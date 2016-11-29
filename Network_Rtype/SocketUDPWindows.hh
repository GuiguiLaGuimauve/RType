//
// SocketUDPWindows.hh for SocketUDPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _SocketUDPWindows_HH_
#define _SocketUDPWindows_HH_

#include "ASocketUDP.hh"

namespace Network
{
	/* La classe SocketUDPWindows définit les méthodes des classes Socket UDP spécifiques à windows. */
	class		SocketUDPWindows : public ASocketUDP {
	public:
		SocketUDPWindows();
		virtual ~SocketUDPWindows() {};
		/* La méthode createIt() permet de créé une socket */
		bool		createIt();
		/* La méthode bindIt(const uint32_t &) permet de bind le port du socket. */
		bool		bindIt(const uint32_t &);
		/* La méthode listenIt(const uint32_t &) permet d'écouter sur le socket. */
		bool		listenIt(const uint32_t &)
		/* La méthode getFdSocket() permet de récupérer le descripteur de la socket. */
		int32_t		getFdSocket() const;
		/* La méthode closeIt() permet de fermer la socket */
		bool		closeIt();
	private:
		SOCKET		_sock;
	};
};

#endif
