#include "SocketTCPWindows.hh"

using namespace Network;

SocketTCPWindows::SocketTCPWindows()
{
	WSADATA				wsadata;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		//throw ErrorSocket("error on WSAStartup()");
		std::cerr << "Error on WSAStartUp: " << WSAGetLastError() << std::endl;
	_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
	if (_sock == INVALID_SOCKET)
		std::cerr << "Error on WSAStartUp: " << WSAGetLastError() << std::endl;
	//throw ErrorSocket("error on WSASocket()");
}

bool				SocketTCPWindows::bindIt(const uint32_t &port)
{
	sockaddr_in			s_in;

	s_in.sin_addr.s_addr = INADDR_ANY;
	s_in.sin_family = AF_INET;
	WSAHtons(_sock, port, &(s_in.sin_port));
	if (bind(_sock, (SOCKADDR *)&s_in, sizeof(s_in)) == SOCKET_ERROR)
	  {
		  std::cerr << "Error on Bind" << std::endl;
		  closesocket(_sock);
	    WSACleanup();
	    return (false);
	  }
	return (true);
}

bool			SocketTCPWindows::listenIt(const uint32_t &nbClient)
{
	if (listen(_sock, nbClient) == -1)
	{
		std::cerr << "Error on Listen" << WSAGetLastError() << std::endl;
		closesocket(_sock);
		WSACleanup();
		return (false);
	}
	return (true);
}

bool			SocketTCPWindows::acceptClient(DataClient &data)
{
	sockaddr_in		saClient;
	SOCKET			fd;
	int32_t			iClientSize;
	DWORD			len;
	LPWSTR			tmp_ip = new (wchar_t);
	
	iClientSize = sizeof(saClient);
	fd = WSAAccept(_sock, (SOCKADDR *)&saClient, &iClientSize, NULL, NULL);
	if (fd == INVALID_SOCKET)
	{
		std::cerr << "Error on WSAAccept: " << WSAGetLastError() << std::endl;
		return (false);
	}
	data.setFd(static_cast<int32_t>(fd));
	len = 46;
	if (WSAAddressToStringW((SOCKADDR *)&saClient, iClientSize, NULL, tmp_ip, &len) == SOCKET_ERROR)
	{
		std::cerr << "Error on WSAAddressToString: " << WSAGetLastError() << std::endl;
		return (false);
	}
	std::wstring		wtmp_ip(tmp_ip);
	std::string			ip;
	char *ctmp_ip = new char[wtmp_ip.length() + 1];
	ctmp_ip[wtmp_ip.size()] = '\0';
	WideCharToMultiByte(CP_ACP, 0, wtmp_ip.c_str(), -1, ctmp_ip, (int)wtmp_ip.length(), NULL, NULL);
	ip = ctmp_ip;
	delete[] ctmp_ip;
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
