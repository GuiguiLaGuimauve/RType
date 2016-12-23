//
// UserNetworkUDPWindows.hh for UserNetworkUDPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 08:52:05 2016 La Guimauve
//

#ifndef _USERNETWORKUDPWINDOWS_HH_
#define _USERNETWORKUDPWINDOWS_HH_

#include "UserNetworkUDP.hpp"

namespace Network
{
  /*!
    en :UserNetworUDPWindows defines the methods for UserNetworkUDP classes on windows.
    fr :La classe UserNetworkUDPWindows définit les méthodes des classes UserNetworkUDP utilisant l'api Windows.
  */
  class		UserNetworkUDPWindows : public UserNetworkUDP {
  public:
    UserNetworkUDPWindows() {};
    virtual ~UserNetworkUDPWindows() {};
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    virtual IUserNetwork	*readSocket(ISocket *) = 0;
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    void			writeSocket(ISocket *net)
    {
      (void)net;
      PacketUnknown         to_write;
      sockaddr_in           s_out;
	  int32_t				nb;
	  WSABUF				DataBuf;
	  DWORD                 SendBytes;
	  
	  if ((nb = inet_pton(AF_INET, _ip.c_str(), &s_out.sin_addr.s_addr)) <= 0)
		{
			std::cerr << "Error on inet_pton: " << WSAGetLastError() << std::endl;
			return;
		}
      s_out.sin_family = AF_INET;
      if (WSAHtons(_fd, _port, &(s_out.sin_port)) == SOCKET_ERROR)
	std::cerr << "Error on WSAHtons: " << WSAGetLastError() << std::endl;
      to_write = buff_w.pop();
      DataBuf.len = to_write.getPacketSize();
      DataBuf.buf = (char *)(to_write.getPacketData());
      std::cout << "Trying to send to: " << _ip << ":" << _port << std::endl;
      if ((nb = WSASendTo(_fd, &DataBuf, 1, &SendBytes, 0, (sockaddr *)&s_out, sizeof (s_out), NULL, NULL)) \
	  == SOCKET_ERROR || DataBuf.len != SendBytes)
	std::cerr << "Error on WSASendTo: " << WSAGetLastError() << std::endl;
    };
    /*! La methode closeFd permet de fermer la socket du client. */
    void			closeFd()
    {
      if (getStatus() == true)
        {
	  std::cout << "Closing socket " << _fd << std::endl;
	  closesocket(_fd);
	  setStatus(false);
	  _fd = -1;
	}
    };
  };
};

#endif
