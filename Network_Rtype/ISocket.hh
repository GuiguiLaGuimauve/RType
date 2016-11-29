//
// ISocket.hh for ISocket.hh in /home/dufren_b/teck3/rendu/CPP/cpp_babel/include
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _ISOCKET_HH_
#define _ISOCKET_HH_

#include <iostream>
#include <string>
#include "DataClient.hh"

#ifdef _WIN32
	#include <sys\types.h>
	#include <winsock2.h>
	#include <Windows.h>
	#include <WS2tcpip.h>
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
#endif

namespace Network
{
  /* L'interface ISocket définit les méthodes des classes Socket. */
  class		ISocket {
  public:
    virtual ~ISocket() {};
	/* La méthode createIt() permet de créé une socket */
	virtual bool		createIt() = 0;
    /* La méthode bindIt(const uint32_t &) permet de bind le port du socket. */
    virtual bool		bindIt(const uint32_t &) = 0;
	/* La méthode listenIt(const uint32_t &) permet d'écouter sur le socket. */
    virtual bool		listenIt(const uint32_t &) = 0;
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
