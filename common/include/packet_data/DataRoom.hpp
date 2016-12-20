//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAROOM_HH__
#define __DATAROOM_HH__

#include <stdint.h>
#include <string>
#include <vector>
#include "DataPlayer.hpp"

class DataRoom {
  
public:
  DataRoom() {
    _maxPlayers = 4;
    _level = 0;};
  ~DataRoom() {};
  
  std::string getName() const { return (_name); };
  std::vector<DataPlayer *> getPlayers() const { return (_players); };
  std::vector<DataPlayer *> getWatchers() const { return (_watchers); };
  uint8_t getMaxPlayers() const { return (_maxPlayers); };
  uint8_t getLevel() const { return (_level); };
  uint16_t getNbPlayers() const { return ((uint16_t)_players.size()); };
  
  void setName(const std::string & name) { _name = name; };
  void setPlayers(const std::vector<DataPlayer *> & players) { _players = players; };
  void setWatchers(const std::vector<DataPlayer *> & watchers) { _watchers = watchers; };
  void setMaxPlayers(const uint8_t & maxPlayers) { _maxPlayers = maxPlayers; };
  void setLevel(const uint8_t & level) { _level = level; };
  
private:
  std::string			_name;
  std::vector<DataPlayer *>	_players;
  std::vector<DataPlayer *>	_watchers;
  uint8_t			_maxPlayers;
  uint8_t			_level;
};

#endif
