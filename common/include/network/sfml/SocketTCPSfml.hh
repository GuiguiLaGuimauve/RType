//
// SocketTCPSfml.hh for SocketTCPSfml.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Sat Dec 24 16:47:43 2016 julien dufrene
//

#ifndef _SocketTCPSFML_HH_
#define _SocketTCPSFML_HH_

#include "ASocketTCP.hh"

#include <SFML/Network.hpp>

namespace Network
{
  /* La classe SocketTCPSfml d�finit les m�thodes des classes Socket TCP sp�cifiques � Sfml. */
  class		SocketTCPSfml : public ASocketTCP {
  public:
    SocketTCPSfml();
    virtual ~SocketTCPSfml();
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
    sf::TcpSocket	_sock;
  private:
    sf::TcpListener	_listen;
    uint32_t		_port;
  };
};

#endif
