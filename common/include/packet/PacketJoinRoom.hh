//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETJOINROOM_HH__
#define __PACKETJOINROOM_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketJoinRoom : public APacket {

	public:
		PacketJoinRoom(const std::string & gameName, const std::string & playerName);
		PacketJoinRoom(const uint8_t *data);
		~PacketJoinRoom();

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