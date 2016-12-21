//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETROOMS_HH__
#define __PACKETROOMS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataRoom.hpp"

namespace Packet {

	class PacketRooms : public APacket {

	public:
		PacketRooms(const std::vector<DataRoom *> & rooms);
		PacketRooms(const uint8_t *data);
		~PacketRooms();

		std::vector<DataRoom *> getRooms() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::vector<DataRoom *> _rooms;
	};
};

#endif