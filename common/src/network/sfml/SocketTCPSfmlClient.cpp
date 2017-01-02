//
// SocketSfmlClient.cpp for SocketSfmlClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 15:52:42 2016 julien dufrene
// Last update Sat Dec 24 16:48:19 2016 julien dufrene
//

#include "SocketTCPSfmlClient.hh"

using namespace Network;

SocketTCPSfmlClient::SocketTCPSfmlClient() : SocketTCPSfml() {}

bool			SocketTCPSfmlClient::connectIt(const std::string &ip, const uint32_t &port)
{
  if (_sock.connect(ip.c_str(), port) != sf::Socket::Done)
    {
      std::cerr << "Error on Connect()" << std::endl;
      closeIt();
      return (false);
    }
  std::cout << "Connected!" << std::endl;
  return (true);
}

SocketTCPSfmlClient::~SocketTCPSfmlClient() {}
