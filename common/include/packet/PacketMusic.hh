//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETMUSIC_HH__
#define __PACKETMUSIC_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketMusic : public APacket {

	public:
		PacketMusic(const std::string & music);
		PacketMusic(const uint8_t *data);
		~PacketMusic();

		std::string getMusic() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::string _music;
	};
};

#endif