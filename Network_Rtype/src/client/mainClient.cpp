#pragma once
#include "SocketTCPWindowsClient.hh"
#include "UserNetworkTCPWindowsClient.hh"
#include "SocketUDPWindows.hh"
#include "UserNetworkUDPWindows.hh"

using namespace Network;

int		main(int ac, char **av)
{
	DataClient	c;
	ISocket			*s = new SocketTCPWindowsClient();
	IUserNetwork	*u = new UserNetworkTCPWindowsClient();
	ISocket			*s2 = new SocketUDPWindows();
	IUserNetwork	*u2 = new UserNetworkUDPWindows();

	std::cout << "Socket TCP client prepared!" << std::endl;
	s->connectIt("127.0.0.1", 4242);
	std::cout << "Connected to server 127.0.0.1 on fd: " << s->getFdSocket() << std::endl;
	u->setIp("127.0.0.1");
	u->setPort(4242);
	u->setFd(s->getFdSocket());
	u = u->readSocket(s);
	std::cout << "READ: " << u->popBufferRead() << std::endl;
	s->closeIt();
	std::cout << "Connection closed" << std::endl;
	delete (s);
	delete (u);
	system("pause");
	s2->bindIt(4343);
	std::cout << "Socket UDP client prepared!" << std::endl;
	u2->setIp("127.0.0.1");
	u2->setPort(4343);
	u2->setFd(s2->getFdSocket());
	u2->readSocket(s);
	std::cout << "READ: " << u2->popBufferRead() << std::endl;
	s2->closeIt();
	std::cout << "Connection closed" << std::endl;
	delete (s2);
	delete (u2);
	return (0);
}