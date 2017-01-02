//
// UserNetworkTCPSfmlServer.hh for UserNetworkTCPSfmlServer.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Sat Dec 24 16:30:19 2016 julien dufrene
//

#ifndef _USERNETWORKTCPSFMLSERVER_HH_
#define _USERNETWORKTCPSFMLSERVER_HH_

#include "UserNetworkTCPSfml.hpp"
#include "UserNetworkTCPSfmlClient.hh"

namespace Network
{
  /*!
    en :UserNetworTCPSfmlServer defines the methods for UserNetworkTCPSfml classes specialized for server.
    fr :La classe UserNetworkTCPSfmlServer définit les méthodes des classes UserNetworkTCPSfml spécialisés pour les serveurs.
  */
  class		UserNetworkTCPSfmlServer : public UserNetworkTCPSfml {
  public:
    UserNetworkTCPSfmlServer();
    virtual ~UserNetworkTCPSfmlServer();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    IUserNetwork	*readSocket(ISocket *);
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    void		writeSocket(ISocket *);
  };
};

#endif
