#include "SocketUDPWindows.hh"

using namespace Network;

SocketUDPWindows::SocketUDPWindows()
{
	WSADATA				wsadata;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		std::cerr << "Error on WSAStartUp: " << WSAGetLastError() << std::endl;
	//throw ErrorSocket("error on WSAStartup()");
	_sock = WSASocketW(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, 0);
	if (_sock == INVALID_SOCKET)
		std::cerr << "Error on WSASocket: " << WSAGetLastError() << std::endl;
	//throw ErrorSocket("error on WSASocket()");
	std::cout << "Socket UDP ok: " << _sock << std::endl;
	bool	reuse = true;
	if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(bool)) == SOCKET_ERROR)
		std::cerr << "Error on Setsockopt: " << WSAGetLastError() << std::endl;
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
