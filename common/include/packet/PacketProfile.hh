//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPROFILE_HH__
#define __PACKETPROFILE_HH__

#include <stdint.h>
#include <string>
#include "DataPlayer.hpp"
#include "APacket.hh"

namespace Packet {

	class PacketProfile : public APacket {

	public:
		PacketProfile(const DataPlayer * player);
		PacketProfile(const uint8_t *data);
		~PacketProfile();

		DataPlayer *getPlayer() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		DataPlayer *_player;
	};
};

#endif