//
// UserNetworkTCPWindowsClient.cpp for UserNetworkTCPWindowsClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Tue Nov 15 01:19:23 2016 lecoq
//

#include "UserNetworkTCPWindowsClient.hh"

using namespace Network;

UserNetworkTCPWindowsClient::UserNetworkTCPWindowsClient() : UserNetworkTCPWindows() {}

UserNetworkTCPWindowsClient::~UserNetworkTCPWindowsClient() {}

IUserNetwork		*UserNetworkTCPWindowsClient::readSocket(ISocket *net)
{
   	WSABUF			DataBuf;
	DWORD			RecvBytes;
	DWORD			Flags;
	char			*buffer = new char[16384];
	
	DataBuf.len = 16384;
	DataBuf.buf = buffer;
	Flags = 0;
	if (WSARecv(_fd, &DataBuf, 1, &RecvBytes, &Flags, NULL, NULL) != SOCKET_ERROR)
	{
		char			*res = new char[RecvBytes];
		uint32_t		i = 0;
		while (i < RecvBytes)
		{
			res[i] = DataBuf.buf[i];
			i++;
		}
		std::string tmp(res);
		buff_r.push(tmp);
	}
	else
	{
		std::cout << "error from WSARecv: " << WSAGetLastError() << std::endl;
		closeFd();
	}
	if (RecvBytes == 0 || RecvBytes == -1)
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
	std::string		write;

	write = buff_w.pop();
	DataBuf.len = write.size();
	DataBuf.buf = (char *)write.c_str();
	Flags = 0;
	if ((nb = WSASend(_fd, &DataBuf, 1, &SendBytes, 0, NULL, NULL)) == SOCKET_ERROR || write.size() != SendBytes)
	  std::cerr << "Error on write: " << WSAGetLastError() << std::endl;
}