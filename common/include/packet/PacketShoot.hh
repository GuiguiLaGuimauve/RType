//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETSHOOT_HH__
#define __PACKETSHOOT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketShoot : public APacket {

	public:
		PacketShoot(const uint8_t & x, const uint8_t & y);
		PacketShoot(const uint8_t *data);
		~PacketShoot();

		uint8_t getX() const;
		uint8_t getY() const;

	protected:
		uint8_t _x;
		uint8_t _y;
	};
};

#endif