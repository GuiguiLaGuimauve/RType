//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETMOVE_HH__
#define __PACKETMOVE_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketMove : public APacket {

	public:
		PacketMove(const uint16_t & x, const uint16_t & y);
		PacketMove(const uint8_t *data);
		~PacketMove();

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