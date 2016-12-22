//
// UserNetworkUDPUnix.cpp for UserNetworkUDPUnix.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Thu Dec 22 17:35:20 2016 julien dufrene
//

#include "UserNetworkUDPUnix.hh"

using namespace Network;

UserNetworkUDPUnix::UserNetworkUDPUnix() : UserNetworkUDP() {}

UserNetworkUDPUnix::~UserNetworkUDPUnix() {}

IUserNetwork		*UserNetworkUDPUnix::readSocket(ISocket *net)
{
  char                  buff[16384];
  int32_t               nb;
  sockaddr_in		s_in;
  socklen_t		s_inLen = sizeof (s_in);

  (void)net;
  // s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
  // s_in.sin_family = AF_INET;
  // s_in.sin_port = htons(_port);
  std::cout << "Trying to recv from: " << _ip << ":" << _port << std::endl;
  errno = 0;
  if ((nb = recvfrom(_fd, buff, 16384, 0, (sockaddr *)&s_in, &s_inLen)) > 0)
    {
      buff[nb] = 0;
      PacketUnknown pkt((uint8_t *)buff, nb);
      buff_r.push(pkt);
      // if (s_in.sin_addr.s_addr != inet_addr(_ip.c_str())
      // 	  && s_in.sin_port != htons(_port))
      // 	  {
      // 	    IUserNetwork	*u = new UserNetworkUDPUnix(*this);
      // 	    u->setIp(inet_ntoa(s_in.sin_addr));
      // 	    u->setFd(_fd);
      // 	    u->setPort(s_in.sin_port);
      // 	    u->setFd(net->getFdSocket());
      // 	    return (u);
      // 	  }
    }
  if (nb == -1 && errno != 11)
    {
      perror("recvfrom");
      std::cerr << "Error from recvfrom(): " << errno << std::endl;
      closeFd();
    }
  return (this);
}

void                    UserNetworkUDPUnix::writeSocket(ISocket *net)
{
  (void)net;
  PacketUnknown         to_write;
  sockaddr_in		s_out;

  //  s_out.sin_addr.s_addr = inet_addr(_ip.c_str());
  s_out.sin_addr.s_addr = inet_addr("127.0.0.1");
  s_out.sin_family = AF_INET;
  // s_out.sin_port = htons(_port);
  s_out.sin_port = htons(4243);
  to_write = buff_w.pop();
  std::cout << "Trying to send to: " << _ip << ":" << _port << std::endl;
  errno = 0;
  if (sendto(_fd, to_write.getPacketData(), to_write.getPacketSize(), 0, (sockaddr *)&s_out, sizeof (s_out)) == -1)
    {
      perror("sendto");
      std::cerr << "Error on sendto(): " << errno << std::endl;
    }
}

void			UserNetworkUDPUnix::closeFd()
{
  if (_fd != -1)
    {
      std::cout << "Closing socket " << _fd << std::endl;
      close(_fd);
      setStatus(false);
      _fd = -1;
    }
}
