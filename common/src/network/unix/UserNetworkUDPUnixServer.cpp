//
// UserNetworkUDPUnixServer.cpp for UserNetworkUDPUnixServer.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Fri Dec 30 23:28:18 2016 Lecoq Maxime
//

#include "UserNetworkUDPUnixServer.hh"

using namespace Network;

UserNetworkUDPUnixServer::UserNetworkUDPUnixServer() : UserNetworkUDPUnix() {}

UserNetworkUDPUnixServer::~UserNetworkUDPUnixServer() {}

IUserNetwork		*UserNetworkUDPUnixServer::readSocket(ISocket *net)
{
  char                  buff[16384];
  uint8_t		*s;
  int32_t               nb;
  sockaddr_in		s_in;
  socklen_t		s_inLen = sizeof (s_in);

  std::cout << "whaaat 1" << std::endl;
  (void)net;
  //std::cout << "Trying to recv from" << std::endl;
  errno = 0;
  if ((nb = recvfrom(_fd, buff, 16384, 0, (sockaddr *)&s_in, &s_inLen)) > 0)
    {
      std::cout << "whaaat345" << std::endl;
      s = new uint8_t[nb + 1];
      int32_t i = 0;
      while (i < nb)
	{
	  s[i] = buff[i];
	  i++;
	}
      s[nb] = 0;
      std::cout << "whaaat2" << std::endl;
      PacketUnknown pkt((uint8_t *)s, nb);
      setIp(inet_ntoa(s_in.sin_addr));
      std::cout << "whaaat3" << std::endl;
      setPort(ntohs(s_in.sin_port));
      std::cout << "whaaat4" << std::endl;
      setFd(net->getFdSocket());
      std::cout << "whaaat5" << std::endl;
      pushBufferRead(pkt);
      std::cout << "whaaat6" << std::endl;
      setStatus(true);
      //std::cout << "Modif Sender: " << getIp() << ":" << getPort() << std::endl;
    }
  std::cout << "whaaat" << std::endl;
  if (nb == -1 && errno != 11)
    {
      std::cout << "pppppppppppppppppppppppppppp" << std::endl;
      perror("recvfrom");
      std::cerr << "Error from recvfrom(): " << errno << std::endl;
      closeFd();
    }
  return (this);
}
