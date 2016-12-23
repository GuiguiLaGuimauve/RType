#include "SocketTCPWindows.hh"

using namespace Network;

SocketTCPWindows::SocketTCPWindows()
{
	WSADATA			wsadata;
	bool			reuse = true;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		throw ErrorSocket("error on WSAStartup(): " + WSAGetLastError());
	_sock = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (_sock == INVALID_SOCKET)
		throw ErrorSocket("Error on WSASocket: " + WSAGetLastError());
	if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(bool)) == SOCKET_ERROR)
	{
		closeIt();
		throw ErrorSocket("Error on Setsockopt: " + WSAGetLastError());
	}
}

const std::string		SocketTCPWindows::getIpInfo() const
{
  struct sockaddr_in        s_in;
  socklen_t                 len;

  len = sizeof(struct sockaddr_in);
  if (getsockname(_sock, (struct sockaddr*)&s_in, &len) < 0)
    {
      std::cerr << "Error on getsockname()" << std::endl;
      return ("");
    }
  return (inet_ntoa(s_in.sin_addr));
}


bool				SocketTCPWindows::bindIt(const uint32_t &port)
{
	sockaddr_in			s_in;

	s_in.sin_addr.s_addr = INADDR_ANY;
	s_in.sin_family = AF_INET;
	if (WSAHtons(_sock, port, &(s_in.sin_port)) == SOCKET_ERROR)
	{
		std::cerr << "Error on WSAHtons(): " << WSAGetLastError() << std::endl;
		closeIt();
		return (false);
	}
	if (bind(_sock, (SOCKADDR *)&s_in, sizeof(s_in)) == SOCKET_ERROR)
	  {
		  std::cerr << "Error on Bind: " << WSAGetLastError() << std::endl;
		  closeIt();
		  return (false);
	  }
	return (true);
}

bool			SocketTCPWindows::listenIt(const uint32_t &nbClient)
{
	if (listen(_sock, nbClient) == -1)
	{
		std::cerr << "Error on Listen: " << WSAGetLastError() << std::endl;
		closeIt();
		return (false);
	}
	return (true);
}

bool			SocketTCPWindows::acceptClient(DataClient &data)
{
	sockaddr_in		saClient;
	SOCKET			fd;
	int32_t			iClientSize;
	
	iClientSize = sizeof(saClient);
	fd = WSAAccept(_sock, (SOCKADDR *)&saClient, &iClientSize, NULL, NULL);
	if (fd == INVALID_SOCKET)
	{
		std::cerr << "Error on WSAAccept: " << WSAGetLastError() << std::endl;
		return (false);
	}
	data.setFd(static_cast<int32_t>(fd));
	std::string ip = inet_ntoa(saClient.sin_addr);
	std::cout << "Accept client ip:" << ip << std::endl;
	data.setIp(ip);
	return (true);
}

int32_t		SocketTCPWindows::getFdSocket() const
{
	return (static_cast<int32_t>(_sock));
} 

bool			SocketTCPWindows::closeIt()
{
	if (_sock != -1)
		if (closesocket(_sock) == SOCKET_ERROR)
		{
			std::cerr << "Error on closeSocket(): "<< WSAGetLastError() << std::endl;
			WSACleanup();
			return (false);
		}
  _sock = -1;
  WSACleanup();
  return (true);
}

SocketTCPWindows::~SocketTCPWindows() {}
