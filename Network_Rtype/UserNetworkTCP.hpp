//
// UserNetworkTCP.hh for UserNetworkTCP.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Tue Nov 15 01:48:30 2016 lecoq
//

#ifndef _USERNETWORKTCP_HH_
#define _USERNETWORKTCP_HH_

#include "AUserNetwork.hh"

namespace Network
{
	/*!
	en :UserNetworkUDP defines the methods for UserNetwork classes using UDP socket.
	fr :L'Abstract UserNetworkUDP définit les méthodes des classes UserNetwork utilisant les socket UDP.
	*/
	class		UserNetworkTCP : public AUserNetwork {
	public:
		UserNetworkTCP() : AUserNetwork() {};
		virtual ~UserNetworkTCP() {};
		/*! La methode readSocket(INetowork *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
		virtual IUserNetwork	*readSocket(ISocket *) = 0;
		/*! La methode writeSocket(INetwork *) permet d'écrire sur une socket. */
		virtual void			writeSocket(ISocket *) = 0;
		/*! La methode closeFd permet de fermer la socket du client. */
		virtual void					closeFd() = 0;
	};
};

#endif
