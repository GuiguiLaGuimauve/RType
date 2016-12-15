//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETWELCOME_HH__
#define __PACKETWELCOME_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketWelcome : public APacket {

	public:
		PacketWelcome(const std::string & message);
		PacketWelcome(const uint8_t *data);
		~PacketWelcome();

		std::string getMessage() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _message;
	};
};

#endif