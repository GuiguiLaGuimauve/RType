//
// UserNetworkTCPUnixServer.hh for UserNetworkTCPUnixServer.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec  2 16:44:22 2016 julien dufrene
//

#ifndef _USERNETWORKTCPUNIXSERVER_HH_
#define _USERNETWORKTCPUNIXSERVER_HH_

#include "UserNetworkTCPUnix.hpp"
#include "UserNetworkTCPUnixClient.hh"

namespace Network
{
  /*!
    en :UserNetworTCPUnixServer defines the methods for UserNetworkTCPUnix classes specialized for server.
    fr :La classe UserNetworkTCPUnixServer définit les méthodes des classes UserNetworkTCPUnix spécialisés pour les serveurs.
  */
  class		UserNetworkTCPUnixServer : public UserNetworkTCPUnix {
  public:
    UserNetworkTCPUnixServer();
    virtual ~UserNetworkTCPUnixServer();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    IUserNetwork	*readSocket(ISocket *);
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    void			writeSocket(ISocket *);
  };
};

#endif
