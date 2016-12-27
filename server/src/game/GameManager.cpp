//
// GameManager.cpp for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:44:47 2016 Maxime Lecoq
// Last update Tue Dec 27 18:27:31 2016 lecoq
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
  
  pb = _factory->getPacket("udpdata", ip, (uint16_t)4243);
  newGame->setFactory(_factory);
  newGame->setUdp(_udp);
  _gameList.push_back(newGame);
  _tcp->pushTo(newGame->getAllName(), pb->getPacketUnknown());
  delete pb; 
  _threadPool->launchTask(&GameManager::runTimeline, this, newGame);
  i = 0;
  while (i < room->getPlayers().size())
    {
      room->getPlayers()[i]->setGamePlayed(room->getPlayers()[i]->getGamePlayed() + 1);
      room->getPlayers()[i]->setId((uint8_t)i);
      room->getPlayers()[i]->setHealth(100);
      room->getPlayers()[i]->setX(100);
      room->getPlayers()[i]->setY(200 + (i * 200));
      pb = _factory->getPacket("positionplayer", 200, 200 + (i * 200));
      tmp.push_back(room->getPlayers()[i]->getName());
      _tcp->pushTo(tmp, pb->getPacketUnknown());
      tmp.clear();
      delete pb;
      i++;
    }
  newGame->run();
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
	  _gameList.erase(_gameList.begin() + i);
	}
      else
	i++;
    }
  return (true);
}

void	GameManager::runTimeline(IGame *g)
{
  g->timeLine();
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

