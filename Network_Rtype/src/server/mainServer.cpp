#pragma once
#include "SocketTCPWindows.hh"
#include "SocketUDPWindows.hh"
#include "UserNetworkTCPWindowsClient.hh"
#include "UserNetworkUDPWindows.hh"

using namespace Network;

int		main(int ac, char **av)
{
	DataClient	c;
	ISocket		*s = new SocketTCPWindows();
	ISocket		*s2 = new SocketUDPWindows();
	IUserNetwork *u = new UserNetworkTCPWindowsClient();
	IUserNetwork *u2 = new UserNetworkUDPWindows();

	s->bindIt(4242);
	s->listenIt(1);
	std::cout << "Socket TCP server prepared on port 4242!" << std::endl;
	s->acceptClient(c);
	std::cout << "Connected to client: " << c.getIp() << " on fd: " << c.getFd() << std::endl;
	u->pushBufferWrite("Welcome on TCP server");
	u->setFd(c.getFd());
	u->writeSocket(s);
	std::cout << "Message send!" << std::endl;
	system("pause");
	s->closeIt();
	std::cout << "Connection closed" << std::endl;
	delete (s);
	delete (u);
	s2->bindIt(4343);
	u2->setIp("127.0.0.1");
	u2->setPort(4343);
	u2->setFd(s2->getFdSocket());
	std::cout << "Socket UDP server prepared on port 4343!" << std::endl;
	u2->pushBufferWrite("Welcome on UDP server!");
	u2->writeSocket(s2);
	std::cout << "Message send!" << std::endl;
	system("pause");
	s2->closeIt();
	std::cout << "Connection closed" << std::endl;
	delete (s2);
	delete (u2);
	return (0);
}