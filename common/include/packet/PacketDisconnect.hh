//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETDISCONNECT_HH__
#define __PACKETDISCONNECT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketDisconnect : public APacket {

	public:
		PacketDisconnect();
		PacketDisconnect(const uint8_t *data);
		~PacketDisconnect();

		bool isTcp() const;
		bool isUdp() const;

	private:
	};
};

#endif