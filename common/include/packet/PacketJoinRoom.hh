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
		PacketJoinRoom(const std::string & gameName);
		PacketJoinRoom(const uint8_t *data);
		~PacketJoinRoom();

		std::string getGameName() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::string _gameName;
	};
};

#endif