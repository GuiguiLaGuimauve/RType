//
// UserNetworkUDPUnix.cpp for UserNetworkUDPUnix.cpp in /home/dufren_b/teck3/rendu/CPP/RType
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Dec 02 15:02:22 2016 julien dufrene
// Last update Tue Dec 27 23:46:19 2016 root
//

#include "UserNetworkUDPUnix.hh"

using namespace Network;

UserNetworkUDPUnix::UserNetworkUDPUnix() : UserNetworkUDP() {}

UserNetworkUDPUnix::~UserNetworkUDPUnix() {}

void				UserNetworkUDPUnix::writeSocket(ISocket *net)
{
		(void)net;
      PacketUnknown         to_write;
      sockaddr_in           s_out;

      s_out.sin_addr.s_addr = inet_addr(_ip.c_str());
      s_out.sin_family = AF_INET;
      s_out.sin_port = htons(_port);
      to_write = buff_w.pop();
      //std::cout << "Trying to send to: " << _ip << ":" << _port << std::endl;
      errno = 0;
      if (sendto(_fd, to_write.getPacketData(), to_write.getPacketSize(), 0, (sockaddr *)&s_out, sizeof (s_out)) == -1)
        {
		perror("sendto");
		std::cerr << "Error on sendto(): " << errno << std::endl;
		}
    };

void			UserNetworkUDPUnix::closeFd()
{
      if (getStatus() == true)
	{
	  std::cout << "Closing socket " << _fd << std::endl;
	  close(_fd);
	  setStatus(false);
	  _fd = -1;
	}
}
