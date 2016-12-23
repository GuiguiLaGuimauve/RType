//
// UserNetworkUDPWindows.cpp for UserNetworkUDPWindows.cpp in /home/dufren_b/teck3/rendu/CPP/RType
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Dec 02 15:02:22 2016 julien dufrene
// Last update Fri Dec 23 07:49:45 2016 julien dufrene
//
/*
#include "UserNetworkUDPWindows.hh"

using namespace Network;

UserNetworkUDPWindows::UserNetworkUDPWindows() : UserNetworkUDP() {}

UserNetworkUDPWindows::~UserNetworkUDPWindows() {}

IUserNetwork		*UserNetworkUDPWindows::readSocket(ISocket *net)
{
	WSABUF				DataBuf;
	DWORD				RecvBytes;
	DWORD				Flags;
	char				*buffer = new char[16384];
	sockaddr_in			s_in;
	int				s_inLen = sizeof(s_in);

	// s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
	// s_in.sin_family = AF_INET;
	// if (WSAHtons(_fd, _port, &(s_in.sin_port)) == SOCKET_ERROR)
	// {
	// 	std::cerr << "Error on WSAHtons: " << WSAGetLastError() << std::endl;
	// 	IUserNetwork		*u = new UserNetworkUDPWindows(*this);
	// 	return (u);
	// }
	// DataBuf.len = 16384;
	// DataBuf.buf = buffer;
	// Flags = 0;
	if (WSARecvFrom(_fd, &DataBuf, 1, &RecvBytes, &Flags, (sockaddr *)&s_in, &s_inLen, NULL, NULL) != SOCKET_ERROR)
	{
		char			*res = new char[RecvBytes];
		uint32_t		i = 0;
		while (i < RecvBytes)
		{
			res[i] = DataBuf.buf[i];
			i++;
		}
		res[i] = 0;
                PacketUnknown pkt((uint8_t *)res, RecvBytes);
		buff_r.push(pkt);
		if (s_in.sin_addr.s_addr != inet_addr(_ip.c_str())
		    && s_in.sin_port != htons(_port))
		  {
		    IUserNetwork        *u = new UserNetworkUDPWindows(*this);
		    u->setIp(inet_ntoa(s_in.sin_addr));
		    u->setFd(_fd);
		    u->setPort(s_in.sin_port);
		    u->setFd(net->getFdSocket());
		    return (u);
		  }
	}
	else
	{
		std::cout << "error from WSARecvFrom: " << WSAGetLastError() << std::endl;
		closeFd();
	}
	if (RecvBytes == 0 || RecvBytes == -1) {
		closeFd();
	}
	(void)net;
	IUserNetwork		*u = new UserNetworkUDPWindows(*this);
	return (u);
}

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
	if (WSAHtons(_fd, _port, &(s_out.sin_port)) == SOCKET_ERROR)
		std::cerr << "Error on WSAHtons: " << WSAGetLastError() << std::endl;
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
*/
