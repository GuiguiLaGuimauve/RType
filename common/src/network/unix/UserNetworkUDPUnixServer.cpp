//
// UserNetworkUDPUnixServer.cpp for UserNetworkUDPUnixServer.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Fri Dec 23 02:52:33 2016 julien dufrene
//

#include "UserNetworkUDPUnixServer.hh"

using namespace Network;

UserNetworkUDPUnixServer::UserNetworkUDPUnixServer() : UserNetworkUDPUnix() {}

UserNetworkUDPUnixServer::~UserNetworkUDPUnixServer() {}

IUserNetwork		*UserNetworkUDPUnixServer::readSocket(ISocket *net)
{
  char                  buff[16384];
  int32_t               nb;
  sockaddr_in		s_in;
  socklen_t		s_inLen = sizeof (s_in);

  (void)net;
  std::cout << "Trying to recv from: " << _ip << ":" << _port << std::endl;
  errno = 0;
  if ((nb = recvfrom(_fd, buff, 16384, 0, (sockaddr *)&s_in, &s_inLen)) > 0)
    {
      buff[nb] = 0;
      PacketUnknown pkt((uint8_t *)buff, nb);
      if (s_in.sin_addr.s_addr != inet_addr(_ip.c_str())
      	  || s_in.sin_port != htons(_port))
      	  {
      	    IUserNetwork	*u = new UserNetworkUDPUnixServer(*this);
      	    u->setIp(inet_ntoa(s_in.sin_addr));
      	    u->setFd(_fd);
      	    u->setPort(ntohs(s_in.sin_port));
      	    u->setFd(net->getFdSocket());
	    u->pushBufferRead(pkt);
	    u->setStatus(true);
	    std::cout << "Sender: " << u->getIp() << ":" << u->getPort() << std::endl;
      	    return (u);
      	  }
      else
	buff_r.push(pkt);
      // _ip = inet_ntoa(s_in.sin_addr);
      std::cout << "Sender: " << inet_ntoa(s_in.sin_addr) << ":" << ntohs(s_in.sin_port) << std::endl;
    }
  if (nb == -1 && errno != 11)
    {
      perror("recvfrom");
      std::cerr << "Error from recvfrom(): " << errno << std::endl;
      closeFd();
    }
  return (this);
}
