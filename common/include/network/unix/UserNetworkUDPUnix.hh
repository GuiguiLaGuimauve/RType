//
// UserNetworkUDPUnix.hh for UserNetworkUDPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 11:03:49 2016 lecoq
//

#ifndef _USERNETWORKUDPUNIX_HH_
#define _USERNETWORKUDPUNIX_HH_

#include "UserNetworkUDP.hpp"

namespace Network
{
  /*!
    en :UserNetworUDPUnix defines the methods for UserNetworkUDP classes on windows.
    fr :La classe UserNetworkUDPUnix d�finit les m�thodes des classes UserNetworkUDP utilisant l'api Unix.
  */
  class		UserNetworkUDPUnix : public UserNetworkUDP {
  public:
    UserNetworkUDPUnix();
    virtual ~UserNetworkUDPUnix();
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
    virtual IUserNetwork	*readSocket(ISocket *) = 0;
    /*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
	void			writeSocket(ISocket *net);
    /*! La methode closeFd permet de fermer la socket du client. */
	void			closeFd();
  };
};

#endif
