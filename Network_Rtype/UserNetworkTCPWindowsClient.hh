//
// UserNetworkTCPWindowsClient.hh for UserNetworkTCPWindowsClient.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Tue Nov 15 01:48:30 2016 lecoq
//

#ifndef _USERNETWORKTCPWINDOWSCLIENT_HH_
#define _USERNETWORKTCPWINDOWSCLIENT_HH_

#include "UserNetworkTCPWindows.hh"

namespace Network
{
	/*!
	en :UserNetworTCPWindowsClient defines the methods for UserNetworkTCPWindows classes specialized for Client.
	fr :La classe UserNetworkTCPWindowsClient définit les méthodes des classes UserNetworkTCPWindows spécialisés pour les clients.
	*/
	class		UserNetworkTCPWindowsClient : public UserNetworkTCPWindows {
	public:
		UserNetworkTCPWindowsClient();
		virtual ~UserNetworkTCPWindowsClient();
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
		IUserNetwork	*readSocket(ISocket *);
		/*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
		void			writeSocket(ISocket *);
	};
};

#endif
