//
// SocketUDPUnix.hh for SocketUDPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Wed Dec 21 08:43:41 2016 julien dufrene
//

#ifndef _SocketUDPUnix_HH_
#define _SocketUDPUnix_HH_

#include "ASocketUDP.hh"
#include <fcntl.h>

namespace Network
{
  /* La classe SocketUDPUnix définit les méthodes des classes Socket UDP spécifiques à Unix. */
  class		SocketUDPUnix : public ASocketUDP {
  public:
    SocketUDPUnix();
    virtual ~SocketUDPUnix();
    /* La méthode bindIt(const uint32_t &) permet de bind le port du socket. */
    bool		bindIt(const uint32_t &);
    /* La méthode getFdSocket() permet de récupérer le descripteur de la socket. */
    int32_t		getFdSocket() const;
    /* La méthode closeIt() permet de fermer la socket */
    bool		closeIt();
    /* La méthode getIpInfo() permet de récupérer l'ip de la socket */
    const std::string   getIpInfo() const;
  private:
    int32_t		_sock;
  };
};

#endif
