//
// ManageNetworkUDP.hh for ManageNetworkUDP in /home/dufren_b/teck3/rendu/CPP/RType/common/include/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:43:03 2016 julien dufrene
// Last update Thu Dec 29 21:48:25 2016 lecoq
//

#ifndef		__MANAGENETWORKUDPSERVER_HH__
#define		__MANAGENETWORKUDPSERVER_HH__

#include	"AManageNetworkUDP.hpp"

namespace Network
{
  /*! L'abstraction de ManageNetworkUDP definit les méthodes utilisée par le manager UDP. */
  class		ManageNetworkUDPServer : public AManageNetworkUDP {
  public:
    ManageNetworkUDPServer();
    virtual ~ManageNetworkUDPServer();
    bool			init();
    bool			selectIt();
    std::vector<IUserNetwork *>	exec();
    bool			run(const uint32_t & = 4243, const uint32_t & = 0);
    bool			tryConnectClient(const uint32_t &, const std::string &);
    void			pushTo(const std::vector<std::string> &, const PacketUnknown &);
    IUserNetwork		*getRunning() const;
    std::vector<std::string>    updateUsers(const std::vector<IUserNetwork *> &);
private:
    mymtx::mutex		_mtx;
  };
};

#endif
