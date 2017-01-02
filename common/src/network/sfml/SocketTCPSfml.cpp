//
// socket.cpp for socket.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:10:10 2016 julien dufrene
// Last update Sat Dec 24 17:06:58 2016 julien dufrene
//

#include "SocketTCPSfml.hh"

using namespace Network;

SocketTCPSfml::SocketTCPSfml()
{
  // bool		reuse;

  // reuse = true;
  // if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
  //   {
  //     closeIt();
  //     throw ErrorSocket("[SFML] Error on Setsockopt()");
  //   }
}

int32_t			SocketTCPSfml::getFdSocket() const
{
  std::cout << "[SFML] get fd socket on SFML Socket" << std::endl;
  return (0);
}

bool			SocketTCPSfml::bindIt(const uint32_t &port)
{
  // if (_sock.bind(port) != sf::Socket::Done)
  //   {
  //     std::cerr << "[SFML]Error on Bind()" << std::endl;
  //     closeIt();
  //     return (false);
  //   }
  _port = port;
  return (true);
}

bool			SocketTCPSfml::listenIt(const uint32_t &nbClient)
{
  if (_listen.listen(_port) != sf::Socket::Done)
    {
      std::cerr << "[SFML]Error on listen()" << std::endl;
    }
  (void)nbClient;
  return (true);
}

bool			SocketTCPSfml::acceptClient(DataClient &data)
{
  sf::TcpSocket		client;

  if (_listen.accept(client) != sf::Socket::Done)
    {
      std::cerr << "[SFML]Error on Accept()" << std::endl;
      closeIt();
      return (false);      
    }
  data.setFd(0);
  std::string tmp(client.getRemoteAddress().toString());
  data.setIp(tmp);
  data.setSfmlSock(client);
  return (true);
}

bool		SocketTCPSfml::closeIt()
{
  return (true);
}

SocketTCPSfml::~SocketTCPSfml() {}
