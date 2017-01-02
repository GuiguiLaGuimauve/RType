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
    fr :La classe UserNetworkTCPSfmlServer d�finit les m�thodes des classes UserNetworkTCPSfml sp�cialis�s pour les serveurs.
  */
  class		UserNetworkTCPSfmlServer : public UserNetworkTCPSfml {
  public:
    UserNetworkTCPSfmlServer();
    virtual ~UserNetworkTCPSfmlServer();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
    IUserNetwork	*readSocket(ISocket *);
    /*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
    void		writeSocket(ISocket *);
  };
};

#endif
