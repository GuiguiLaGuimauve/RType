//
// UserNetworkUDPUnix.cpp for UserNetworkUDPUnix.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Thu Dec 15 16:04:30 2016 julien dufrene
//

#include "UserNetworkUDPUnix.hh"

using namespace Network;

UserNetworkUDPUnix::UserNetworkUDPUnix() : UserNetworkUDP() {}

UserNetworkUDPUnix::~UserNetworkUDPUnix() {}

IUserNetwork		*UserNetworkUDPUnix::readSocket(ISocket *net)
{
  (void)net;
  char                  buff[16384];
  int32_t               nb;
  sockaddr_in		s_in;
  socklen_t		s_inLen = sizeof (s_in);

  s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(_port);
  if ((nb = recvfrom(_fd, buff, 16384, 0, (sockaddr *)&s_in, &s_inLen)) > 0)
    {
      buff[nb] = 0;
      std::string       tmp(buff);
      buff_r.push(tmp);
    }
  if (nb == 0 || nb == -1)
    {
      std::cerr << "Error from recv()" << std::endl;
      closeFd();
    }
  IUserNetwork          *u = new UserNetworkUDPUnix(*this);
  return (u);
}

void                    UserNetworkUDPUnix::writeSocket(ISocket *net)
{
  (void)net;
  std::string           to_write;
  sockaddr_in		s_out;

  s_out.sin_addr.s_addr = inet_addr(_ip.c_str());
  s_out.sin_family = AF_INET;
  s_out.sin_port = htons(_port);
  to_write = buff_w.front();
  if (sendto(_fd, to_write.c_str(), to_write.size(), 0, (sockaddr *)&s_out, sizeof (s_out)) != -1)
    std::cerr << "Error on write" << std::endl;
  else
    buff_w.pop();
}

void			UserNetworkUDPUnix::closeFd()
{
  if (_fd != -1)
    {
      std::cout << "Closing socket " << _fd << std::endl;
      close(_fd);
      setStatus(false);
      _fd = -1;
    }
}
