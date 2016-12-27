//
// GameManager.cpp for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:44:47 2016 Maxime Lecoq
// Last update Tue Dec 27 15:21:44 2016 lecoq
//

#include "GameManager.hh"

GameManager::GameManager() {}
GameManager::~GameManager() {}

void	GameManager::createGame(DataRoom *room, const uint8_t *ip)
{
  IPacket                       *pb;
  IGame *newGame = new Game(room);

  pb = _factory->getPacket("udpdata", ip, (uint16_t)4243);
  newGame->setFactory(_factory);
  newGame->setUdp(_udp);
  _gameList.push_back(newGame);
  _tcp->pushTo(newGame->getAllName(), pb->getPacketUnknown());
  newGame->run();
  delete pb; 
  _threadPool->launchTask(&GameManager::runTimeline, this, newGame);
}

bool          GameManager::gamesUpdate()
{
  uint64_t	i;

  i = 0;
  while (i < _gameList.size())
    {
      if (_gameList[i]->getPlayersName().size() == 0)
	{
	  //envoyer un signal de fin de partie aux viewers (all)
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

