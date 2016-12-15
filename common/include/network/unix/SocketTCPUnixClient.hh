//
// SocketTCPUnix.hh for SocketTCPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Thu Dec 15 15:58:18 2016 julien dufrene
//

#ifndef _SocketTCPUnixClient_HH_
#define _SocketTCPUnixClient_HH_

#include "SocketTCPUnix.hh"

namespace Network
{
  /* La classe SocketTCPUnixClient d�finit les m�thodes de la classe SocketTCPUnix sp�cifiques aux clients. */
  class		SocketTCPUnixClient : public SocketTCPUnix {
  public:
    SocketTCPUnixClient();
    virtual ~SocketTCPUnixClient();
    /* La m�thode connectIt(const std::string &, const uint32_t &) permet de se connecter sur une socket TCP. */
    bool		connectIt(const std::string &ip, const uint32_t &port);
  };
};

#endif
