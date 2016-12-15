//
// SocketTCPWindows.hh for SocketTCPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _SocketTCPWindowsClient_HH_
#define _SocketTCPWindowsClient_HH_

#include "SocketTCPWindows.hh"

namespace Network
{
	/* La classe SocketTCPWindowsClient définit les méthodes de la classe SocketTCPWindows spécifiques aux clients. */
	class		SocketTCPWindowsClient : public SocketTCPWindows {
	public:
		SocketTCPWindowsClient();
		virtual ~SocketTCPWindowsClient();
		/* La méthode connectIt(const std::string &, const uint32_t &) permet de se connecter sur une socket TCP. */
		bool		connectIt(const std::string &ip, const uint32_t &port);
	};
};

#endif
