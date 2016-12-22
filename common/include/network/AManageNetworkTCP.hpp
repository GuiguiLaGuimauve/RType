//
// ManageNetworkTCP.hh for ManagerNetworkTCP in /home/dufren_b/teck3/rendu/CPP/RType/common/include/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Wed Dec 21 00:16:17 2016 julien dufrene
// Last update Thu Dec 22 23:35:22 2016 julien dufrene
//

#ifndef		__MANAGENETWORKTCP_HH__
#define		__MANAGENETWORKTCP_HH__

#include	"AManageNetwork.hh"

#ifdef _WIN32
	#include	"SocketTCPWindows.hh"
	#include	"SocketTCPWindowsClient.hh"
	#include	"UserNetworkTCPWindowsServer.hh"
	#include	"UserNetworkTCPWindowsClient.hh"
#else
	#include	"SocketTCPUnix.hh"
	#include	"SocketTCPUnixClient.hh"
	#include	"UserNetworkTCPUnixServer.hh"
	#include	"UserNetworkTCPUnixClient.hh"
#endif

namespace Network
{
  /*! L'abstraction de ManageNetworkTCP definit les méthodes utilisée par le manager TCP .*/
  class		AManageNetworkTCP : public AManageNetwork {
  public:
    AManageNetworkTCP() : AManageNetwork() {};
    virtual ~AManageNetworkTCP() {};
    virtual bool			init() = 0;
    virtual bool			selectIt() = 0;
    virtual std::vector<IUserNetwork *>	exec() = 0;
    virtual bool			run(const uint32_t & = 4242, const uint32_t & = 0) = 0;
    virtual IUserNetwork                *getRunning() const = 0;
    virtual void			pushTo(const std::vector<std::string> &, const PacketUnknown &) = 0;
    virtual std::vector<std::string>	updateUsers(const std::vector<IUserNetwork *> &p) = 0;
    bool				hasServerRunning() const
    {
      return (false);
    };
    bool				tryConnectClient(const uint32_t &p, const std::string &ip)
    {
      (void)p; (void)ip;
      return (false);
    }
    void				pushNewUser(IUserNetwork *u)
    {
      (void)u;
    }
  protected:
    /* fd_read est un attribut contentant un descripteur de fichier de lecture. */
    fd_set					fd_read;
    /* fd_write est un attribut contentant un descripteur de fichier d'écriture. */
    fd_set					fd_write;
    /* _sec est l'attribut qui défini le timeout du select en secondes. */
    int		                                _sec;
    /* _sec est l'attribut qui défini le timeout du select en micro secondes. */
    int			                        _usec;
  };
};

#endif
