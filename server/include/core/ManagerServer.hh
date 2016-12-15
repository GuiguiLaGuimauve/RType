//
// ManagerServer.hh for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Thu Dec 15 10:40:09 2016 lecoq
//

#ifndef MANAGERSERVER_HH_
# define MANAGERSERER_HH_

# include "IManagerServer.hh"

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
  IPacketManager	*getPacketanager() const;
private:
  IManager		*_man;
  IGameManager		*_game;
  IPacketManager	*_pkt;
  bool			_isSet;
};

#endif /* !MANAGER_HH_ */
