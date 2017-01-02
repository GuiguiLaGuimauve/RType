//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAROOM_HH__
#define __DATAROOM_HH__

#include <stdint.h>
#include <string>
#include <vector>
#include "AData.hh"
#include "DataPlayer.hpp"
#include "StringCk.hpp"

class DataRoom {
  
public:
  DataRoom() {
    _maxPlayers = 4;
    _level = 1;
    _started = false;
    _isUpdate = false;
  };
  ~DataRoom() {};
  
  std::string getName() const { return (_name); };
  std::vector<DataPlayer *> getPlayers() const { return (_players); };
  std::vector<DataPlayer *> getWatchers() const { return (_watchers); };
  uint8_t getMaxPlayers() const { return (_maxPlayers); };
  uint8_t getLevel() const { return (_level); };
  uint16_t getNbPlayers() const { return ((uint16_t)_players.size()); };
  bool getStarted() const { return _started; }
  DataPlayer *getPlayer(const std::string &m) { StringCk st; uint64_t i; i = 0; while (i < _players.size()) { if (st.lower(_players[i]->getName()) == st.lower(m)) return (_players[i]); i++; } return (NULL); }
  uint32_t getScore() const { return (_score); }

  void update() { _isUpdate = true; }
  bool isUpdate() { if (_isUpdate == true) { _isUpdate = false; return (true); } else return (false); };
  void setName(const std::string & name) { _name = name; };
  void setPlayers(const std::vector<DataPlayer *> & players) { _players = players; };
  void setWatchers(const std::vector<DataPlayer *> & watchers) { _watchers = watchers; };
  void setMaxPlayers(const uint8_t & maxPlayers) { _maxPlayers = maxPlayers; };
  void setLevel(const uint8_t & level) { if (_level != level) { _isUpdate = true; _level = level; } };
  void setStarted(const bool & started) { _started = started; };  
  void setScore(const uint32_t &s) { _score = s; }

private:
  std::string			_name;
  std::vector<DataPlayer *>	_players;
  std::vector<DataPlayer *>	_watchers;
  uint8_t			_maxPlayers;
  uint8_t			_level;
  bool				_started;
  bool				_isUpdate;
  uint32_t			_score;
};

#endif
