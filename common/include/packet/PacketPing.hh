//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPING_HH__
#define __PACKETPING_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketPing : public APacket {

	public:
		PacketPing();
		PacketPing(const uint8_t *data);
		~PacketPing();

		bool isTcp() const;
		bool isUdp() const;

	protected:
	};
};

#endif