//
// UserNetworkTCPWindowsClient.cpp for UserNetworkTCPWindowsClient.cpp in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 21 15:02:22 2016 julien dufrene
// Last update Fri Dec 23 07:26:54 2016 julien dufrene
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
		int32_t			i = 0;
		while (i < RecvBytes)
		{
			res[i] = DataBuf.buf[i];
			i++;
		}
		res[i] = 0;
		cutRead((uint8_t *)res, i);
		//		PacketUnknown pkt((uint8_t *)res, RecvBytes);
		//buff_r.push(pkt);   
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
  WSABUF                  DataBuf;
  DWORD                   SendBytes;
  DWORD                   Flags;
  int                             nb;
  PacketUnknown           write;

  write = buff_w.front();
  DataBuf.len = write.getPacketSize();
  DataBuf.buf = (char *)(write.getPacketData());
  Flags = 0;
  if ((nb = WSASend(_fd, &DataBuf, 1, &SendBytes, 0, NULL, NULL)) == SOCKET_ERROR || \
      write.getPacketSize() != SendBytes)
    std::cerr << "Error on write: " << WSAGetLastError() << std::endl;
  else
    buff_w.pop();
}
