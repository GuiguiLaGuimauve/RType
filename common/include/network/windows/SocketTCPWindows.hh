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
	/* La classe SocketTCPWindows d�finit les m�thodes des classes Socket TCP sp�cifiques � windows et aux serveurs. */
	class		SocketTCPWindows : public ASocketTCP {
	public:
		SocketTCPWindows();
		virtual ~SocketTCPWindows();
		/* La m�thode bindIt(const uint32_t &) permet de bind le port de la socket. */
		bool		bindIt(const uint32_t &);
		/* La m�thode listenIt(const uint32_t &) permet d'�couter sur la socket. */
		bool		listenIt(const uint32_t &);
		/* La m�thode acceptClient(DataClient &) permet d'accepter une connexion */
		bool		acceptClient(DataClient &d);
		/* La m�thode connectIt(const std::string &, const uint32_t &) ne doit pas �tre utilis�e avec un objet de cette classe. */
		virtual bool		connectIt(const std::string &ip, const uint32_t &port)
		{
			(void)ip; (void)port;
			return (false);
		}
		/* La m�thode getFdSocket() permet de r�cup�rer le descripteur de la socket. */
		int32_t		getFdSocket() const;
		/* La m�thode closeIt() permet de fermer la socket */
		bool		closeIt();
	protected:
		SOCKET		_sock;
	};
};

#endif