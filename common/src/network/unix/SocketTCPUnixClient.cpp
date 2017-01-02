//
// SocketUnixClient.cpp for SocketUnixClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 15:52:42 2016 julien dufrene
// Last update Mon Jan  2 20:16:49 2017 julien dufrene
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

bool			SocketTCPUnixClient::createIt()
{
  struct protoent       *proto;
  int                   reuse;

  _sock = -1;
  reuse = 1;
  proto = getprotobyname("TCP");
  if (!proto)
    {
      std::cerr << "Error on Getprotobyname()" << std::endl;
      return (false);
    }
  if ((_sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    {
      std::cerr << "Error on Socket()" << std::endl;
      return (false);
    }
  if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
    {
      closeIt();
      std::cerr << "Error on Setsockopt()" << std::endl;
      return (false);
    }
  if (fcntl(_sock, F_SETFL, O_NONBLOCK) == -1)                                                             
    {    
      std::cerr << "Error on fcntl(O_NONBLOCK)" << std::endl;
      return (false);
    }
  return (true);
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
  tv.tv_sec = 4;
  tv.tv_usec = 0;
  if ((connect(_sock, (struct sockaddr *)&s_in, sizeof (s_in))) == -1)
    {
      if (errno == EALREADY || errno == EBADF)
	{
	  closeIt();
	  if (createIt() == false)
	    return (false);
	  return (connectIt(ip, port));
	}
      if (errno == EINPROGRESS)
      	{
      	  FD_ZERO(&write);
      	  FD_SET(_sock, &write);
      	  if (select(_sock + 1, NULL, &write, NULL, &tv) != -1)
      	    {
	      len = sizeof (s_in);
	      if (getpeername(_sock, (struct sockaddr *)&s_in, &len) == ENOTCONN)
		{
		  std::cerr << "Error on getpeername()" << std::endl;
		  return (false);
		}
	      else
		if (c.getTimeMilli() < 4000)
		  return (true);
	    }
	}
      std::cerr << "Error on connect: " << errno << std::endl;
      return (false);
    }
  return (true);
}

SocketTCPUnixClient::~SocketTCPUnixClient() {}
