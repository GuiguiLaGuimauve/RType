//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETACCEPT_HH__
#define __PACKETACCEPT_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketAccept : public APacket {

	public:
		PacketAccept(const std::string & message);
		PacketAccept(const uint8_t *data);
		~PacketAccept();

		std::string getMessage() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _message;
	};
};

#endif