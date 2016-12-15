//
// UserNetworkTCPWindowsClient.cpp for UserNetworkTCPWindowsClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Thu Dec 15 15:29:24 2016 julien dufrene
//

#include "UserNetworkTCPWindowsClient.hh"

using namespace Network;

UserNetworkTCPWindowsClient::UserNetworkTCPWindowsClient() : UserNetworkTCPWindows() {}

UserNetworkTCPWindowsClient::~UserNetworkTCPWindowsClient() {}

IUserNetwork		*UserNetworkTCPWindowsClient::readSocket(ISocket *net)
{
	bool			error;
	WSABUF			DataBuf;
	DWORD			RecvBytes;
	DWORD			Flags;
	char			*buffer = new char[16384];
	
	(void)net;
	DataBuf.len = 16384;
	DataBuf.buf = buffer;
	Flags = 0;
	error = false;
	if (WSARecv(_fd, &DataBuf, 1, &RecvBytes, &Flags, NULL, NULL) != SOCKET_ERROR)
	{
		char			*res = new char[RecvBytes];
		uint32_t		i = 0;
		while (i < RecvBytes)
		{
			res[i] = DataBuf.buf[i];
			i++;
		}
		res[i] = 0;
		std::string tmp(res);
		buff_r.push(tmp);
	}
	else
	{
		error = true;
		if (WSAGetLastError() == 10054)
			std::cerr << "Connection reset by peer!" << std::endl;
		else
			std::cerr << "error from WSARecv: " << WSAGetLastError() << std::endl;
		closeFd();
	}
	if (error == false && (RecvBytes == 0 || RecvBytes == -1))
		closeFd();
	IUserNetwork		*u = new UserNetworkTCPWindowsClient(*this);
	return (u);
}

void			UserNetworkTCPWindowsClient::writeSocket(ISocket *net)
{
  	WSABUF			DataBuf;
	DWORD			SendBytes;
	DWORD			Flags;
	int				nb;
	std::string		write = "";

	std::cout << "Write: ";
	write = buff_w.front();
	std::cout << "[" << write << "]" << std::endl;
	DataBuf.len = write.size();
	DataBuf.buf = (char *)write.c_str();
	Flags = 0;
	if ((nb = WSASend(_fd, &DataBuf, 1, &SendBytes, 0, NULL, NULL)) == SOCKET_ERROR || write.size() != SendBytes)
	  std::cerr << "Error on WSASend: " << WSAGetLastError() << std::endl;
	else
	  buff_w.pop();
}
