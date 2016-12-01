#pragma once
#include "SocketTCPWindows.hh"

using namespace Network;

int		main(int ac, char **av)
{
	DataClient	c;
	ISocket		*s = new SocketTCPWindows();
	s->bindIt(4242);
	s->listenIt(1);
	std::cout << "Socket TCP server prepared on port 4242!" << std::endl;
	s->acceptClient(c);
	std::cout << "Connected to client: " << c.getIp() << " on fd: " << c.getFd() << std::endl;
	system("pause");
	return (0);
}