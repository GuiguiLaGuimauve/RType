//
// AManageNetwork.hpp for AManageNetwork in /home/dufren_b/teck3/rendu/CPP/RType/common
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:41:23 2016 julien dufrene
// Last update Fri Dec 16 12:06:24 2016 lecoq
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
    virtual bool				select_it() = 0;
    virtual std::vector<IUserNetwork *>		execClient() = 0;
    virtual std::vector<IUserNetwork *>		execServer() = 0;
    virtual bool				run() = 0;
    virtual bool				run(const uint32_t &, const uint32_t &) = 0;
    virtual bool				tryConnectClient(const uint32_t &, const std::string &) = 0;
    virtual void				pushToServ(const std::string &) = 0;
    uint32_t					getMaxFd() const;
    ISocket					*getSocket() const;
    void					updateUsers(const std::vector<IUserNetwork *> &);
  protected:
    /* _user est un attribut qui contient la liste des utilisateurs du serveur. */
    std::vector<IUserNetwork *>		_user;
    /* _net est un attribut socket du serveur. */
    ISocket				*_net;
    /* _port est un attribut contenant le port du serveur. */
    uint32_t				_port;
    /* _init est un attribut permettant de savoir si le core à été lancer en tant que serveur/client ou aucun des deux. */
    bool				_init;
  };
};

#endif
