//
// UserNetworkUDPUnixServer.cpp for UserNetworkUDPUnixServer.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Tue Dec 27 23:43:40 2016 root
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
  //std::cout << "Trying to recv from" << std::endl;
  errno = 0;
  if ((nb = recvfrom(_fd, buff, 16384, 0, (sockaddr *)&s_in, &s_inLen)) > 0)
    {
      buff[nb] = 0;
      PacketUnknown pkt((uint8_t *)buff, nb);
      setIp(inet_ntoa(s_in.sin_addr));
      setPort(ntohs(s_in.sin_port));
      setFd(net->getFdSocket());
      pushBufferRead(pkt);
      setStatus(true);
      //std::cout << "Modif Sender: " << getIp() << ":" << getPort() << std::endl;
    }
  if (nb == -1 && errno != 11)
    {
      perror("recvfrom");
      std::cerr << "Error from recvfrom(): " << errno << std::endl;
      closeFd();
    }
  return (this);
}
