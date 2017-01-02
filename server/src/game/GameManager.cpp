//
// GameManager.cpp for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:44:47 2016 Maxime Lecoq
// Last update Mon Jan  2 13:34:40 2017 Lecoq Maxime
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
      room->getPlayers()[i]->setTick(0);
      pb = _factory->getPacket("positionplayer", 200, 200 + (i * 200));
      tmp.push_back(room->getPlayers()[i]->getName());
      _tcp->pushTo(tmp, pb->getPacketUnknown());
      tmp.clear();
      delete pb;
      i++;
    }
  newGame->addThread(_threadPool->launchTask(&GameManager::runGame, this, newGame));
  newGame->addThread(_threadPool->launchTask(&GameManager::runTimeline, this, newGame));
  newGame->addThread(_threadPool->launchTask(&GameManager::runMovements, this, newGame));
  newGame->addThread(_threadPool->launchTask(&GameManager::popMonster, this, newGame));
  newGame->addThread(_threadPool->launchTask(&GameManager::popBackground, this, newGame));
}

bool          GameManager::gamesUpdate()
{
  uint64_t	i;

  i = 0;
  while (i < _gameList.size())
    {
      if (_gameList[i]->getPlayersName().size() == 0
	  || _gameList[i]->isWin() == true || _gameList[i]->isLoose() == true)
	{
	  IPacket	*p = _factory->getPacket("gameended");
	  _tcp->pushTo(_gameList[i]->getAllName(), p->getPacketUnknown());
	  delete p;

	  /*if (_gameList[i]->isWin() == true)
	  tous les players dedans on leur envoie un packet winnnnnnnnn
	  else
if (_gameList[i]->isLoose() == true)
//tous les players dedans 
edit gameended avec un 1/0 pour un */
	  _gameList[i]->end();
	  _gameList.erase(_gameList.begin() + i);
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
