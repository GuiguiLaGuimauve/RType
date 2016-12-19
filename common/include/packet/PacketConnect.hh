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
		PacketConnect(const uint16_t & code);
		PacketConnect(const uint8_t *data);
		~PacketConnect();

		uint16_t getCode() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		uint16_t _code;
	};
};

#endif