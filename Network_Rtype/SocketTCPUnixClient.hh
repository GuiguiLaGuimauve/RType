//
// SocketTCPUnix.hh for SocketTCPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _SocketTCPUnixClient_HH_
#define _SocketTCPUnixClient_HH_

#include "SocketTCPUnix.hh"

namespace Network
{
	/* La classe SocketTCPUnixClient définit les méthodes de la classe SocketTCPUnix spécifiques aux clients. */
	class		SocketTCPUnixClient : public SocketTCPUnix {
	public:
		SocketTCPUnixClient();
		virtual ~SocketTCPUnixClient() {};
		/* La méthode connectIt(const std::string &, const uint32_t &) permet de se connecter sur une socket TCP. */
		bool		connectIt(const std::string &ip, const uint32_t &port);
	};
};

#endif
