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
		DataPlayer() {};
		~DataPlayer() {};

		std::string getName() const { return (_name); };
		uint16_t getStageSucceed() const { return (_stageSucceed); };
		uint16_t getGamePlayed() const { return (_gamePlayed); };

		void setName(const std::string & name) { _name = name; };
		void setStageSucceed(const uint16_t & stageSucceed) { _stageSucceed = stageSucceed; };
		void setGamePlayed(const uint16_t & gamePlayed) { _gamePlayed = gamePlayed; };

	protected:
		std::string _name;
		uint16_t _stageSucceed;
		uint16_t _gamePlayed;
	};
};

#endif