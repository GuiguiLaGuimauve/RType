//
// SocketTCPSfml.hh for SocketTCPSfml.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Sat Dec 24 16:23:06 2016 julien dufrene
//

#ifndef _SocketTCPSfmlClient_HH_
#define _SocketTCPSfmlClient_HH_

#include "SocketTCPSfml.hh"

namespace Network
{
  /* La classe SocketTCPSfmlClient définit les méthodes de la classe SocketTCPSfml spécifiques aux clients. */
  class		SocketTCPSfmlClient : public SocketTCPSfml {
  public:
    SocketTCPSfmlClient();
    virtual ~SocketTCPSfmlClient();
    /* La méthode connectIt(const std::string &, const uint32_t &) permet de se connecter sur une socket TCP. */
    bool		connectIt(const std::string &ip, const uint32_t &port);
  };
};

#endif
