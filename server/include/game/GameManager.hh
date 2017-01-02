//
// GameManager.hh for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:52:02 2016 Maxime Lecoq
// Last update Mon Jan  2 19:50:25 2017 Lecoq Maxime
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include	<vector>
# include	"IGameManager.hh"
# include	"DataRoom.hpp"
# include	"ThreadPool.hpp"
# include	"Printer.hpp"
# include	"ServerData.hh"

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
  void		runMovements(IGame *);
  void		runGame(IGame *);
  bool          gamesUpdate();
  bool          execPacket(const IPacket *, const std::string &);
  void		popMonster(IGame *);
  void		popBackground(IGame *);
  void		setData(ServerData *);
private:
  std::vector<IGame *>	_gameList;
  PacketFactory	*_factory;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  ThreadPool		*_threadPool;
  ServerData		*_data;
};

#endif /* !GAMEMANAGER_HH_ */
