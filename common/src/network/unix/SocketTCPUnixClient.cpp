//
// SocketUnixClient.cpp for SocketUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 15:52:42 2016 julien dufrene
// Last update Fri Dec 23 07:23:48 2016 julien dufrene
//

#include "SocketTCPUnixClient.hh"

using namespace Network;

SocketTCPUnixClient::SocketTCPUnixClient() : SocketTCPUnix() {}

bool			SocketTCPUnixClient::connectIt(const std::string &ip, const uint32_t &port)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_addr.s_addr = inet_addr(ip.c_str());
  s_in.sin_port = htons(port);
  if ((connect(_sock, (struct sockaddr *)&s_in, sizeof (s_in))) == -1)
    return (false);
  return (true);
}

SocketTCPUnixClient::~SocketTCPUnixClient() {}
