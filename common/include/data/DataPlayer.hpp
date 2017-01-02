//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAPLAYER_HH__
#define __DATAPLAYER_HH__

#include <stdint.h>
#include <string>
#include <vector>
#include "AData.hh"
#include "DataShoot.hpp"

using namespace Data;

class DataPlayer : public AData {

public:
  DataPlayer() : AData() {_online = false;
    _stageSucceed = 0;
    _gamePlayed = 0;
    _health = 100;
    _tick = 0; 
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSizeX(32 * 3);
	this->setSizeY(14 * 3);
	this->setHitBoxSizeX(32 * 3);
	this->setHitBoxSizeY(14 * 3);
  };
  ~DataPlayer() {};
  
  std::string getName() const { return (_name); };
  std::string getPassword() const { return (_pw); };
  uint16_t getStageSucceed() const { return (_stageSucceed); };
  uint16_t getGamePlayed() const { return (_gamePlayed); };
  uint8_t getId() const { return (_id); };
  bool getOnline() const { return (_online); };
  std::vector<DataShoot *> getShoots() const { return (_shoots); };
  uint64_t	getTick() const { return (_tick); };

  void setTick(const uint64_t &i) { _tick = i; };
  void setName(const std::string & name) { _name = name; };
  void setPassword(const std::string & pw) { _pw = pw; };
  void setStageSucceed(const uint16_t & stageSucceed) { _stageSucceed = stageSucceed; };
  void setGamePlayed(const uint16_t & gamePlayed) { _gamePlayed = gamePlayed; };
  void setId(const uint8_t & id) { _id = id; };
  void setOnline(const bool & status) { _online = status; }
  void setShoots(const std::vector<DataShoot *> &s) {
    _shoots = s;
  };
  void resetGame() {
    _shoots.clear();
  }
private:
  std::string _name;
  std::string _pw;
  uint16_t _stageSucceed;
  uint16_t _gamePlayed;
  uint8_t _id;
  bool _online;
  std::vector<DataShoot *> _shoots;
  uint64_t	_tick;
};

#endif
