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
	fr :La classe UserNetworkTCPWindowsServer d�finit les m�thodes des classes UserNetworkTCPWindows sp�cialis�s pour les serveurs.
	*/
	class		UserNetworkTCPWindowsServer : public UserNetworkTCPWindows {
	public:
		UserNetworkTCPWindowsServer();
		virtual ~UserNetworkTCPWindowsServer();
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
		IUserNetwork	*readSocket(ISocket *);
		/*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
		void			writeSocket(ISocket *);
	};
};

#endif
