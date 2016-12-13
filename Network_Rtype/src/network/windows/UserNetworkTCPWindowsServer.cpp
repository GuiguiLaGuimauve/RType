//
// UserNetworkTCPWindowsServer.cpp for UserNetworkTCPWindowsServer.cpp in /home/dufren_b/teck3/rendu/CPP/RType
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Dec 02 15:02:22 2016 julien dufrene
// Last update Fri Dec 03 01:33:55 2016 julien dufrene
//

#include "UserNetworkTCPWindowsServer.hh"

using namespace Network;

UserNetworkTCPWindowsServer::UserNetworkTCPWindowsServer() : UserNetworkTCPWindows() {}

UserNetworkTCPWindowsServer::~UserNetworkTCPWindowsServer() {}

IUserNetwork		*UserNetworkTCPWindowsServer::readSocket(ISocket *net)
{
#ifdef _WIN32
	IUserNetwork		*u = new UserNetworkTCPWindowsClient();
#else
	IUserNetwork		*u = new UserNetworkTCPUnixClient();
#endif
  DataClient		data;

  std::cout << "Accepting client..." << std::endl;
  if (net->acceptClient(data) == false)
    return (NULL);
  u->setFd(data.getFd());
  u->setIp(data.getIp());
  std::cout << "New client with fd: " << u->getFd() << std::endl;
  return (u);
}

void			UserNetworkTCPWindowsServer::writeSocket(ISocket *net)
{
	std::cerr << "ERROR: Write in UserNetworkTCPWindowsServer" << std::endl;
  (void)net;
}

