//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAPLAYER_HH__
#define __DATAPLAYER_HH__

#include <stdint.h>
#include <string>

namespace Packet {

	class DataPlayer {

	public:
		DataPlayer() {_online = false;};
		~DataPlayer() {};

		std::string getName() const { return (_name); };
		std::string getPassword() const { return (_pw); };
		uint16_t getStageSucceed() const { return (_stageSucceed); };
		uint16_t getGamePlayed() const { return (_gamePlayed); };
		uint16_t getX() const { return (_x); };
		uint16_t getY() const { return (_y); };
		uint8_t getId() const { return (_id); };
		uint8_t getHealth() const { return (_health); };
		bool getOnline() const { return (_online); };

		void setName(const std::string & name) { _name = name; };
		void setPassword(const std::string & pw) { _pw = pw; };
		void setStageSucceed(const uint16_t & stageSucceed) { _stageSucceed = stageSucceed; };
		void setGamePlayed(const uint16_t & gamePlayed) { _gamePlayed = gamePlayed; };
		void setId(const uint8_t & id) { _id = id; };
		void setX(const uint16_t & x) { _x = x; };
		void setY(const uint16_t & y) { _y = y; };
		void setHealth(const uint8_t & health) { _health = health; };
		void setOnline(const bool & status) { _online = status; }

	protected:
		std::string _name;
		std::string _pw;
		uint16_t _stageSucceed;
		uint16_t _gamePlayed;
		uint8_t _id;
		uint16_t _x;
		uint16_t _y;
		uint8_t _health;
		bool _online;
	};
};

#endif