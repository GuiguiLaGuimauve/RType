//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPLAYERS_HH__
#define __PACKETPLAYERS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataPlayer.hpp"

namespace Packet {

	class PacketPlayers : public APacket {

	public:
		PacketPlayers(const std::vector<DataPlayer *> & players);
		PacketPlayers(const uint8_t *data);
		~PacketPlayers();

		std::vector<DataPlayer *> getPlayers() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::vector<DataPlayer *> _players;
	};
};

#endif