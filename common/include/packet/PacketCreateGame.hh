//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCREATEGAME_HH__
#define __PACKETCREATEGAME_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketCreateGame : public APacket {

	public:
		PacketCreateGame(const std::string & gameName, const uint8_t & maxPlayers, const uint8_t & level);
		PacketCreateGame(const uint8_t *data);
		~PacketCreateGame();

		std::string getGameName() const;
		uint8_t getMaxPlayers() const;
		uint8_t getLevel() const;

	protected:
		std::string _gameName;
		uint8_t _maxPlayers;
		uint8_t _level;
	};
};

#endif