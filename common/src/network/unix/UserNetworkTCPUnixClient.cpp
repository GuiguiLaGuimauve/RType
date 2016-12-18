//
// UserNetworkTCPUnixClient.cpp for UserNetworkTCPUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Sun Dec 18 20:10:32 2016 lecoq
//

#include "UserNetworkTCPUnixClient.hh"

using namespace Network;

UserNetworkTCPUnixClient::UserNetworkTCPUnixClient() {}

UserNetworkTCPUnixClient::~UserNetworkTCPUnixClient() {}

IUserNetwork		*UserNetworkTCPUnixClient::readSocket(ISocket *net)
{
  (void)net;
  char			buff[16384];
  int32_t		nb;

  if ((nb = recv(_fd, buff, 16384, 0)) > 0)
    {
      buff[nb] = 0;
      PacketUnknown pkt((uint8_t *)buff, nb);
      buff_r.push(pkt);
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
  if (send(_fd, to_write.getPacketData(), to_write.getPacketSize(), 0) != to_write.getPacketSize())
    std::cerr << "Error on write" << std::endl;
  buff_w.pop();                                
}
