//
// ASocketTCP.hh for ASocketTCP.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _ASOCKETTCP_HH_
#define _ASOCKETTCP_HH_

#include "ISocket.hh"

namespace Network
{
	/* L'Abstract class ASocketTCP définit les méthodes des classes Socket TCP. */
	class		ASocketTCP : public ISocket {
	public:
		virtual ~ASocketTCP() {};
		/* La méthode createIt() permet de créé une socket */
		virtual bool		createIt() = 0;
		/* La méthode bindIt(const uint32_t &) permet de bind le port du socket. */
		virtual bool		bindIt(const uint32_t &) = 0;
		/* La méthode listenIt(const uint32_t &) permet d'écouter sur le socket. */
		virtual bool		listenIt(const uint32_t &) = 0;
		/* La méthode acceptClient(DataClient &) permet d'accepter un client.. */
		virtual bool		acceptClient(DataClient &) = 0;
		/* La méthode connectIt(const std::string &, const uint32_t &) permet connecter un socket à un autre socket. */
		virtual bool		connectIt(const std::string &, const uint32_t &) = 0;
		/* La méthode getFdSocket() permet de récupérer le descripteur de la socket. */
		virtual int32_t		getFdSocket() const = 0;
		/* La méthode closeIt() permet de fermer la socket */
		virtual bool		closeIt() = 0;
	};
};

#endif
