//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETBACKGROUNDS_HH__
#define __PACKETBACKGROUNDS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataBackground.hpp"

namespace Packet {

	class PacketBackgrounds : public APacket {

	public:
		PacketBackgrounds(const std::vector<DataBackground *> & backgrounds);
		PacketBackgrounds(const uint8_t *data);
		~PacketBackgrounds();

		std::vector<DataBackground *> getBackgrounds() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::vector<DataBackground *> _backgrounds;
	};
};

#endif