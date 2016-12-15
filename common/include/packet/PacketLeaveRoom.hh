//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETLEAVEROOM_HH__
#define __PACKETLEAVEROOM_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketLeaveRoom : public APacket {

	public:
		PacketLeaveRoom(const std::string & gameName, const std::string & playerName);
		PacketLeaveRoom(const uint8_t *data);
		~PacketLeaveRoom();

		std::string getGameName() const;
		std::string getPlayerName() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _gameName;
		std::string _playerName;
	};
};

#endif