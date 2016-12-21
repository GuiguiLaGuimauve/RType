//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPOSITIONPLAYER_HH__
#define __PACKETPOSITIONPLAYER_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketPositionPlayer : public APacket {

	public:
		PacketPositionPlayer(const uint16_t & x, const uint16_t & y);
		PacketPositionPlayer(const uint8_t *data);
		~PacketPositionPlayer();

		uint16_t getX() const;
		uint16_t getY() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		uint16_t _x;
		uint16_t _y;
	};
};

#endif