//
// UserNetworkTCPSfmlClient.hh for UserNetworkTCPSfmlClient.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Sat Dec 24 16:30:51 2016 julien dufrene
//

#ifndef _USERNETWORKTCPUNIXCLIENT_HH_
#define _USERNETWORKTCPUNIXCLIENT_HH_

#include "UserNetworkTCPSfml.hpp"

namespace Network
{
  /*!
    en :UserNetworTCPSfmlClient defines the methods for UserNetworkTCPSfml classes specialized for Client.
    fr :La classe UserNetworkTCPSfmlClient définit les méthodes des classes UserNetworkTCPSfml spécialisés pour les clients.
  */
  class		UserNetworkTCPSfmlClient : public UserNetworkTCPSfml {
  public:
    UserNetworkTCPSfmlClient();
    virtual ~UserNetworkTCPSfmlClient();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    IUserNetwork	*readSocket(ISocket *);
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    void		writeSocket(ISocket *);
  };
};

#endif
