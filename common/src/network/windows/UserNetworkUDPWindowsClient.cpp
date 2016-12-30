//
// UserNetworkUDPWindowsClient.cpp for UserNetworkUDPWindowsClient.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Fri Dec 23 07:42:07 2016 julien dufrene
//

#include "UserNetworkUDPWindowsClient.hh"

using namespace Network;

UserNetworkUDPWindowsClient::UserNetworkUDPWindowsClient() : UserNetworkUDPWindows() {}

UserNetworkUDPWindowsClient::~UserNetworkUDPWindowsClient() {}

IUserNetwork		*UserNetworkUDPWindowsClient::readSocket(ISocket *net)
{
  WSABUF						DataBuf;
  DWORD							RecvBytes;
  DWORD							Flags;
  char							*buffer = new char[16384];
  sockaddr_in                   s_in;
  int                           s_inLen = sizeof(s_in);
  u_short						port;

  (void)net;
  std::cout << "Trying to recv from ip: " << _ip << " port: " << _port << std::endl;
  s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
  s_in.sin_family = AF_INET;
  if (WSAHtons(_fd, _port, &(s_in.sin_port)) == SOCKET_ERROR)
  {
	  std::cerr << "UNUWC Error on WSAHtons: " << WSAGetLastError() << std::endl;
	  IUserNetwork		*u = new UserNetworkUDPWindowsClient(*this);
	  return (u);
  }
  DataBuf.len = 16384;
  DataBuf.buf = buffer;
  Flags = 0;
  if (WSARecvFrom(_fd, &DataBuf, 1, &RecvBytes, &Flags, (sockaddr *)&s_in, &s_inLen, NULL, NULL) != SOCKET_ERROR)
    {
      char                    *res = new char[RecvBytes];
      uint32_t                i = 0;
      while (i < RecvBytes)
	{
	  res[i] = DataBuf.buf[i];
	  i++;
	}
      res[i] = 0;
      PacketUnknown pkt((uint8_t *)res, RecvBytes);
      buff_r.push(pkt);
      if (WSANtohs(_fd, s_in.sin_port, &port) == SOCKET_ERROR)
	std::cerr << "Error from Wsatohs(): " << WSAGetLastError() << std::endl;
      else
	std::cout << "Sender: " << inet_ntoa(s_in.sin_addr) << ":" << port << std::endl;
    }
  else
    if (WSAGetLastError() != 10035 && WSAGetLastError() != 10060)
      {
	std::cout << "error from WSARecvFrom: " << WSAGetLastError() << std::endl;
	closeFd();
      }
	else if (WSAGetLastError() != 10022)
	{
		std::cout << "Error :" << WSAGetLastError() << std::endl;
	}
  if (RecvBytes == -1)
    {
      std::cout << "error from WSARecvFrom: " << WSAGetLastError() << std::endl;
      closeFd();
    }
  return (this);
}
