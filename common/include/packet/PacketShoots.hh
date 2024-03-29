//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETSHOOTS_HH__
#define __PACKETSHOOTS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataShoot.hpp"

namespace Packet {

	class PacketShoots : public APacket {

	public:
		PacketShoots(const std::vector<DataShoot *> & shoots);
		PacketShoots(const uint8_t *data);
		~PacketShoots();

		std::vector<DataShoot *> getShoots() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::vector<DataShoot *> _shoots;
	};
};

#endif