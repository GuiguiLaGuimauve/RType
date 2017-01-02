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
  if ((ret = ioctlsocket(m_socket, FIONBIO, &iMode)) != NO_ERROR)
    throw ErrorSocket("Error on ioctlsocket(): " + ret);
}

bool			SocketTCPWindowsClient::connectIt(const std::string &ip, const uint32_t &port)
{
	struct sockaddr_in	s_in;

	s_in.sin_family = AF_INET;
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
		// std::cerr << "Error on WSASocket(): " << WSAGetLastError() << std::endl;
		// return (false);
	  if (WSAGetLastError() == WSAEINPROGRESS)
	    {
	      FD_ZERO(&write);
	      FD_SET(_sock, &write);
	      if (select(_sock + 1, NULL, &write, NULL, &tv) != -1)
		{
		  len = sizeof (s_in);
		  if (getpeername(_sock, (struct sockaddr *)&s_in, &len) == WSAENOTCONN)
		    return (false);
		  else
		    {
		      std::cout << "timeout: " << c.getTimeMilli() << "ms" << std::endl;
		      if (c.getTimeMilli() < 100)
			return (true);
		    }
		}
	    }
	  return (false);
	}
	return (true);
}

SocketTCPWindowsClient::~SocketTCPWindowsClient() {}
