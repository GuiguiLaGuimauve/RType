//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPONG_HH__
#define __PACKETPONG_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketPong : public APacket {

	public:
		PacketPong();
		PacketPong(const uint8_t *data);
		~PacketPong();

		bool isTcp() const;
		bool isUdp() const;

	private:
	};
};

#endif