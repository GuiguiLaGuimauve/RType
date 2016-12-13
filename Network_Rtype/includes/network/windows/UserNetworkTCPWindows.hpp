//
// UserNetworkTCPWindows.hh for UserNetworkTCPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Tue Nov 15 01:48:30 2016 lecoq
//

#ifndef _USERNETWORKTCPWINDOWS_HPP_
#define _USERNETWORKTCPWINDOWS_HPP_

#include "UserNetworkTCP.hpp"

namespace Network
{
	/*!
	en :UserNetworTCPWindows defines the methods for UserNetworkTCP classes on windows.
	fr :La classe UserNetworkTCPWindows d�finit les m�thodes des classes UserNetworkTCP utilisant l'api Windows.
	*/
	class		UserNetworkTCPWindows : public UserNetworkTCP {
	public:
		UserNetworkTCPWindows() : UserNetworkTCP() {};
		virtual ~UserNetworkTCPWindows() {};
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
		virtual IUserNetwork	*readSocket(ISocket *) = 0;
		/*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
		virtual void			writeSocket(ISocket *) = 0;
		/*! La methode closeFd permet de fermer la socket du client. */
		void					closeFd()
		{
			if (_fd != -1)
			{
				std::cout << "Closing socket: " << _fd << std::endl;
				closesocket(_fd);
			}
		};
	};
};

#endif
