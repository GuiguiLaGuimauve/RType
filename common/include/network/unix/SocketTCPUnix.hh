//
// SocketTCPUnix.hh for SocketTCPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Wed Dec 21 06:39:26 2016 julien dufrene
//

#ifndef _SocketTCPUnix_HH_
#define _SocketTCPUnix_HH_

#include "ASocketTCP.hh"

namespace Network
{
  /* La classe SocketTCPUnix d�finit les m�thodes des classes Socket TCP sp�cifiques � Unix. */
  class		SocketTCPUnix : public ASocketTCP {
  public:
    SocketTCPUnix();
    virtual ~SocketTCPUnix();
    /* La m�thode createIt() permet de cr�� une socket */
    bool		createIt();
    /* La m�thode bindIt(const uint32_t &) permet de bind le port de la socket. */
    bool		bindIt(const uint32_t &);
    /* La m�thode listenIt(const uint32_t &) permet d'�couter sur la socket. */
    bool		listenIt(const uint32_t &);
    /* La m�thode acceptClient(DataClient &) permet d'accepter une connexion */
    bool		acceptClient(DataClient &d);
    /* La m�thode connectIt(const std::string &, const uint32_t &) permet de se connecter sur une socket TCP. */
    virtual bool		connectIt(const std::string &ip, const uint32_t &port)
    {
      (void)ip; (void)port;
      return (false);
    }
    /* La m�thode getIpInfo() permet de r�cup�rer l'ip de la socket */
    const std::string   getIpInfo() const;
    /* La m�thode getFdSocket() permet de r�cup�rer le descripteur de la socket. */
    int32_t		getFdSocket() const;
    /* La m�thode closeIt() permet de fermer la socket */
    bool		closeIt();
  protected:
    int32_t		_sock;
  };
};

#endif