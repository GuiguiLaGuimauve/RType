//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCREATEROOM_HH__
#define __PACKETCREATEROOM_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketCreateRoom : public APacket {

	public:
		PacketCreateRoom(const std::string & gameName, const uint8_t & maxPlayers);
		PacketCreateRoom(const uint8_t *data);
		~PacketCreateRoom();

		std::string getGameName() const;
		uint8_t getMaxPlayers() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _gameName;
		uint8_t _maxPlayers;
	};
};

#endif