//
// UserNetworkUDPUnixClient.hh for UserNetworkUDPUnixClient.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 02:56:09 2016 julien dufrene
//

#ifndef _USERNETWORKUDPUNIXCLIENT_HH_
#define _USERNETWORKUDPUNIXCLIENT_HH_

#include "UserNetworkUDPUnix.hh"

namespace Network
{
  /*!
    en :UserNetworUDPUnixClient defines the methods for UserNetworkUDPUnix classes on client side.
    fr :La classe UserNetworkUDPUnixClient définit les méthodes des classes UserNetworkUDPUnix coté client.
  */
  class		UserNetworkUDPUnixClient : public UserNetworkUDPUnix {
  public:
    UserNetworkUDPUnixClient();
    virtual ~UserNetworkUDPUnixClient();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    IUserNetwork	*readSocket(ISocket *);
  };
};

#endif
