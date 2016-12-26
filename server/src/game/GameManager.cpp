//
// GameManager.cpp for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:44:47 2016 Maxime Lecoq
// Last update Mon Dec 26 12:01:05 2016 lecoq
//

#include "GameManager.hh"

GameManager::GameManager() {}
GameManager::~GameManager() {}

void	GameManager::createGame(DataRoom *room, const uint8_t *ip)
{
  (void)ip;
  IGame *newGame = new Game(room);
  _gameList.push_back(newGame);
}

void	GameManager::setFactory(PacketFactory *f)
{
  _factory = f;
}
