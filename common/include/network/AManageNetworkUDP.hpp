//
// ManageNetworkUDP.hh for ManageNetworkUDP in /home/dufren_b/teck3/rendu/CPP/RType/common/include/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:43:03 2016 julien dufrene
// Last update Wed Dec 21 06:45:56 2016 julien dufrene
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
  class		AManageNetworkUDP : public AManageNetwork {
  public:
    AManageNetworkUDP() {};
    virtual ~AManageNetworkUDP() {};
    virtual bool			init() = 0;
    virtual bool			selectIt() = 0;
    virtual std::vector<IUserNetwork *>	exec() = 0;
    virtual bool			run(const uint32_t & = 4242, const uint32_t & = 0) = 0;
    virtual bool			tryConnectClient(const uint32_t &, const std::string &) = 0;
    virtual void			pushTo(const std::vector<std::string> &, const PacketUnknown &) = 0;
    IUserNetwork	                *getServerRunning() const
    {
      return (NULL);
    };
    bool                                hasServerRunning() const
    {
      return (false);
    };
    std::vector<std::string>            updateUsers(const std::vector<IUserNetwork *> &p)
    {
      std::vector<std::string>  res;
      (void)p;
      return (res);
    };
  };
};

#endif
