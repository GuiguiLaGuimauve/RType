//
// UserNetworkTCPSfmlServer.cpp for UserNetworkTCPSfmlServer.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Sat Dec 24 16:45:10 2016 julien dufrene
//

#include "UserNetworkTCPSfmlServer.hh"

using namespace Network;

UserNetworkTCPSfmlServer::UserNetworkTCPSfmlServer() {}

UserNetworkTCPSfmlServer::~UserNetworkTCPSfmlServer() {}

IUserNetwork            *UserNetworkTCPSfmlServer::readSocket(ISocket *net)
{
  IUserNetwork          *u = new UserNetworkTCPSfmlClient();
  DataClient            data;

  std::cout << "Accepting client..." << std::endl;
  if (net->acceptClient(data) == false)
    return (NULL);
  u->setFd(data.getFd());
  u->setIp(data.getIp());
  std::cout << "New client ip: " << u->getIp() << std::endl;
  u->setStatus(true);
  return (u);
}

void                    UserNetworkTCPSfmlServer::writeSocket(ISocket *net)
{
  std::cerr << "ERROR: Write in UserNetworkTCPSfmlServer" << std::endl;
  (void)net;
}

