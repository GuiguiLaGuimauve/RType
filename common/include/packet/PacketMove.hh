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
		PacketMove(const uint8_t & x, const uint8_t & y);
		PacketMove(const uint8_t *data);
		~PacketMove();

		uint8_t getX() const;
		uint8_t getY() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		uint8_t _x;
		uint8_t _y;
	};
};

#endif