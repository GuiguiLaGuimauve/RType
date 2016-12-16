//
// ManagerServer.hh for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Fri Dec 16 11:22:07 2016 lecoq
//

#ifndef MANAGERSERVER_HH_
# define MANAGERSERER_HH_

# include "IManagerServer.hh"
# include "IPacketManager.hh"
# include "ErrorServer.hpp"

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
private:
  IManager		*_man;
  IGameManager		*_game;
  IPacketManager	*_pkt;
  bool			_isSet;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
};

#endif /* !MANAGER_HH_ */
