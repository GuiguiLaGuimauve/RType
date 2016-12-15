#ifndef		__MANAGENETWORK_HH__
#define		__MANAGENETWORK_HH__

#include	<map>
#include	<vector>
#include	"IManageNetwork.hh"
#include	"ErrorSocket.hpp"
#ifdef _WIN32
		#include		"SocketTCPWindows.hh"
		#include		"SocketTCPWindowsClient.hh"
		#include		"UserNetworkTCPWindowsServer.hh"
		#include		"UserNetworkTCPWindowsClient.hh"
#else
		#include	"SocketTCPUnix.hh"
		#include	"SocketTCPUnixClient.hh"
		#include	"UserNetworkTCPUnixServer.hh"
		#include	"UserNetworkTCPUnixClient.hh"
#endif

namespace Network
{
  /*! L'abstraction de AManageNetwork definit les méthodes de ManageNetworkUnix et ManageNetworkWindows.*/
  class		ManageNetwork : public IManageNetwork {
  public:
    ManageNetwork();
    ~ManageNetwork();
    bool									init();
    bool									select_it();
    std::vector<IUserNetwork *>				execClient();
    std::vector<IUserNetwork *>				execServer();
    bool									run();
    bool									run(const uint32_t &, const uint32_t &);
    ISocket									*getSocket() const;
    bool									tryConnectClient(const uint32_t &, const std::string &);
	uint32_t								getMaxFd() const;
	void									updateUsers(std::vector<IUserNetwork *>);
	void									pushToServ(const std::string &);
  private:
    /* _user est un attribut qui contient la liste des utilisateurs du serveur. */
    std::vector<IUserNetwork *>		_user;
    /* _net est un attribut socket du serveur. */
    ISocket							*_net;
    /* _port est un attribut contenant le port du serveur. */
    uint32_t						_port;
    /* _maxCl est un attribut contenant le nombre maximum de client sur le serveur. */
//    uint32_t						_maxCl;
    /* _init est un attribut permettant de savoir si le core à été lancer en tant que serveur/client ou aucun des deux. */
    bool							_init;
	/* fd_read est un attribut contentant un descripteur de fichier de lecture. */
	fd_set							fd_read;
	/* fd_write est un attribut contentant un descripteur de fichier d'écriture. */
	fd_set							fd_write;
	/* _serv est un attribut permettant de reconnaire le serveur auquel le client est actuellement connecté. */
    IUserNetwork					*_serv;
	/* _initServ est un attribut permettant de savoir si un client est connecté au serveur. */
	bool							_initServ;
  };
};

#endif
