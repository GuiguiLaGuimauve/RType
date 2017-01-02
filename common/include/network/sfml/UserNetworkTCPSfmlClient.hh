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
    fr :La classe UserNetworkTCPSfmlClient d�finit les m�thodes des classes UserNetworkTCPSfml sp�cialis�s pour les clients.
  */
  class		UserNetworkTCPSfmlClient : public UserNetworkTCPSfml {
  public:
    UserNetworkTCPSfmlClient();
    virtual ~UserNetworkTCPSfmlClient();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
    IUserNetwork	*readSocket(ISocket *);
    /*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
    void		writeSocket(ISocket *);
  };
};

#endif
