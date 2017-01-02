//
// UserNetworkTCPSfml.hh for UserNetworkTCPSfml.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Sat Dec 24 16:29:19 2016 julien dufrene
//

#ifndef _USERNETWORKTCPUNIX_HPP_
#define _USERNETWORKTCPUNIX_HPP_

#include "UserNetworkTCP.hpp"

namespace Network
{
  /*!
    en :UserNetworTCPSfml defines the methods for UserNetworkTCP classes on windows.
    fr :La classe UserNetworkTCPSfml définit les méthodes des classes UserNetworkTCP utilisant l'api Sfml.
  */
  class		UserNetworkTCPSfml : public UserNetworkTCP {
  public:
    UserNetworkTCPSfml() : UserNetworkTCP() {};
    virtual ~UserNetworkTCPSfml() {};
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    virtual IUserNetwork		*readSocket(ISocket *) = 0;
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    virtual void			writeSocket(ISocket *) = 0;
    /*! La methode closeFd permet de fermer la socket du client. */
    void				closeFd()
    {
      std::cout << "Closing socket sfml" << std::endl;
      _fd.disconnect();
    };
  };
};

#endif
