//
// SocketUDPWindows.cpp for SocketUDPWindows.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/windows
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:13:57 2016 julien dufrene
// Last update Thu Dec 15 16:27:56 2016 julien dufrene
//

#include "SocketUDPWindows.hh"

using namespace Network;

SocketUDPWindows::SocketUDPWindows()
{
	WSADATA				wsadata;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		throw ErrorSocket("error on WSAStartup(): " + WSAGetLastError());
	_sock = WSASocketW(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (_sock == INVALID_SOCKET)
		throw ErrorSocket("Error on WSASocket: " + WSAGetLastError());
}

bool				SocketUDPWindows::bindIt(const uint32_t &port)
{
	sockaddr_in			s_in;

	s_in.sin_addr.s_addr = htonl(INADDR_ANY);
	s_in.sin_family = AF_INET;
	WSAHtons(_sock, port, &(s_in.sin_port));
	if (bind(_sock, (SOCKADDR *)&s_in, sizeof(s_in)) == SOCKET_ERROR)
	{
		std::cerr << "Error on Bind: " << WSAGetLastError() << std::endl;
		closeIt();
		return (false);
	}
	return (true);
}

int32_t		SocketUDPWindows::getFdSocket() const
{
	return (static_cast<int32_t>(_sock));
}

bool			SocketUDPWindows::closeIt()
{
	if (_sock != -1)
		if (closesocket(_sock) == SOCKET_ERROR)
		{
			std::cerr << "Error on closeSocket(): " << WSAGetLastError() << std::endl;
			WSACleanup();
			return (false);
		}
	_sock = -1;
	WSACleanup();
	return (true);
}

SocketUDPWindows::~SocketUDPWindows() {}