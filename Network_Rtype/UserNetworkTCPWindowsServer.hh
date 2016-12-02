//
// UserNetworkTCPWindowsServer.hh for UserNetworkTCPWindowsServer.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Tue Nov 15 01:48:30 2016 lecoq
//

#ifndef _USERNETWORKTCPWINDOWSSERVER_HH_
#define _USERNETWORKTCPWINDOWSSERVER_HH_

#include "UserNetworkTCPWindows.hh"

namespace Network
{
	/*!
	en :UserNetworTCPWindowsServer defines the methods for UserNetworkTCPWindows classes specialized for server.
	fr :La classe UserNetworkTCPWindowsServer définit les méthodes des classes UserNetworkTCPWindows spécialisés pour les serveurs.
	*/
	class		UserNetworkTCPWindowsServer : public UserNetworkTCPWindows {
	public:
		UserNetworkTCPWindowsServer();
		virtual ~UserNetworkTCPWindowsServer();
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
		IUserNetwork	*readSocket(ISocket *);
		/*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
		void			writeSocket(ISocket *);
	};
};

#endif
