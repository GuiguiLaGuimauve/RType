//
// UserNetworkTCPUnix.hh for UserNetworkTCPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Thu Dec 15 15:48:22 2016 julien dufrene
//

#ifndef _USERNETWORKTCPUNIX_HPP_
#define _USERNETWORKTCPUNIX_HPP_

#include "UserNetworkTCP.hpp"

namespace Network
{
  /*!
    en :UserNetworTCPUnix defines the methods for UserNetworkTCP classes on windows.
    fr :La classe UserNetworkTCPUnix définit les méthodes des classes UserNetworkTCP utilisant l'api Unix.
  */
  class		UserNetworkTCPUnix : public UserNetworkTCP {
  public:
    UserNetworkTCPUnix() : UserNetworkTCP() {};
    virtual ~UserNetworkTCPUnix() {};
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    virtual IUserNetwork	*readSocket(ISocket *) = 0;
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    virtual void			writeSocket(ISocket *) = 0;
    /*! La methode closeFd permet de fermer la socket du client. */
    void					closeFd()
    {
      if (_fd != -1)
	{
	  std::cout << "Closing socket: " << _fd << std::endl;
	  close(_fd);
	  setStatus(false);
	}
    };
  };
};

#endif
