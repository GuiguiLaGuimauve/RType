//
// UserNetworkTCPUnixServer.cpp for UserNetworkTCPUnixServer.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Wed Dec 21 17:15:29 2016 julien dufrene
//

#include "UserNetworkTCPUnixServer.hh"

using namespace Network;

UserNetworkTCPUnixServer::UserNetworkTCPUnixServer() {}

UserNetworkTCPUnixServer::~UserNetworkTCPUnixServer() {}

IUserNetwork            *UserNetworkTCPUnixServer::readSocket(ISocket *net)
{
  IUserNetwork          *u = new UserNetworkTCPUnixClient();
  DataClient            data;

  std::cout << "Accepting client..." << std::endl;
  if (net->acceptClient(data) == false)
    return (NULL);
  u->setFd(data.getFd());
  u->setIp(data.getIp());
  std::cout << "New client with fd: " << u->getFd() << " and ip: " << u->getIp() << std::endl;
  u->setStatus(true);
  return (u);
}

void                    UserNetworkTCPUnixServer::writeSocket(ISocket *net)
{
  std::cerr << "ERROR: Write in UserNetworkTCPUnixServer" << std::endl;
  (void)net;
}

