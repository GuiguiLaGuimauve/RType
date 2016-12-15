//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCONNECT_HH__
#define __PACKETCONNECT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketConnect : public APacket {

	public:
		PacketConnect();
		PacketConnect(const uint8_t *data);
		~PacketConnect();

		bool isTcp() const;
		bool isUdp() const;

	protected:
	};
};

#endif