//
// ServerData.cpp for ServerData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Mon Dec 19 23:24:16 2016 Maxime Lecoq
// Last update Mon Dec 19 23:59:47 2016 lecoq
//

#include	"ServerData.hh"

ServerData::ServerData() {}

ServerData::~ServerData() {}

void	ServerData::addPlayer(const std::string &name, const std::string &pwd)
{
  if (name.empty() == true)
    return;
  DataPlayer	*player = new DataPlayer;

  player->setName(name);
  player->setPassword(pwd);
  _player.push_back(player);
}

DataPlayer	*ServerData::getPlayer(const std::string &name) const
{
  if (playerExist(name) == true)
    return (_player[getPlayerPos(name)]);
  return (NULL);
}

bool		ServerData::playerExist(const std::string &name) const
{
  uint64_t	i;

  i = 0;
  while (i < _player.size())
    {
      if (_player[i]->getName() == name)
	return (true);
      i++;
    }
  return (false);
}

uint64_t	ServerData::getPlayerPos(const std::string &name) const
{
  uint64_t	i;

  i = 0;
  while (i < _player.size())
    {
      if (_player[i]->getName() == name)
	return (i);
      i++;
    }
  return (i);
}

void	ServerData::addRoom(const std::string &name, const uint8_t &mPlayer)
{
  if (name.empty() == true && mPlayer != 0)
    return;
  uint8_t nbPlayer;
  
  if (mPlayer > 4)
    nbPlayer = 4;
  else
    nbPlayer = mPlayer;
  DataRoom	*room = new DataRoom;

  room->setName(name);
  room->setMaxPlayers(nbPlayer);
  _room.push_back(room);
}

DataRoom	*ServerData::getRoom(const std::string &name) const
{
  if (roomExist(name) == true)
    return (_room[getRoomPos(name)]);
  return (NULL);
}

bool		ServerData::roomExist(const std::string &name) const
{
  uint64_t	i;

  i = 0;
  while (i < _room.size())
    {
      if (_room[i]->getName() == name)
	return (true);
      i++;
    }
  return (false);
}

uint64_t		ServerData::getRoomPos(const std::string &name) const
{
  uint64_t	i;

  i = 0;
  while (i < _room.size())
    {
      if (_room[i]->getName() == name)
	return (i);
      i++;
    }
  return (i);
}
