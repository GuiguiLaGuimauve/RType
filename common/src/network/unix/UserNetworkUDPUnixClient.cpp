//
// UserNetworkUDPUnixClient.cpp for UserNetworkUDPUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Mon Jan  2 10:34:43 2017 julien dufrene
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
  uint8_t		*s;
  
  (void)net;
  errno = 0;
  if ((nb = recvfrom(_fd, buff, 16384, 0, (sockaddr *)&s_in, &s_inLen)) > 0)
    {
      s = new uint8_t[nb + 1];
      int32_t i = 0;
      while (i < nb)
	{
	  s[i] = buff[i];
	  i++;
	}
      s[nb] = 0;
      PacketUnknown pkt((uint8_t *)s, nb);
      buff_r.push(pkt);
    }
  if (nb == -1 && errno != 11)
    {
      perror("recvfrom");
      std::cerr << "Error from recvfrom(): " << errno << std::endl;
      closeFd();
    }
  return (this);
}
