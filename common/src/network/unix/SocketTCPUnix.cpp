//
// socket.cpp for socket.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:10:10 2016 julien dufrene
// Last update Thu Dec 15 16:36:04 2016 julien dufrene
//

#include "SocketTCPUnix.hh"

using namespace Network;

SocketTCPUnix::SocketTCPUnix()
{
  struct protoent	*proto;
  int			reuse;

  _sock = -1;
  reuse = 1;
  proto = getprotobyname("TCP");
  if (!proto)
    throw ErrorSocket("Error on Getprotobyname()");
  if ((_sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    throw ErrorSocket("Error on Socket()");
  if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
    {
      closeIt();
      throw ErrorSocket("Error on Setsockopt()");
    }
}

int32_t			SocketTCPUnix::getFdSocket() const
{
  return (_sock);
}

bool			SocketTCPUnix::bindIt(const uint32_t &port)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = htonl(INADDR_ANY);
  if ((bind(_sock, (const struct sockaddr *)&s_in, sizeof (s_in))) == -1)
    {
      closeIt();
      return (false);
    }
  return (true);
}

bool			SocketTCPUnix::listenIt(const uint32_t &nbClient)
{
  if (listen(_sock, nbClient) == -1)
    {
      std::cerr << "Error on Listen()" << std::endl;
      closeIt();
      return (false);
    }
  return (true);
}

bool			SocketTCPUnix::acceptClient(DataClient &data)
{
  struct sockaddr_in	s_client;
  socklen_t		s_len;
  uint32_t		fd;

  if ((fd = accept(_sock, (struct sockaddr *)&s_client, &s_len)) == (unsigned int)-1)
    {
      std::cerr << "Error on Accept()" << std::endl;
      closeIt();
      return (false);
    }
  data.setFd(fd);
  std::string tmp(inet_ntoa(s_client.sin_addr));
  data.setIp(tmp);
  return (true);
}

bool		SocketTCPUnix::closeIt()
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

SocketTCPUnix::~SocketTCPUnix() {}
