//
// UserNetworkUDPWindowsServer.hh for UserNetworkUDPWindowsServer.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 07:21:57 2016 julien dufrene
//

#ifndef _USERNETWORKUDPWINDOWSSERVER_HH_
#define _USERNETWORKUDPWINDOWSSERVER_HH_

#include "UserNetworkUDPWindows.hh"

namespace Network
{
  /*!
    en :UserNetworUDPWindows defines the methods for UserNetworkUDPWindows classes on server side.
    fr :La classe UserNetworkUDPWindows d�finit les m�thodes des classes UserNetworkUDPWindows cot� serveur.
  */
  class		UserNetworkUDPWindowsServer : public UserNetworkUDPWindows {
  public:
    UserNetworkUDPWindowsServer();
    virtual ~UserNetworkUDPWindowsServer();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
    IUserNetwork	*readSocket(ISocket *);
  };
};

#endif
