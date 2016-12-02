//
// UserNetworkTCPUnixClient.hh for UserNetworkTCPUnixClient.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec  2 16:44:41 2016 julien dufrene
//

#ifndef _USERNETWORKTCPUNIXCLIENT_HH_
#define _USERNETWORKTCPUNIXCLIENT_HH_

#include "UserNetworkTCPUnix.hpp"

namespace Network
{
  /*!
    en :UserNetworTCPUnixClient defines the methods for UserNetworkTCPUnix classes specialized for Client.
    fr :La classe UserNetworkTCPUnixClient d�finit les m�thodes des classes UserNetworkTCPUnix sp�cialis�s pour les clients.
  */
  class		UserNetworkTCPUnixClient : public UserNetworkTCPUnix {
  public:
    UserNetworkTCPUnixClient();
    virtual ~UserNetworkTCPUnixClient();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
    IUserNetwork	*readSocket(ISocket *);
    /*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
    void			writeSocket(ISocket *);
  };
};

#endif
