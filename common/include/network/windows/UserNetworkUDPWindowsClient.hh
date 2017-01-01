//
// UserNetworkUDPWindowsClient.hh for UserNetworkUDPWindowsClient.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 07:22:23 2016 julien dufrene
//

#ifndef _USERNETWORKUDPWINDOWSCLIENT_HH_
#define _USERNETWORKUDPWINDOWSCLIENT_HH_

#include "UserNetworkUDPWindows.hh"

namespace Network
{
  /*!
    en :UserNetworUDPWindowsClient defines the methods for UserNetworkUDPWindows classes on client side.
    fr :La classe UserNetworkUDPWindowsClient définit les méthodes des classes UserNetworkUDPWindows coté client.
  */
  class		UserNetworkUDPWindowsClient : public UserNetworkUDPWindows {
  public:
    UserNetworkUDPWindowsClient();
    virtual ~UserNetworkUDPWindowsClient();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    IUserNetwork	*readSocket(ISocket *);
  };
};

#endif
