//
// UserNetworkUDPUnix.hh for UserNetworkUDPUnix.hh in /home/dufren_b/teck3/rendu/CPP/RType
//
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
//
// Started on  Fri Oct 21 14:44:09 2016 julien dufrene
// Last update Fri Dec 23 07:52:06 2016 julien dufrene
//

#ifndef _USERNETWORKUDPUNIX_HH_
#define _USERNETWORKUDPUNIX_HH_

#include "UserNetworkUDP.hpp"

namespace Network
{
  /*!
    en :UserNetworUDPUnix defines the methods for UserNetworkUDP classes on windows.
    fr :La classe UserNetworkUDPUnix définit les méthodes des classes UserNetworkUDP utilisant l'api Unix.
  */
  class		UserNetworkUDPUnix : public UserNetworkUDP {
  public:
    UserNetworkUDPUnix() {};
    virtual ~UserNetworkUDPUnix() {};
    /*! La methode readSocket(ISocket *) permet de lire sur une socket et donc de récupérer ce qui à été écris de l'autre côté de la socket. */
    virtual IUserNetwork	*readSocket(ISocket *) = 0;
    /*! La methode writeSocket(ISocket *) permet d'écrire sur une socket. */
    void			writeSocket(ISocket *net)
    {
		(void)net;
#ifndef _WIN32
      PacketUnknown         to_write;
      sockaddr_in           s_out;

      s_out.sin_addr.s_addr = inet_addr(_ip.c_str());
      s_out.sin_family = AF_INET;
      s_out.sin_port = htons(_port);
      to_write = buff_w.pop();
      std::cout << "Trying to send to: " << _ip << ":" << _port << std::endl;
      errno = 0;
      if (sendto(_fd, to_write.getPacketData(), to_write.getPacketSize(), 0, (sockaddr *)&s_out, sizeof (s_out)) == -1)
        {
		perror("sendto");
		std::cerr << "Error on sendto(): " << errno << std::endl;
		}
#else
	  std::cerr << "Using Windows function" << std::endl;
#endif
    };
    /*! La methode closeFd permet de fermer la socket du client. */
    void			closeFd()
    {
	#ifndef _WIN32
      if (getStatus() == true)
	{
	  std::cout << "Closing socket " << _fd << std::endl;
	  close(_fd);
	  setStatus(false);
	  _fd = -1;
	}
	#else
	std::cerr << "Using Windows function" << std::endl;
	#endif
    };
  };
};

#endif