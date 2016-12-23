//
// UserNetworkUDPUnixClient.cpp for UserNetworkUDPUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Fri Dec 23 07:32:28 2016 julien dufrene
//

#include "UserNetworkUDPUnixClient.hh"

using namespace Network;

UserNetworkUDPUnixClient::UserNetworkUDPUnixClient() : UserNetworkUDPUnix() {}

UserNetworkUDPUnixClient::~UserNetworkUDPUnixClient() {}

IUserNetwork		*UserNetworkUDPUnixClient::readSocket(ISocket *net)
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
      buff_r.push(pkt);
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
