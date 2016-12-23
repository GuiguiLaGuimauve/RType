//
// SocketUDPWindows.hh for SocketUDPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Thu Dec 22 11:44:49 2016 La Guimauve
//

#ifndef _SocketUDPWindows_HH_
#define _SocketUDPWindows_HH_

#include "ASocketUDP.hh"

namespace Network
{
	/* La classe SocketUDPWindows d�finit les m�thodes des classes Socket UDP sp�cifiques � windows. */
	class		SocketUDPWindows : public ASocketUDP {
	public:
		SocketUDPWindows();
		virtual ~SocketUDPWindows();
		/* La m�thode bindIt(const uint32_t &) permet de bind le port du socket. */
		bool		bindIt(const uint32_t &);
		/* La m�thode getFdSocket() permet de r�cup�rer le descripteur de la socket. */
		int32_t		getFdSocket() const;
		/* La m�thode closeIt() permet de fermer la socket */
		bool		closeIt();
		/* La méthode getIpInfo() permet de récupérer l'ip de la socket */
    const std::string   getIpInfo() const;
	private:
		SOCKET		_sock;
	};
};

#endif
