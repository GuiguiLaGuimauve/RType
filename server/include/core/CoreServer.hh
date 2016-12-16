//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Fri Dec 16 11:23:15 2016 lecoq
//

#ifndef CORESERVER_HH_
# define CORESERVER_HH_

# include "ACore.hh"
# include "ManagerServer.hh"

using namespace Network;
using namespace Error;

class CoreServer : public ACore
{
  public:
  CoreServer();
  ~CoreServer();
  void		run();
  bool		initManager();
  void		deleteManager();
private:
  IManagerServer *_manager;
  IGameManager	*_gameManager;
};

#endif /* !CORESERVER_HH_ */
