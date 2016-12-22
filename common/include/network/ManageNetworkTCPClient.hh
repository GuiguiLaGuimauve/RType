//
// ManageNetworkTCPClient.hh for ManageNetworkTCPClient in /home/dufren_b/teck3/rendu/CPP/RType/common/include/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Wed Dec 21 00:15:36 2016 julien dufrene
// Last update Thu Dec 22 11:06:45 2016 julien dufrene
//

#ifndef		__MANAGENETWORKTCPCLIENT_HH__
#define		__MANAGENETWORKTCPCLIENT_HH__

#include	"AManageNetworkTCP.hpp"

namespace Network
{
  /*! L'abstraction de ManageNetworkTCPClient definit les méthodes utilisées par le managerTCP côté client.*/
  class		ManageNetworkTCPClient : public AManageNetworkTCP {
  public:
    ManageNetworkTCPClient();
    virtual ~ManageNetworkTCPClient();
    bool			init();
    bool			selectIt();
    std::vector<IUserNetwork *>	exec();
    bool			run(const uint32_t & = 4242, const uint32_t & = 0);
    bool			tryConnectClient(const uint32_t &, const std::string &);
    void			pushTo(const std::vector<std::string> &, const PacketUnknown &);
    bool			hasServerRunning() const;
    IUserNetwork                *getRunning() const;
  };
};

#endif
