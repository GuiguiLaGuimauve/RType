//
// ServerData.hh for ServerData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Mon Dec 19 23:14:36 2016 Maxime Lecoq
// Last update Wed Dec 21 00:25:23 2016 lecoq
//

#ifndef SERVERDATA_HH_
# define SERVERDATA_HH_

# include <vector>
# include <iostream>
# include <string>
# include "DataRoom.hpp"
# include "DataPlayer.hpp"
# include "ServerConf.hh"
# include "StringCk.hpp"
# include "Thread.hpp"

class ServerData {
public:
  ServerData();
  ~ServerData();
  bool		loginPlayer(const std::string &, const std::string &);
  bool		registerPlayer(const std::string &, const std::string &);
  void		logoutPlayer(const std::string &);
  DataPlayer	*getPlayer(const std::string &) const;
  bool		playerExist(const std::string &) const;
  bool		createRoom(const std::string &, const uint8_t & = 4, const std::string & = "");
  bool		joinRoom(const std::string &, const std::string &);
  bool		watchGame(const std::string &, const std::string &);
  bool		leaveRoom(const std::string &, const std::string &);
  DataRoom	*getRoom(const std::string &) const;
  bool		roomExist(const std::string &) const;
  bool		roomAreUpdate() const;
  std::vector<DataRoom *> getRooms();
  void		logout(const std::vector<std::string> &);
  std::vector<std::string> getOnlineClients() const;
private:
  uint64_t	getPlayerPos(const std::string &) const;
  uint64_t	getRoomPos(const std::string &) const;
  bool		playerInRoom(const std::string &, const DataRoom *);
  bool		playerAlreadyInRoom(const std::string &);
  bool		deletePlayerInRoom(const std::string &, DataRoom *);
  void		deletePlayerOfRoom(const std::string &);
  void		save();
private:
  std::vector<DataRoom *>	_room;
  std::vector<DataPlayer *>	_player;
  bool				_isUpdate;
  ServerConf			_conf;
  mythrd::Thread		*_thread;
  bool				_isRunning;
};

#endif /* !SERVERDATA_HH_ */
