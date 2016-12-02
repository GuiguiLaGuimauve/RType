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
	fr :La classe UserNetworkTCPWindowsClient d�finit les m�thodes des classes UserNetworkTCPWindows sp�cialis�s pour les clients.
	*/
	class		UserNetworkTCPWindowsClient : public UserNetworkTCPWindows {
	public:
		UserNetworkTCPWindowsClient();
		virtual ~UserNetworkTCPWindowsClient();
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
		IUserNetwork	*readSocket(ISocket *);
		/*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
		void			writeSocket(ISocket *);
	};
};

#endif
