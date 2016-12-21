//
// ManagerServer.hh for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Wed Dec 21 02:34:31 2016 julien dufrene
//

#ifndef MANAGERSERVER_HH_
# define MANAGERSERER_HH_

# include "IManagerServer.hh"
# include "IPacketManager.hh"
# include "ErrorServer.hpp"
# include "ManageNetworkTCPServer.hh"
# include "ManageNetworkUDPServer.hh"

using namespace Network;
using namespace Error;

class ManagerServer : public IManagerServer
{
public:
  ManagerServer();
  ~ManagerServer();
  void                  setManager();
  IManageNetwork        *getNetworkTCPManager() const;
  IManageNetwork        *getNetworkUDPManager() const;
  void                  deleteManager();
  IGameManager		*getGameManager() const;
  IPacketManager	*getPacketManager() const;
  ServerData            *getServerData() const; 
private:
  IGameManager		*_game;
  IPacketManager	*_pkt;
  bool			_isSet;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  ServerData		*_data;
};

#endif /* !MANAGER_HH_ */
