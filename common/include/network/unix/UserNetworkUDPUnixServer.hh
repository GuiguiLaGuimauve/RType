//
// UserNetworkUDPUnixServer.hh for UserNetworkUDPUnixServer.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 02:55:28 2016 julien dufrene
//

#ifndef _USERNETWORKUDPUNIXSERVER_HH_
#define _USERNETWORKUDPUNIXSERVER_HH_

#include "UserNetworkUDPUnix.hh"

namespace Network
{
  /*!
    en :UserNetworUDPUnix defines the methods for UserNetworkUDPUnix classes on server side.
    fr :La classe UserNetworkUDPUnix d�finit les m�thodes des classes UserNetworkUDPUnix cot� serveur.
  */
  class		UserNetworkUDPUnixServer : public UserNetworkUDPUnix {
  public:
    UserNetworkUDPUnixServer();
    virtual ~UserNetworkUDPUnixServer();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
    IUserNetwork	*readSocket(ISocket *);
  };
};

#endif
