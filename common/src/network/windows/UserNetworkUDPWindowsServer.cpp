//
// UserNetworkUDPWindowsServer.cpp for UserNetworkUDPWindowsServer.cpp in /home/dufren_b/teck3/rendu/CPP/RType/Network_Rtype/src/network/unix
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Thu Dec 15 15:33:48 2016 julien dufrene
// Last update Mon Jan  2 10:27:48 2017 julien dufrene
//

#include "UserNetworkUDPWindowsServer.hh"

using namespace Network;

UserNetworkUDPWindowsServer::UserNetworkUDPWindowsServer() : UserNetworkUDPWindows() {}

UserNetworkUDPWindowsServer::~UserNetworkUDPWindowsServer() {}

IUserNetwork		*UserNetworkUDPWindowsServer::readSocket(ISocket *net)
{
  WSABUF                        DataBuf;
  DWORD                         RecvBytes;
  DWORD                         Flags;
  char                          *buffer = new char[16384];
  sockaddr_in                   s_in;
  int							s_inLen = sizeof(s_in);

  (void)net;
  s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
  s_in.sin_family = AF_INET;
  if (WSAHtons(_fd, _port, &(s_in.sin_port)) == SOCKET_ERROR)
  {
	  std::cerr << "UNUWS Error on WSAHtons: " << WSAGetLastError() << std::endl;
	  IUserNetwork		*u = new UserNetworkUDPWindowsServer(*this);
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
      PacketUnknown pkt((uint8_t *)buffer, RecvBytes);
      setIp(inet_ntoa(s_in.sin_addr));
      setPort(ntohs(s_in.sin_port));
      setFd(net->getFdSocket());
      pushBufferRead(pkt);
      setStatus(true);
    }
  else
    if (WSAGetLastError() != 10035 && WSAGetLastError() != 10060 && WSAGetLastError() != 10054)
      {
		std::cout << "NB error from WSARecvFrom: " << WSAGetLastError() << std::endl;
		closeFd();
      }
  if (RecvBytes == -1)
    {
      std::cout << "LENGTH error from WSARecvFrom: " << WSAGetLastError() << std::endl;
      closeFd();
    }
  return (this);
}
