//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETSOUND_HH__
#define __PACKETSOUND_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketSound : public APacket {

	public:
		PacketSound(const std::string & sound);
		PacketSound(const uint8_t *data);
		~PacketSound();

		std::string getSound() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _sound;
	};
};

#endif