//
// ISocket.hh for ISocket.hh in /home/dufren_b/teck3/rendu/CPP/cpp_babel/include
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Wed Dec 21 06:25:29 2016 julien dufrene
//

#ifndef _ISOCKET_HH_
#define _ISOCKET_HH_

#include <iostream>
#include <string>
#include "DataClient.hpp"
#include "ErrorSocket.hpp"

#ifdef _WIN32
	#include <sys\types.h>
	#include <winsock2.h>
	#include <Windows.h>
	#include <WS2tcpip.h>
	// Disable deprecated API Warning
	#define _CRT_NONSTDC_NO_WARNINGS
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#pragma comment(lib, "WS2_32")
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#include <unistd.h>
#endif

namespace Network
{
/* L'interface ISocket définit les méthodes des classes Socket. */
  class		ISocket {
  public:
    virtual ~ISocket() {};
    /* La méthode bindIt(const uint32_t &) permet de bind le port du socket. */
    virtual bool		bindIt(const uint32_t &) = 0;
    /* La méthode listenIt(const uint32_t &) permet d'écouter sur le socket. */
    virtual bool		listenIt(const uint32_t &) = 0;
    /* La méthode getIpInfo() permet de récupérer l'ip de la socket */
    virtual const std::string	getIpInfo() const = 0;	
      /* La méthode acceptClient(DataClient &) permet d'accepter un client.. */
    virtual bool		acceptClient(DataClient &) = 0;
    /* La méthode connectIt(const std::string &, const uint32_t &) permet connecter un socket à un autre socket. */
    virtual bool		connectIt(const std::string &, const uint32_t &) = 0;
    /* La méthode getFdSocket() permet de récupérer le descripteur de la socket. */
    virtual int32_t		getFdSocket() const = 0;
	/* La méthode closeIt() permet de fermer la socket */
    virtual bool		closeIt() = 0;
  };
};

#endif
