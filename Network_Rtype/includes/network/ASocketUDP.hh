//
// ASocketUDP.hh for ASocketUDP.hh in /home/dufren_b/teck3/rendu/CPP/RType
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Oct 14 11:25:14 2016 julien dufrene
// Last update Mon Nov 14 09:47:18 2016 lecoq
//

#ifndef _ASOCKETUDP_HH_
#define _ASOCKETUDP_HH_

#include "ISocket.hh"

namespace Network
{
	/* L'Abstract class ASocketUDP définit les méthodes des classes Socket UDP. */
	class		ASocketUDP : public ISocket {
	public:
		ASocketUDP() {};
		virtual ~ASocketUDP() {};
		/* La méthode bindIt(const uint32_t &) permet de bind le port du socket. */
		virtual bool		bindIt(const uint32_t &) = 0;
		/* La méthode listenIt(const uint32_t &) ne doit pas être utilisée avec une socketUDP */
		virtual bool		listenIt(const uint32_t &n)
		{
			(void)n;
			return (false);
		}
		/* La méthode acceptClient(DataClient &) ne doit pas être utilisée avec une socketUDP */
		virtual bool		acceptClient(DataClient &d)
		{
			(void)d;
			return (false);
		};
		/* La méthode connectIt(const std::string &, const uint32_t &) ne doit pas être utilisée avec une socketUDP. */
		virtual bool		connectIt(const std::string &ip, const uint32_t &port)
		{
			(void)ip; (void)port;
			return (false);
		};
		/* La méthode getFdSocket() permet de récupérer le descripteur de la socket. */
		virtual int32_t		getFdSocket() const = 0;
		/* La méthode closeIt() permet de fermer la socket */
		virtual bool		closeIt() = 0;
	};
};

#endif
