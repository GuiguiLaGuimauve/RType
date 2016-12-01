#pragma once
#include "SocketTCPWindowsClient.hh"

using namespace Network;

int		main(int ac, char **av)
{
	DataClient	c;
	ISocket		*s = new SocketTCPWindowsClient();
	std::cout << "Socket TCP client prepared!" << std::endl;
	s->connectIt("127.0.0.1", 4242);
	std::cout << "Connected to server 127.0.0.1 on fd: " << c.getFd() << std::endl;
	system("pause");
	return (0);
}