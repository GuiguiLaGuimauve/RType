//
// UserNetworkTCPUnixServer.cpp for UserNetworkTCPUnixServer.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Mon Jan  2 20:20:59 2017 julien dufrene
//

#include "UserNetworkTCPUnixServer.hh"

using namespace Network;

UserNetworkTCPUnixServer::UserNetworkTCPUnixServer() {}

UserNetworkTCPUnixServer::~UserNetworkTCPUnixServer() {}

IUserNetwork            *UserNetworkTCPUnixServer::readSocket(ISocket *net)
{
  IUserNetwork          *u = new UserNetworkTCPUnixClient();
  DataClient            data;

  if (net->acceptClient(data) == false)
    return (NULL);
  u->setFd(data.getFd());
  u->setIp(data.getIp());
  u->setStatus(true);
  return (u);
}

void                    UserNetworkTCPUnixServer::writeSocket(ISocket *net)
{
  std::cerr << "[TCP ERROR] Write in UserNetworkTCPUnixServer" << std::endl;
  (void)net;
}

