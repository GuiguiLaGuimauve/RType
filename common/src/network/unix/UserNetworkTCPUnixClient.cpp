//
// UserNetworkTCPUnixClient.cpp for UserNetworkTCPUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Sat Dec 31 16:02:40 2016 Lecoq Maxime
//

#include "UserNetworkTCPUnixClient.hh"

using namespace Network;

UserNetworkTCPUnixClient::UserNetworkTCPUnixClient() {}

UserNetworkTCPUnixClient::~UserNetworkTCPUnixClient() {}

IUserNetwork		*UserNetworkTCPUnixClient::readSocket(ISocket *net)
{
  (void)net;
  char			buff[16384];
  uint8_t		*s;
  int32_t		nb;

  if ((nb = recv(_fd, buff, 16384, 0)) > 0)
    {
      s = new uint8_t[nb + 1];
      int32_t i;
      i = 0;
      while (i < nb)
	{
	  s[i] = buff[i];
	  i++;
	}
      s[nb] = 0;
      cutRead((uint8_t *)s, nb);
      //PacketUnknown pkt((uint8_t *)buff, nb);
      //buff_r.push(pkt);
    }
  if (nb == 0 || nb == -1)
    {
      std::cerr << "Error from recv()" << std::endl;
      closeFd();
    }
  IUserNetwork		*u = new UserNetworkTCPUnixClient(*this);
  return (u);
}

void			UserNetworkTCPUnixClient::writeSocket(ISocket *net)
{
  (void)net;
  PacketUnknown         to_write;

  to_write = buff_w.front();
  if (to_write.packetIsValid() == false)
    return;
  if (send(_fd, to_write.getPacketData(), to_write.getPacketSize(), 0) != to_write.getPacketSize())
    std::cerr << "Error on write" << std::endl;
  else
    buff_w.pop();                                
}
