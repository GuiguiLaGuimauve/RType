//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETWATCHGAME_HH__
#define __PACKETWATCHGAME_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketWatchGame : public APacket {

	public:
		PacketWatchGame(const std::string & gameName);
		PacketWatchGame(const uint8_t *data);
		~PacketWatchGame();

		std::string getGameName() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _gameName;
	};
};

#endif