//
// AManageNetwork.hpp for AManageNetwork in /home/dufren_b/teck3/rendu/CPP/RType/common
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:41:23 2016 julien dufrene
// Last update Tue Dec 20 04:04:25 2016 lecoq
//


#ifndef		__AMANAGENETWORK_HH__
#define		__AMANAGENETWORK_HH__

#include	<map>
#include	<vector>
#include	"IManageNetwork.hh"
#include	"IUserNetwork.hh"
#include	"ISocket.hh"

namespace Network
{
  /*! L'abstraction de AManageNetwork definit les méthodes de ManageNetworkUDP et ManageNetworkTCP.*/
  class		AManageNetwork : public IManageNetwork {
  public:
    AManageNetwork();
    ~AManageNetwork() {};
    virtual bool				init() = 0;
    virtual bool				selectIt() = 0;
    virtual std::vector<IUserNetwork *>		execClient() = 0;
    virtual std::vector<IUserNetwork *>		execServer() = 0;
    virtual bool				run() = 0;
    virtual bool				run(const uint32_t &, const uint32_t & = 0) = 0;
    virtual bool				tryConnectClient(const uint32_t &, const std::string &) = 0;
    void					pushToClients(const std::vector<std::string> &, const PacketUnknown &);
    virtual void				pushToServ(const PacketUnknown &) = 0;
    bool	                                hasServerRunning() const;
    uint32_t					getMaxFd() const;
    ISocket					*getSocket() const;
    std::vector<std::string>			updateUsers(const std::vector<IUserNetwork *> &);
    void				        setPacketQueueRead(const IPacketQueue *c) { _read = (IPacketQueue *)c; };
    void			                setPacketQueueWrite(const IPacketQueue *c){  _write = (IPacketQueue *)c; };
    void		                        setPacketFactory(const PacketFactory *c) { _factory = (PacketFactory *)c; };
  private:
    bool                                        inList(const std::string &, const std::vector<std::string> &);
  protected:
    /* _user est un attribut qui contient la liste des utilisateurs du serveur. */
    std::vector<IUserNetwork *>		_user;
    /* _net est un attribut socket du serveur. */
    ISocket				*_net;
    /* _port est un attribut contenant le port du serveur. */
    uint32_t				_port;
    /* _init est un attribut permettant de savoir si le core à été lancer en tant que serveur/client ou aucun des deux. */
    bool				_init;
    /* _serv est un attribut permettant de reconnaire le serveur auquel le client est actuellement connecté.*/
    IUserNetwork                                *_serv;
    /* _initServ est un attribut permettant de savoir si un client est connecté au serveur. */
    bool                                _initServ;
    IPacketQueue			*_read;
    IPacketQueue			*_write;
    PacketFactory			*_factory;
    int					_sec;
    int					_usec;
  };
};

#endif
