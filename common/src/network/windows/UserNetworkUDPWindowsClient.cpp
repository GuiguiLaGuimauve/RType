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
  WSABUF			DataBuf;
  DWORD				RecvBytes;
  DWORD				Flags;
  char				*buffer = new char[16384];
  sockaddr_in                   s_in;
  int                           s_inLen = sizeof(s_in);
  u_short			port;

  (void)net;
  std::cout << "Trying to recv from: " << _ip << ":" << _port << std::endl;
  if (WSARecvFrom(_fd, &DataBuf, 1, &RecvBytes, &Flags, (sockaddr *)&s_in, &s_inLen, NULL, NULL) != SOCK\
      ET_ERROR)
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
    if (WSAGetLastError() != 10035)
      {
	std::cout << "error from WSARecvFrom: " << WSAGetLastError() << std::endl;
	closeFd();
      }
  if (nb == -1)
    {
      std::cout << "error from WSARecvFrom: " << WSAGetLastError() << std::endl;
      closeFd();
    }
  return (this);
}
