//
// GameManager.hh for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:52:02 2016 Maxime Lecoq
// Last update Mon Dec 26 17:04:37 2016 lecoq
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include	<vector>
# include	"IGameManager.hh"
# include	"DataRoom.hpp"
# include	"ThreadPool.hpp"

class GameManager : public IGameManager
{
public:
  GameManager();
  ~GameManager();
  void		createGame(DataRoom *, const uint8_t *);
  void		setFactory(PacketFactory *);
  void		setTcp(IManageNetwork *);
  void		setUdp(IManageNetwork *);
  void		setThreadPool(ThreadPool *);
  void		runTimeline(IGame *);
private:
  std::vector<IGame *>	_gameList;
  PacketFactory	*_factory;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  ThreadPool		*_threadPool;
};

#endif /* !GAMEMANAGER_HH_ */
