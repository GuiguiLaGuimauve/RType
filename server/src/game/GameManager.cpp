//
// GameManager.cpp for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:44:47 2016 Maxime Lecoq
// Last update Sun Jan  1 19:24:49 2017 Lecoq Maxime
//

#include "GameManager.hh"

GameManager::GameManager() {}
GameManager::~GameManager() {}

void	GameManager::createGame(DataRoom *room, const uint8_t *ip)
{
  IPacket                       *pb;
  IGame *newGame = new Game(room);
  uint64_t			i;
  std::vector<std::string>	tmp;
  std::vector<DataShoot *>	reset;

  pb = _factory->getPacket("udpdata", ip, (uint16_t)4243, "player");
  newGame->setFactory(_factory);
  newGame->setUdp(_udp);
  _gameList.push_back(newGame);
  _tcp->pushTo(newGame->getPlayersName(), pb->getPacketUnknown());
  delete pb;
  pb = _factory->getPacket("udpdata", ip, (uint16_t)4243, "watcher");
  _tcp->pushTo(newGame->getViewersName(), pb->getPacketUnknown());
  delete pb;
  i = 0;
  while (i < room->getPlayers().size())
    {
      room->getPlayers()[i]->setGamePlayed(room->getPlayers()[i]->getGamePlayed() + 1);
      room->getPlayers()[i]->setId((uint8_t)i);
      room->getPlayers()[i]->setHealth(100);
      room->getPlayers()[i]->setX(100);
      room->getPlayers()[i]->setY(200 + (i * 200));
      room->getPlayers()[i]->setShoots(reset);
      pb = _factory->getPacket("positionplayer", 200, 200 + (i * 200));
      tmp.push_back(room->getPlayers()[i]->getName());
      _tcp->pushTo(tmp, pb->getPacketUnknown());
      tmp.clear();
      delete pb;
      i++;
    }
  _threadPool->launchTask(&GameManager::runGame, this, newGame);
  _threadPool->launchTask(&GameManager::runTimeline, this, newGame);
  _threadPool->launchTask(&GameManager::runMovements, this, newGame);
  _threadPool->launchTask(&GameManager::popMonster, this, newGame);
  _threadPool->launchTask(&GameManager::popBackground, this, newGame);
}

bool          GameManager::gamesUpdate()
{
  uint64_t	i;

  i = 0;
  while (i < _gameList.size())
    {
      if (_gameList[i]->getPlayersName().size() == 0)
	{
	  IPacket	*p = _factory->getPacket("gameended");
	  _tcp->pushTo(_gameList[i]->getAllName(), p->getPacketUnknown());
	  delete p;
	  _gameList[i]->end();
	  //	  delete _gameList[i];
	  _gameList.erase(_gameList.begin() + i);
	  std::cout << "la game est finis ca mere" << std::endl;
	}
      else
	i++;
    }
  return (true);
}

void	GameManager::popMonster(IGame *g)
{
  g->monster();
}

void	GameManager::popBackground(IGame *g)
{
  g->background();
}

void	GameManager::runGame(IGame *g)
{
  g->run();
}

void	GameManager::runTimeline(IGame *g)
{
  g->timeLine();
}

void	GameManager::runMovements(IGame *g)
{
  g->movements();
}

void	GameManager::setFactory(PacketFactory *f)
{
  _factory = f;
}

void	GameManager::setTcp(IManageNetwork *t) { _tcp = t; }

void	GameManager::setUdp(IManageNetwork *u) { _udp = u; }

void	GameManager::setThreadPool(ThreadPool *t) { _threadPool = t; }

bool	GameManager::execPacket(const IPacket *pa, const std::string &pl)
{
  uint64_t	i;
  
  i = 0;
  while (i < _gameList.size())
    {
      if (_gameList[i]->playerPresent(pl) == true)
	_gameList[i]->execPacket(pa, pl);
      i++;
    }
  return (true);
}
