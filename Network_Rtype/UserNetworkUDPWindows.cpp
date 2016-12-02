//
// UserNetworkUDPWindows.cpp for UserNetworkUDPWindows.cpp in /home/dufren_b/teck3/rendu/CPP/RType
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Dec 02 15:02:22 2016 julien dufrene
// Last update Fri Dec 03 01:33:55 2016 julien dufrene
//

#include "UserNetworkUDPWindows.hh"

using namespace Network;

UserNetworkUDPWindows::UserNetworkUDPWindows() : UserNetworkUDP() {}

UserNetworkUDPWindows::~UserNetworkUDPWindows() {}

IUserNetwork		*UserNetworkUDPWindows::readSocket(ISocket *net)
{
	(void)net;
	// recv from
	IUserNetwork		*u = new UserNetworkUDPWindows(*this);
	return (u);
}

void			UserNetworkUDPWindows::writeSocket(ISocket *net)
{
	(void)net;
	//send to
}

void			UserNetworkUDPWindows::closeFd()
{
	if (_fd != -1)
	{
		std::cout << "Closing socket " << _fd << std::endl;
		closesocket(_fd);
	}
}
