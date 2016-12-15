//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETENNEMIES_HH__
#define __PACKETENNEMIES_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataEnnemy.hpp"

namespace Packet {

	class PacketEnnemies : public APacket {

	public:
		PacketEnnemies(const std::vector<DataEnnemy *> & ennemies);
		PacketEnnemies(const uint8_t *data);
		~PacketEnnemies();

		std::vector<DataEnnemy *> getEnnemies() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::vector<DataEnnemy *> _ennemies;
	};
};

#endif