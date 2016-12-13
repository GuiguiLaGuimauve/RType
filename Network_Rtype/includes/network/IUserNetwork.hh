//
// IUserNetwork.hh for IUserNetwork.hh in /home/dufren_b/teck3/rendu/CPP/cpp_babel/common/include
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Mon Nov 14 19:57:21 2016 lecoq
//

#ifndef _IUSERNETWORK_HH_
#define _IUSERNETWORK_HH_

#include "ISocket.hh"
#include <iostream>
#ifdef _WIN32
#else
	#include <unistd.h>
#endif

namespace Network
{
  /*!
    L'interface IUserNetwork définit les méthodes de la classe AUserNetwork.
  */   
  class		IUserNetwork {
  public:
    virtual ~IUserNetwork() {};
    /*! La methode readSocket(INetowork *) permet de lire sur un socket et donc de récupérer ce qui à été écris de l'autre côté du socket. */
    virtual IUserNetwork			*readSocket(ISocket *) = 0;
    /*! La methode writeSocket(INetowork *) permet d'écrire sur un socket. */
    virtual void					writeSocket(ISocket *) = 0;
    /*! La methode setFd(const uint32_t) permet de set le Descripteur de fichier du client. */
    virtual void					setFd(const int32_t &) = 0;
    /*! La methode getFd() permet de récupérer le Descripteur de fichier du client. */
    virtual int32_t					getFd() const = 0;
	/*! La methode setPort(const uint32_t) permet de set le Port de la socket du client. */
	virtual void					setPort(const uint32_t &) = 0;
	/*! La methode getPort() permet de récupérer le Port de la socket du client. */
	virtual uint32_t					getPort() const = 0;
	/*! La methode setIp(const std::string &) permet de set l'adresse ip du client. */
    virtual void					setIp(const std::string &) = 0;
    /*! La methode getIp() permet de récupérer l'adresse ip du client. */
    virtual const std::string		&getIp() const = 0;
    /*! La méthode pushBufferWrite() permet d'ajouter une chaine dans le buffer d'écriture */
    virtual void					pushBufferWrite(const std::string &) = 0;
	/*! La méthode popBufferRead() permet de récupérer une chaine dans le buffer de lecture */
    virtual const std::string		popBufferRead() = 0;
    /*! La méthode haveSomethingToWrite() permet de savoir si il y a quelque chose à écrire. */
    virtual void				closeFd() = 0;
  };
};

#endif
