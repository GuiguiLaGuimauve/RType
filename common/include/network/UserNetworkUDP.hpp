//
// UserNetworkUDP.hh for UserNetworkUDP.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Tue Nov 15 01:48:30 2016 lecoq
//

#ifndef _USERNETWORKUDP_HPP_
#define _USERNETWORKUDP_HPP_

#include "AUserNetwork.hh"

namespace Network
{
	/*!
	en :UserNetworUDP defines the methods for UserNetwork classes using UDP socket.
	fr :L'Abstract UserNetworkUDP d�finit les m�thodes des classes UserNetwork utilisant une socket UDP.
	*/
	class		UserNetworkUDP : public AUserNetwork {
	public:
		UserNetworkUDP() : AUserNetwork() {};
		virtual ~UserNetworkUDP() {};
		/*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de r�cup�rer ce qui � �t� �cris de l'autre c�t� de la socket. */
		virtual IUserNetwork	*readSocket(ISocket *) = 0;
		/*! La methode writeSocket(ISocket *) permet d'�crire sur une socket. */
		virtual void			writeSocket(ISocket *) = 0;
		/*! La methode closeFd permet de fermer la socket du client. */
		virtual void			closeFd() = 0;
	};
};

#endif
