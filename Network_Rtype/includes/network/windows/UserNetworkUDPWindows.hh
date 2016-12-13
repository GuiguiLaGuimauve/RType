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
	fr :La classe UserNetworkUDPWindows définit les méthodes des classes UserNetworkUDP utilisant l'api Windows.
	*/
	class		UserNetworkUDPWindows : public UserNetworkUDP {
	public:
		UserNetworkUDPWindows();
		virtual ~UserNetworkUDPWindows();
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
		IUserNetwork	*readSocket(ISocket *);
		/*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
		void			writeSocket(ISocket *);
		/*! La methode closeFd permet de fermer la socket du client. */
		void			closeFd();
	};
};

#endif
