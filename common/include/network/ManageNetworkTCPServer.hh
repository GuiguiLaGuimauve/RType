//
// ManageNetworkTCPServer.hh for ManageNetworkTCPServer in /home/dufren_b/teck3/rendu/CPP/RType/common/include/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Wed Dec 21 00:16:00 2016 julien dufrene
// Last update Wed Dec 21 03:03:49 2016 julien dufrene
//

#ifndef		__MANAGENETWORKTCPSERVER_HH__
#define		__MANAGENETWORKTCPSERVER_HH__

#include	"AManageNetworkTCP.hpp"

namespace Network
{
  /*! L'abstraction de ManageNetworkTCPServer definit les méthodes utilisées par le managerTCP côté Serveur.*/
  class		ManageNetworkTCPServer : public AManageNetworkTCP {
  public:
    ManageNetworkTCPServer();
    virtual ~ManageNetworkTCPServer();
    bool			init();
    bool			selectIt();
    std::vector<IUserNetwork *>	exec();
    bool			run(const uint32_t &, const uint32_t & = 0);
    void                        pushTo(const std::vector<std::string> &, const PacketUnknown &);
    std::vector<std::string>	updateUsers(const std::vector<IUserNetwork *> &);
  };
};

#endif
