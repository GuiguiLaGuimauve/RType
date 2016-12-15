//
// IManager.hh for IManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:44:58 2016 Maxime Lecoq
// Last update Thu Dec 15 15:32:56 2016 lecoq
//

#ifndef IMANAGERSERVER_HH_
# define IMANAGERSERVER_HH_

# include "Manager.hh"
# include "GameManager.hh"
# include "ManagePacketServer.hh"

class IManagerServer : public IManager
{
public:
  virtual			~IManagerServer() {};
  virtual void			setManager() = 0;
  virtual IManageNetwork	*getNetworkTCPManager() const = 0;
  virtual IManageNetwork	*getNetworkUDPManager() const = 0;
  virtual void			deleteManager() = 0;
  virtual IGameManager		*getGameManager() const = 0;
  virtual IPacketManager	*getPacketManager() const = 0;
};

#endif /* !IMANAGER_HH_ */
