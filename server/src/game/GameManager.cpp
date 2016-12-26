//
// GameManager.cpp for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:44:47 2016 Maxime Lecoq
// Last update Mon Dec 26 17:07:28 2016 lecoq
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
