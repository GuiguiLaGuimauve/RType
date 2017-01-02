//
// SocketUnixClient.cpp for SocketUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 15:52:42 2016 julien dufrene
// Last update Mon Jan  2 04:02:45 2017 julien dufrene
//

#include "SocketTCPUnixClient.hh"
#include <fcntl.h>
#include "Clock.hpp"

using namespace Network;

SocketTCPUnixClient::SocketTCPUnixClient() : SocketTCPUnix()
{
  if (fcntl(_sock, F_SETFL, O_NONBLOCK) == -1)                                                             
    throw ErrorSocket("Error on fcntl(O_NONBLOCK)");               
}

bool			SocketTCPUnixClient::connectIt(const std::string &ip, const uint32_t &port)
{
  Clock			c;
  struct sockaddr_in	s_in;
  socklen_t		len;
  fd_set		write;
  struct timeval	tv;

  s_in.sin_family = AF_INET;
  s_in.sin_addr.s_addr = inet_addr(ip.c_str());
  s_in.sin_port = htons(port);
  tv.tv_sec = 10;
  tv.tv_usec = 0;
  if ((connect(_sock, (struct sockaddr *)&s_in, sizeof (s_in))) == -1)
    {
      if (errno == EINPROGRESS)
      	{
      	  FD_ZERO(&write);
      	  FD_SET(_sock, &write);
      	  if (select(_sock + 1, NULL, &write, NULL, &tv) != -1)
      	    {
	      len = sizeof (s_in);
	      if (getpeername(_sock, (struct sockaddr *)&s_in, &len) == ENOTCONN)
		return (false);
	      else
		{
		  std::cout << "timeout: " << c.getTimeMilli() << "ms" << std::endl;
		  if (c.getTimeMilli() < 100)
		    return (true);
		}
	    }
	}
      return (false);
    }
  return (true);
}

SocketTCPUnixClient::~SocketTCPUnixClient() {}
