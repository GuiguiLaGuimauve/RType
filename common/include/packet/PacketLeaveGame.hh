//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETLEAVEGAME_HH__
#define __PACKETLEAVEGAME_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketLeaveGame : public APacket {

	public:
		PacketLeaveGame(const std::string & gameName, const std::string & playerName);
		PacketLeaveGame(const uint8_t *data);
		~PacketLeaveGame();

		std::string getGameName() const;
		std::string getPlayerName() const;

	protected:
		std::string _gameName;
		std::string _playerName;
	};
};

#endif