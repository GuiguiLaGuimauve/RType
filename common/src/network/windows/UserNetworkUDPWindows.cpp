//
// UserNetworkUDPWindows.cpp for UserNetworkUDPWindows.cpp in /home/dufren_b/teck3/rendu/CPP/RType
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Dec 02 15:02:22 2016 julien dufrene
// Last update Fri Dec 23 07:49:45 2016 julien dufrene
//

#include "UserNetworkUDPWindows.hh"

using namespace Network;

UserNetworkUDPWindows::UserNetworkUDPWindows() : UserNetworkUDP() {}

UserNetworkUDPWindows::~UserNetworkUDPWindows() {}

void			UserNetworkUDPWindows::writeSocket(ISocket *net)
{
	WSABUF			DataBuf;
	DWORD			SendBytes;
	DWORD			Flags;
	int			nb;
	PacketUnknown           write;
	sockaddr_in		s_out;

	if ((nb = inet_pton(AF_INET, _ip.c_str(), &s_out.sin_addr.s_addr)) <= 0)
	{
	  std::cerr << "Error on inet_pton: " << WSAGetLastError() << std::endl;
	  return;
	}
	s_out.sin_family = AF_INET;
	//TODO : Le port semble mauvais à revoir
	if (WSAHtons(_fd, _port, &(s_out.sin_port)) == SOCKET_ERROR)
	{
	  std::cerr << "UNUW Error on WSAHtons: " << WSAGetLastError() << std::endl;
	}
	write = buff_w.pop();
	DataBuf.len = write.getPacketSize();
	DataBuf.buf = (char *)(write.getPacketData());
	Flags = 0;
	if ((nb = WSASendTo(_fd, &DataBuf, 1, &SendBytes, 0, (sockaddr *)&s_out, sizeof (s_out), NULL, NULL)) == SOCKET_ERROR || DataBuf.len != SendBytes)
		std::cerr << "Error on WSASendTo: " << WSAGetLastError() << std::endl;
}

void			UserNetworkUDPWindows::closeFd()
{
	if (_fd != -1)
	{
		std::cout << "Closing socket " << _fd << std::endl;
		closesocket(_fd);
		setStatus(false);
		_fd = -1;
	}
}
