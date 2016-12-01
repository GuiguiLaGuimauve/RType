//
// SocketUDPUnix.hh for SocketUDPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _SocketUDPUnix_HH_
#define _SocketUDPUnix_HH_

#include "ASocketUDP.hh"

namespace Network
{
	/* La classe SocketUDPUnix d�finit les m�thodes des classes Socket UDP sp�cifiques � Unix. */
	class		SocketUDPUnix : public ASocketUDP {
	public:
		SocketUDPUnix();
		virtual ~SocketUDPUnix() {};
		/* La m�thode createIt() permet de cr�� une socket */
		bool		createIt();
		/* La m�thode bindIt(const uint32_t &) permet de bind le port du socket. */
		bool		bindIt(const uint32_t &);
		/* La m�thode listenIt(const uint32_t &) permet d'�couter sur le socket. */
		bool		listenIt(const uint32_t &)
		/* La m�thode getFdSocket() permet de r�cup�rer le descripteur de la socket. */
		int32_t		getFdSocket() const;
		/* La m�thode closeIt() permet de fermer la socket */
		bool		closeIt();
	private:
		SOCKET		_sock;
	};
};

#endif
