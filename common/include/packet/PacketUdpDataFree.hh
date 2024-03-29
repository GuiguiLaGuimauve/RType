//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETUDPDATAFREE_HH__
#define __PACKETUDPDATAFREE_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketUdpDataFree : public APacket {

	public:
		PacketUdpDataFree();
		PacketUdpDataFree(const uint8_t *data);
		~PacketUdpDataFree();

		bool isTcp() const;
		bool isUdp() const;

	private:
	};
};

#endif