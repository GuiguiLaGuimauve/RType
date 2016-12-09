//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPLAYERS_HH__
#define __PACKETPLAYERS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataPlayerPosition.hpp"

namespace Packet {

	class PacketPlayers : public APacket {

	public:
		PacketPlayers(const std::vector<DataPlayerPosition *> & players);
		PacketPlayers(const uint8_t *data);
		~PacketPlayers();

		std::vector<DataPlayerPosition *> getPlayers() const;

	protected:
		std::vector<DataPlayerPosition *> _players;
	};
};

#endif