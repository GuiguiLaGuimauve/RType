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
		PacketLeaveRoom(const std::string & gameName);
		PacketLeaveRoom(const uint8_t *data);
		~PacketLeaveRoom();

		std::string getGameName() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::string _gameName;
	};
};

#endif