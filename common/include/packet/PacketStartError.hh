//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETSTARTERROR_HH__
#define __PACKETSTARTERROR_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketStartError : public APacket {

	public:
		PacketStartError(const std::string & gameName);
		PacketStartError(const uint8_t *data);
		~PacketStartError();

		std::string getGameName() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _gameName;
	};
};

#endif