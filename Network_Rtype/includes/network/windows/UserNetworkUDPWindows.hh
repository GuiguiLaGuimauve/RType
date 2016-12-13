//
// UserNetworkUDPWindows.hh for UserNetworkUDPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Tue Nov 15 01:48:30 2016 lecoq
//

#ifndef _USERNETWORKUDPWINDOWS_HH_
#define _USERNETWORKUDPWINDOWS_HH_

#include "UserNetworkUDP.hpp"

namespace Network
{
	/*!
	en :UserNetworUDPWindows defines the methods for UserNetworkUDP classes on windows.
	fr :La classe UserNetworkUDPWindows d�finit les m�thodes des classes UserNetworkUDP utilisant l'api Windows.
	*/
	class		UserNetworkUDPWindows : public UserNetworkUDP {
	public:
		UserNetworkUDPWindows();
		virtual ~UserNetworkUDPWindows();
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
		IUserNetwork	*readSocket(ISocket *);
		/*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
		void			writeSocket(ISocket *);
		/*! La methode closeFd permet de fermer la socket du client. */
		void			closeFd();
	};
};

#endif
