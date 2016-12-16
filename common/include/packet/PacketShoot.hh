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
		PacketShoot(const uint16_t & x, const uint16_t & y);
		PacketShoot(const uint8_t *data);
		~PacketShoot();

		uint16_t getX() const;
		uint16_t getY() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		uint16_t _x;
		uint16_t _y;
	};
};

#endif