//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETJOINGAME_HH__
#define __PACKETJOINGAME_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketJoinGame : public APacket {

	public:
		PacketJoinGame(const std::string & gameName, const std::string & playerName);
		PacketJoinGame(const uint8_t *data);
		~PacketJoinGame();

		std::string getGameName() const;
		std::string getPlayerName() const;

	protected:
		std::string _gameName;
		std::string _playerName;
	};
};

#endif