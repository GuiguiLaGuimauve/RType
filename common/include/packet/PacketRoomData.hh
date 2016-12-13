//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETROOMDATA_HH__
#define __PACKETROOMDATA_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataPlayer.hpp"

namespace Packet {

	class PacketRoomData : public APacket {

	public:
		PacketRoomData(const std::vector<DataPlayer *> & players, const uint8_t & maxPlayers, const uint8_t & level);
		PacketRoomData(const uint8_t *data);
		~PacketRoomData();

		std::vector<DataPlayer *> getPlayers() const;
		uint8_t getMaxPlayers() const;
		uint8_t getLevel() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::vector<DataPlayer *> _players;
		uint8_t _maxPlayers;
		uint8_t _level;
	};
};

#endif