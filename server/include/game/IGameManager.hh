//
// IGameManager.hh for IGameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:46:33 2016 Maxime Lecoq
// Last update Mon Jan  2 19:53:19 2017 Lecoq Maxime
//

#ifndef IGAMEMANAGER_HH_
# define IGAMEMANAGER_HH_

# include	"Game.hh"
# include	"PacketFactory.hh"
# include       "IManageNetwork.hh"
# include	"ThreadPool.hpp"
# include	"ServerData.hh"

using namespace Network;

class		IGameManager
{
public:
  virtual ~IGameManager() {};
  virtual void createGame(DataRoom *, const uint8_t *) = 0;
  virtual void setFactory(PacketFactory *) = 0;
  virtual void          setTcp(IManageNetwork *) = 0;
  virtual void          setUdp(IManageNetwork *) = 0;
  virtual void          setThreadPool(ThreadPool *) = 0;
  virtual void		runTimeline(IGame *) = 0;
  virtual void		runMovements(IGame *) = 0;
  virtual void		runGame(IGame *) = 0;
  virtual bool		gamesUpdate() = 0;
  virtual bool		execPacket(const IPacket *, const std::string &) = 0;
  virtual void          popMonster(IGame *) = 0;
  virtual void          popBackground(IGame *) = 0;
  virtual void		setData(ServerData *) = 0;
};

#endif /* !IGAMEMANAGER_HH_ */
