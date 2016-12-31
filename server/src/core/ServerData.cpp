/*
// ServerData.cpp for ServerData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Mon Dec 19 23:24:16 2016 Maxime Lecoq
// Last update Sat Dec 31 11:41:40 2016 Lecoq Maxime
*/

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
  _thread = new mythrd::Thread();
  _thread->launch(&ServerData::save, this);
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
  StringCk	st;
  Epur		ep;
  
  if (name.empty() == true || pwd.empty() == true || playerExist(st.lower(name)) == false
      || ep.epur(name, ' ').empty() == true || ep.epur(pwd, ' ').empty() == true)
    return (false);
  DataPlayer	*player = getPlayer(st.lower(name));
  Crypt		cr;
  
  if (player->getPassword() == cr._sha1(pwd) && player->getOnline() == false)
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
  Epur		ep;
  
  if (name.empty() == true || pwd.empty() == true || playerExist(st.lower(name)) == true
      || ep.epur(name, ' ').empty() == true || ep.epur(pwd, ' ').empty() == true)
    return (false);
  DataPlayer	*player = new DataPlayer;
  Crypt		cr;
  
  player->setName(name);
  player->setPassword(cr._sha1(pwd));
  player->setOnline(true);
  _player.push_back(player);
  std::cout << name << " just register" << std::endl;
  return (true);
}

void	ServerData::logoutPlayer(const std::string &name)
{
  StringCk	st;
  if (playerExist(st.lower(name)) == true)
    {
      std::cout << name << " just logout" << std::endl;
      if (playerAlreadyInRoom(st.lower(name)) == true)
	{
	  deletePlayerOfRoom(st.lower(name));
	  _isUpdate = true;
	}
      getPlayer(st.lower(name))->setOnline(false);
      getPlayer(st.lower(name))->resetGame();
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
  StringCk	st;
  if (playerExist(st.lower(name)) == true)
    return (_player[getPlayerPos(st.lower(name))]);
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
  
  if (name.empty() == true || mPlayer == 0 || playerExist(st.lower(player)) == false || roomExist(st.lower(name)) == true)
    return (false);
  deletePlayerOfRoom(st.lower(player));
  uint8_t nbPlayer;
  
  if (mPlayer > 4)
    nbPlayer = 4;
  else
    nbPlayer = mPlayer;
  DataRoom	*room = new DataRoom;
  std::vector<DataPlayer *> playerList;

  playerList.push_back(getPlayer(st.lower(player)));
  room->setName(name);
  room->setMaxPlayers(nbPlayer);
  room->setPlayers(playerList);
  _room.push_back(room);
  _isUpdate = true;
  std::cout << "room : [" << name << "] crée par : [" << player << "]" <<  std::endl;
  return (true);
}

bool	ServerData::joinRoom(const std::string &roomName, const std::string &playerName)
{
  StringCk	st;
  if (roomExist(st.lower(roomName)) == false || playerExist(st.lower(playerName)) == false)
    return (false);
  DataRoom	*room = getRoom(st.lower(roomName));
  if (room->getPlayers().size() == room->getMaxPlayers())
    return (false);
  deletePlayerOfRoom(st.lower(playerName));
  DataPlayer	*player = getPlayer(st.lower(playerName));
  std::vector<DataPlayer *> pl = room->getPlayers();

  pl.push_back(player);
  room->setPlayers(pl);
  _isUpdate = true;
  std::cout << "room : [" << roomName << "] rejointe par : [" << playerName << "]" << std::endl;
  return (true);
}

bool	ServerData::watchGame(const std::string &roomName, const std::string &playerName)
{
  StringCk	st;
  if (roomExist(st.lower(roomName)) == false || playerExist(st.lower(playerName)) == false)
    return (false);
  deletePlayerOfRoom(st.lower(playerName));
  DataRoom	*room = getRoom(st.lower(roomName));
  DataPlayer	*player = getPlayer(st.lower(playerName));
  std::vector<DataPlayer *> pl = room->getWatchers();

  pl.push_back(player);
  room->setWatchers(pl);
  _isUpdate = true;
    std::cout << "room : [" << roomName << "] rejointe par : [" << playerName << "] en tant que viewer" << std::endl;
  return (true);
}

bool	ServerData::leaveRoom(const std::string &roomName, const std::string &playerName)
{
  StringCk	st;
  if (roomExist(st.lower(roomName)) == false || playerExist(st.lower(playerName)) == false || playerInRoom(st.lower(playerName), getRoom(st.lower(roomName))) == false)
    return (false);
  std::cout << "[" << playerName << "] a quitter la room : [" << roomName << "]" << std::endl;
  if (deletePlayerInRoom(st.lower(playerName), getRoom(st.lower(roomName))) == true)
    {
      if (getRoom(st.lower(roomName))->getPlayers().size() == 0)
	{
	  std::cout << getRoom(st.lower(roomName))->getName() << " room's just delete" << std::endl;
	  _isUpdate = true;
	  deleteRoom(st.lower(roomName));
	}
    }
  _isUpdate = true;
  return (true);
}

void		ServerData::deleteRoom(const std::string &name)
{
  uint64_t	i;
  StringCk	st;
  
  i = 0;
  while (i < _room.size())
    {
      if (st.lower(_room[i]->getName()) == st.lower(name))
	{
	  _isUpdate = true;
	  _room.erase(_room.begin() + i);
	  return;
	}
      i++;
    }
}

DataRoom	*ServerData::getRoom(const std::string &name) const
{
  StringCk	st;
  if (roomExist(st.lower(name)) == true)
    return (_room[getRoomPos(st.lower(name))]);
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
  StringCk	st;

  i = 0;
  while (i < room->getPlayers().size())
    {
      if (st.lower(room->getPlayers()[i]->getName()) == st.lower(player))
	return (true);
      i++;
    }
  i = 0;
  while (i < room->getWatchers().size())
    {
      if (st.lower(room->getWatchers()[i]->getName()) == st.lower(player))
	return (true);
      i++;
    }
  return (false);
}

bool			ServerData::playerAlreadyInRoom(const std::string &player)
{
  StringCk	st;
  if (playerExist(st.lower(player)) == false || getPlayer(st.lower(player))->getOnline() == false)
    return (false);
  uint64_t	i;

  i = 0;
  while (i < _room.size())
    {
      if (playerInRoom(st.lower(player), _room[i]) == true)
	return (true);
      i++;
    }
  return (false);
}

bool			ServerData::deletePlayerInRoom(const std::string &player, DataRoom *room)
{
  uint64_t		i;
  std::vector<DataPlayer *> pl = room->getPlayers();
  StringCk	st;
  
  i = 0;
  while (i < pl.size())
    {
      if (st.lower(pl[i]->getName()) == st.lower(player))
	{
	  _isUpdate = true;
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
      if (st.lower(pl[i]->getName()) == st.lower(player))
	{
	  _isUpdate = true;
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
  StringCk	st;
  
  i = 0;
  while (i < _room.size())
    {
      if (deletePlayerInRoom(st.lower(player), _room[i]) == true)
	{
	  if (_room[i]->getPlayers().size() == 0)
	    {
	      std::cout << _room[i]->getName() << " room's just delete" << std::endl;
	      _isUpdate = true;
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
