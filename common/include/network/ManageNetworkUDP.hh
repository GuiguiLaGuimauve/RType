//
// ManageNetworkUDP.hh for ManageNetworkUDP in /home/dufren_b/teck3/rendu/CPP/RType/common/include/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:43:03 2016 julien dufrene
// Last update Fri Dec 16 11:57:43 2016 lecoq
//

#ifndef		__MANAGENETWORKUDP_HH__
#define		__MANAGENETWORKUDP_HH__

#include	"AManageNetwork.hh"
#include	"ErrorSocket.hpp"

#ifdef _WIN32
	#include	"SocketUDPWindows.hh"
	#include	"UserNetworkUDPWindows.hh"
#else
	#include	"SocketUDPUnix.hh"
	#include	"UserNetworkUDPUnix.hh"
#endif

namespace Network
{
  /*! L'abstraction de ManageNetworkUDP definit les méthodes utilisée par le manager UDP. */
  class		ManageNetworkUDP : public AManageNetwork {
  public:
    ManageNetworkUDP();
    ~ManageNetworkUDP();
    bool				init();
    bool				select_it();
    std::vector<IUserNetwork *>		execClient();
    std::vector<IUserNetwork *>		execServer();
    bool				run();
    bool				run(const uint32_t &, const uint32_t &);
    bool				tryConnectClient(const uint32_t &, const std::string &);
    void				pushToServ(const std::string &);
  private:
    /* _serv est un attribut permettant de reconnaire le serveur auquel le client est actuellement connecté.*/
    IUserNetwork			*_serv;
    /* _initServ est un attribut permettant de savoir si un client est connecté au serveur. */
    bool				_initServ;
  };
};

#endif
