#ifndef		__MANAGENETWORKTCP_HH__
#define		__MANAGENETWORKTCP_HH__

#include	"AManageNetwork.hh"
#include	"ErrorSocket.hpp"

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
  class		ManageNetworkTCP : public AManageNetwork {
  public:
    ManageNetworkTCP();
    ~ManageNetworkTCP();
    bool					init();
    bool					selectIt();
    std::vector<IUserNetwork *>			execClient();
    std::vector<IUserNetwork *>			execServer();
    bool					run();
    bool					run(const uint32_t &, const uint32_t &);
    bool					tryConnectClient(const uint32_t &, const std::string &);
    void					pushToServ(const std::string &);
  private:
    /* fd_read est un attribut contentant un descripteur de fichier de lecture. */
    fd_set					fd_read;
    /* fd_write est un attribut contentant un descripteur de fichier d'écriture. */
    fd_set					fd_write;
    /* _serv est un attribut permettant de reconnaire le serveur auquel le client est actuellement connecté.*/
    IUserNetwork				*_serv;
    /* _initServ est un attribut permettant de savoir si un client est connecté au serveur. */
    bool                                _initServ;
  };
};

#endif
