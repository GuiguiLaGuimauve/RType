//
// socket.cpp for socket.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:10:10 2016 julien dufrene
// Last update Thu Dec 22 11:23:20 2016 julien dufrene
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
  if (fcntl(_sock, F_SETFL, O_NONBLOCK) == -1)
    throw ErrorSocket("Error on fcntl(O_NONBLOCK)");
}

const std::string   SocketUDPUnix::getIpInfo() const
{
  struct sockaddr_in        s_in;
  socklen_t                 len;

  len = sizeof(struct sockaddr_in);
  if (getsockname(_sock, (struct sockaddr*)&s_in, &len) < 0)
    {
      std::cerr << "Error on getsockname()" << std::endl;
      return ("");
    }
  return (inet_ntoa(s_in.sin_addr));
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
