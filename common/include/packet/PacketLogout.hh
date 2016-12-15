//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETLOGOUT_HH__
#define __PACKETLOGOUT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketLogout : public APacket {

	public:
		PacketLogout();
		PacketLogout(const uint8_t *data);
		~PacketLogout();

		bool isTcp() const;
		bool isUdp() const;

	protected:
	};
};

#endif