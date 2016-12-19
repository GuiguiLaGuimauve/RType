//
// ServerData.hh for ServerData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Mon Dec 19 23:14:36 2016 Maxime Lecoq
// Last update Mon Dec 19 23:57:13 2016 lecoq
//

#ifndef SERVERDATA_HH_
# define SERVERDATA_HH_

# include <vector>
# include <iostream>
# include <string>
# include "DataRoom.hpp"
# include "DataPlayer.hpp"

using namespace Packet;

class ServerData {
public:
  ServerData();
  ~ServerData();
  void		addPlayer(const std::string &, const std::string &);
  DataPlayer	*getPlayer(const std::string &) const;
  bool		playerExist(const std::string &) const;
  void		addRoom(const std::string &, const uint8_t & = 4);
  DataRoom	*getRoom(const std::string &) const;
  bool		roomExist(const std::string &) const;
private:
  uint64_t	getPlayerPos(const std::string &) const;
  uint64_t	getRoomPos(const std::string &) const;
private:
  std::vector<DataRoom *>	_room;
  std::vector<DataPlayer *>	_player;
};

#endif /* !SERVERDATA_HH_ */
