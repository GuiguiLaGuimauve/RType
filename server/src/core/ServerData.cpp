//
// ServerData.cpp for ServerData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Mon Dec 19 23:24:16 2016 Maxime Lecoq
// Last update Tue Dec 20 22:35:58 2016 julien dufrene
//

#include	"ServerData.hh"

ServerData::ServerData() : _isUpdate(false)
{
  if (_conf.findSomething() == true)
    {
      if (_conf.query() == true)
	_player = _conf.getPlayers();
      _conf.reset();
    }
  _isRunning = true;
  _thread = new mythrd::Thread(&ServerData::save, this);
}

void	        ServerData::save()
{
  while (_isRunning == true)
    {
      _conf.write(_player);
      _thread->pause(2);
    }
  std::cout << "End of saving thread" << std::endl; 
}

ServerData::~ServerData()
{
  uint64_t	i;

  i = 0;
  _isRunning = false;
  _thread->join();
  while (i < _player.size())
    delete _player[i++];
  i = 0;
  while (i < _room.size())
    delete _room[i++];
}

bool	ServerData::loginPlayer(const std::string &name, const std::string &pwd)
{
  if (name.empty() == true || pwd.empty() == true || playerExist(name) == false)
    return (false);
  DataPlayer	*player = getPlayer(name);

  if (player->getPassword() == pwd && player->getOnline() == false)
    {
      player->setOnline(true);
      std::cout << name << " just login" << std::endl;
      return (true);
    }
  else
    return (false);
}

bool	ServerData::registerPlayer(const std::string &name, const std::string &pwd)
{
  StringCk	st;
  
  if (name.empty() == true || pwd.empty() == true || playerExist(name) == true || playerExist(st.lower(name)) == true)
    return (false);
  DataPlayer	*player = new DataPlayer;

  player->setName(name);
  player->setPassword(pwd);
  player->setOnline(true);
  _player.push_back(player);
  std::cout << name << " just register" << std::endl;
  return (true);
}

void	ServerData::logoutPlayer(const std::string &name)
{
  if (playerExist(name) == true)
    {
      std::cout << name << " just logout" << std::endl;
      if (playerAlreadyInRoom(name) == true)
	{
	  deletePlayerOfRoom(name);
	  _isUpdate = true;
	}
      getPlayer(name)->setOnline(false);
    }
}

void	ServerData::logout(const std::vector<std::string> &list)
{
  uint64_t	i;

  i = 0;
  while (i < list.size())
    {
      logoutPlayer(list[i]);
      i++;
    }
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
  StringCk	st;
  
  i = 0;
  while (i < _player.size())
    {
      if (st.lower(_player[i]->getName()) == st.lower(name))
	return (true);
      i++;
    }
  return (false);
}

uint64_t	ServerData::getPlayerPos(const std::string &name) const
{
  uint64_t	i;
  StringCk	st;
  
  i = 0;
  while (i < _player.size())
    {
      if (st.lower(_player[i]->getName()) == st.lower(name))
	return (i);
      i++;
    }
  return (i);
}

bool	ServerData::createRoom(const std::string &name, const uint8_t &mPlayer, const std::string &player)
{
  StringCk	st;
  
  std::cout << "try createRoom" << std::endl;
  if (name.empty() == true || mPlayer == 0 || playerExist(player) == false || roomExist(name) == true || roomExist(st.lower(name)) == true)
    return (false);
  uint8_t nbPlayer;
  
  if (mPlayer > 4)
    nbPlayer = 4;
  else
    nbPlayer = mPlayer;
  DataRoom	*room = new DataRoom;
  std::vector<DataPlayer *> playerList;

  playerList.push_back(getPlayer(player));
  room->setName(name);
  room->setMaxPlayers(nbPlayer);
  room->setPlayers(playerList);
  _room.push_back(room);
  _isUpdate = true;
  std::cout << "room : " << name << " crée par : " << player << std::endl;
  return (true);
}

bool	ServerData::joinRoom(const std::string &roomName, const std::string &playerName)
{
  if (roomExist(roomName) == false || playerExist(playerName) == false || playerAlreadyInRoom(playerName) == true)
    return (false);
  DataRoom	*room = getRoom(roomName);
  DataPlayer	*player = getPlayer(playerName);
  std::vector<DataPlayer *> pl = room->getPlayers();

  pl.push_back(player);
  room->setPlayers(pl);
  _isUpdate = true;
  std::cout << "room : " << roomName << " rejointe par : " << playerName << std::endl;
  return (true);
}

bool	ServerData::watchGame(const std::string &roomName, const std::string &playerName)
{
  if (roomExist(roomName) == false || playerExist(playerName) == false || playerAlreadyInRoom(playerName) == true)
    return (false);
  DataRoom	*room = getRoom(roomName);
  DataPlayer	*player = getPlayer(playerName);
  std::vector<DataPlayer *> pl = room->getWatchers();

  pl.push_back(player);
  room->setWatchers(pl);
  _isUpdate = true;
  return (true);
}

bool	ServerData::leaveRoom(const std::string &roomName, const std::string &playerName)
{
  if (roomExist(roomName) == false || playerExist(playerName) == false || playerInRoom(playerName, getRoom(roomName)) == false)
    return (false);
  deletePlayerInRoom(playerName, getRoom(roomName));
  std::cout << playerName << " a quitter la room : " << roomName << std::endl;
  _isUpdate = true;
  return (true);
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
  StringCk	st;
  
  i = 0;
  while (i < _room.size())
    {
      if (st.lower(_room[i]->getName()) == st.lower(name))
	return (true);
      i++;
    }
  return (false);
}

uint64_t		ServerData::getRoomPos(const std::string &name) const
{
  uint64_t	i;
  StringCk	st;
  
  i = 0;
  while (i < _room.size())
    {
      if (st.lower(_room[i]->getName()) == st.lower(name))
	return (i);
      i++;
    }
  return (i);
}

bool			ServerData::playerInRoom(const std::string &player, const DataRoom *room)
{
  uint64_t		i;

  i = 0;
  while (i < room->getPlayers().size())
    {
      if (room->getPlayers()[i]->getName() == player)
	return (true);
      i++;
    }
  i = 0;
  while (i < room->getWatchers().size())
    {
      if (room->getWatchers()[i]->getName() == player)
	return (true);
      i++;
    }
  return (false);
}

bool			ServerData::playerAlreadyInRoom(const std::string &player)
{
  if (playerExist(player) == false || getPlayer(player)->getOnline() == false)
    return (false);
  uint64_t	i;

  i = 0;
  while (i < _room.size())
    {
      if (playerInRoom(player, _room[i]) == true)
	return (true);
      i++;
    }
  return (false);
}

bool			ServerData::deletePlayerInRoom(const std::string &player, DataRoom *room)
{
  uint64_t		i;
  std::vector<DataPlayer *> pl = room->getPlayers();
  
  i = 0;
  while (i < pl.size())
    {
      if (pl[i]->getName() == player)
	{
	  pl.erase(pl.begin() + i);
	  room->setPlayers(pl);
	  return (true);
	}
      i++;
    }
  pl = room->getWatchers();
  
  i = 0;
  while (i < pl.size())
    {
      if (pl[i]->getName() == player)
	{
	  pl.erase(pl.begin() + i);
	  room->setWatchers(pl);
	  return (true);
	}
      i++;
    }
  return (false);
}

void			ServerData::deletePlayerOfRoom(const std::string &player)
{
  uint64_t	i;

  i = 0;
  while (i < _room.size())
    {
      if (deletePlayerInRoom(player, _room[i]) == true)
	{
	  if (_room[i]->getPlayers().size() == 0)
	    {
	      std::cout << _room[i]->getName() << " room's just delete" << std::endl;
	      _room.erase(_room.begin() + i);
	    }
	  return;
	}
      i++;
    }
}

bool			ServerData::roomAreUpdate() const
{
  return (_isUpdate);
}

std::vector<DataRoom *>	ServerData::getRooms()
{
  _isUpdate = false;
  return (_room);
}

std::vector<std::string> ServerData::getOnlineClients() const
{
  std::vector<std::string> ret;
  uint64_t		i;

  i = 0;
  while (i < _player.size())
    {
      if (_player[i]->getOnline() == true)
	ret.push_back(_player[i]->getName());
      i++;
    }
  return (ret);
}
