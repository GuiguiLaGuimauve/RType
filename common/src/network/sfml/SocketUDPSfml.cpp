//
// socket.cpp for socket.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:10:10 2016 julien dufrene
// Last update Fri Dec 16 16:23:42 2016 julien dufrene
//

#include "SocketUDPUnix.hh"

using namespace Network;

SocketUDPUnix::SocketUDPUnix()
{
  struct protoent	*proto;

  _sock = -1;
  proto = getprotobyname("UDP");
  if (!proto)
    throw ErrorSocket("Error on Getprotobyname()");
  if ((_sock = socket(AF_INET, SOCK_DGRAM, proto->p_proto)) == -1)
    throw ErrorSocket("Error on Socket()");
}

int32_t			SocketUDPUnix::getFdSocket() const
{
  return (_sock);
}

bool			SocketUDPUnix::bindIt(const uint32_t &port)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = htonl(INADDR_ANY);
  if ((bind(_sock, (const struct sockaddr *)&s_in, sizeof (s_in))) == -1)
    {
      std::cerr << "Error on Bind()" << std::endl;
      closeIt();
      return (false);
    }
  return (true);
}

bool		SocketUDPUnix::closeIt()
{
  if ((int32_t)_sock != -1)
    if (close(_sock) == -1)
      {
	std::cerr << "Error on close()" << std::endl;
	return (false);
      }
  _sock = -1;
  return (true);
}

SocketUDPUnix::~SocketUDPUnix() {}