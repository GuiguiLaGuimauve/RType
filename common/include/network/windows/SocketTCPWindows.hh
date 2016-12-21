//
// SocketTCPWindows.hh for SocketTCPWindows.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _SocketTCPWindows_HH_
#define _SocketTCPWindows_HH_

#include "ASocketTCP.hh"

namespace Network
{
	/* La classe SocketTCPWindows définit les méthodes des classes Socket TCP spécifiques à windows et aux serveurs. */
	class		SocketTCPWindows : public ASocketTCP {
	public:
		SocketTCPWindows();
		virtual ~SocketTCPWindows();
		/* La méthode bindIt(const uint32_t &) permet de bind le port de la socket. */
		bool		bindIt(const uint32_t &);
		/* La méthode listenIt(const uint32_t &) permet d'écouter sur la socket. */
		bool		listenIt(const uint32_t &);
		/* La méthode acceptClient(DataClient &) permet d'accepter une connexion */
		bool		acceptClient(DataClient &d);
		/* La méthode connectIt(const std::string &, const uint32_t &) ne doit pas être utilisée avec un objet de cette classe. */
		virtual bool		connectIt(const std::string &ip, const uint32_t &port)
		{
			(void)ip; (void)port;
			return (false);
		}
		/* La méthode getIpInfo() permet de récupérer l'ip de la socket */
		const std::string   getIpInfo() const;
		/* La méthode getFdSocket() permet de récupérer le descripteur de la socket. */
		int32_t		getFdSocket() const;
		/* La méthode closeIt() permet de fermer la socket */
		bool		closeIt();
	protected:
		SOCKET		_sock;
	};
};

#endif
