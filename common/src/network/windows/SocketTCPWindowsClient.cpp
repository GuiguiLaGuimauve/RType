//
// SocketWindowsClient.cpp for SocketWindowsClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 15:52:42 2016 julien dufrene
// Last update Mon Jan  2 04:20:10 2017 julien dufrene
//

#include "SocketTCPWindowsClient.hh"

using namespace Network;

SocketTCPWindowsClient::SocketTCPWindowsClient() : SocketTCPWindows()
{
  int		ret;
  u_long	iMode;

  iMode = 1;
  if ((ret = ioctlsocket(_sock, FIONBIO, &iMode)) != NO_ERROR)
    throw ErrorSocket("Error on ioctlsocket(): " + ret);
}

bool			SocketTCPWindowsClient::createIt()
{
	WSADATA			wsadata;
	bool			reuse = true;
	int				ret;
	u_long			iMode;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		std::cerr << "Error on WSAStartup(): " + WSAGetLastError() << std::endl;
		return (false);
	}
	_sock = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (_sock == INVALID_SOCKET)
	{
		std::cerr << "Error on WSASocket: " + WSAGetLastError() << std::endl;
		return (false);
	}
	if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(bool)) == SOCKET_ERROR)
	{
		closeIt();
		std::cerr << "Error on Setsockopt: " + WSAGetLastError() << std::endl;
		return (false);
	}
	iMode = 1;
	if ((ret = ioctlsocket(_sock, FIONBIO, &iMode)) != NO_ERROR)
	{
		std::cerr << "Error on ioctlsocket(): " + ret << std::endl;
		return (false);
	}
	return (true);
}

bool			SocketTCPWindowsClient::connectIt(const std::string &ip, const uint32_t &port)
{
	struct sockaddr_in	s_in;
	FD_SET				write;
	struct timeval		tv;
	DWORD				len;
	Clock				c;

	s_in.sin_family = AF_INET;
	tv.tv_sec = 4;
	tv.tv_usec = 0;
	if (inet_pton(AF_INET, ip.c_str(), &s_in.sin_addr.s_addr) <= 0)
	{
		std::cerr << "Error on inet_pton(): " << WSAGetLastError() << std::endl;
		return (false);
	}
	if (WSAHtons(_sock, port, &s_in.sin_port) == SOCKET_ERROR)
	{
		std::cerr << "Error on WSAHtons(): " << WSAGetLastError() << std::endl;
		return (false);
	}
	if (WSAConnect(_sock, (struct sockaddr *)&s_in, sizeof(s_in), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAEALREADY)
		{
			std::cout << "Reseting connection!" << std::endl;
			closeIt();
			if (createIt() == false)
				return (false);
			return (connectIt(ip, port));
		}
		if (WSAGetLastError() == WSAEINPROGRESS || WSAGetLastError() == WSAEWOULDBLOCK)
		{
			std::cout << "Connecting..." << WSAGetLastError() << std::endl;
			FD_ZERO(&write);
			FD_SET(_sock, &write);
			if (select((int)_sock + 1, NULL, &write, NULL, &tv) != -1)
			{
				len = sizeof (s_in);
				if (getpeername(_sock, (struct sockaddr *)&s_in, (int *)&len) == WSAENOTCONN)
				{
					std::cout << "Error on getpeername(): " << WSAGetLastError() << std::endl;
					return (false);
				}
				else
				{
					std::cout << "timeout: " << c.getTimeMilli() << "ms" << std::endl;
					if (c.getTimeMilli() < 4000)
						return (true);
				}
			}
			else
				std::cerr << "Error on select: " << WSAGetLastError() << std::endl;
		}
		std::cout << "Error on WSAConnect(): " << WSAGetLastError() << std::endl;
		return (false);
	}
	return (true);
}

SocketTCPWindowsClient::~SocketTCPWindowsClient() {}
