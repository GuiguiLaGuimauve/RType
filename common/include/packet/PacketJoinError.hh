//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETJOINERROR_HH__
#define __PACKETJOINERROR_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketJoinError : public APacket {

	public:
		PacketJoinError(const std::string & gameName);
		PacketJoinError(const uint8_t *data);
		~PacketJoinError();

		std::string getGameName() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::string _gameName;
	};
};

#endif