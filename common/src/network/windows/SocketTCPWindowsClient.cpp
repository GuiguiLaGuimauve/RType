//
// SocketWindowsClient.cpp for SocketWindowsClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 15:52:42 2016 julien dufrene
// Last update Fri Dec 23 07:23:53 2016 julien dufrene
//

#include "SocketTCPWindowsClient.hh"

using namespace Network;

SocketTCPWindowsClient::SocketTCPWindowsClient() : SocketTCPWindows() {}

bool			SocketTCPWindowsClient::connectIt(const std::string &ip, const uint32_t &port)
{
	struct sockaddr_in	s_in;

	s_in.sin_family = AF_INET;
	if (inet_pton(AF_INET, ip.c_str(), &s_in.sin_addr.s_addr) <= 0)
		return (false);
	if (WSAHtons(_sock, port, &s_in.sin_port) == SOCKET_ERROR)
		return (false);
	if (WSAConnect(_sock, (struct sockaddr *)&s_in, sizeof(s_in), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
		return (false);
	return (true);
}

SocketTCPWindowsClient::~SocketTCPWindowsClient() {}
