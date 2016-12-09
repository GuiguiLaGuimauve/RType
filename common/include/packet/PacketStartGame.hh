//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETSTARTGAME_HH__
#define __PACKETSTARTGAME_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketStartGame : public APacket {

	public:
		PacketStartGame(const std::string & gameName, const uint16_t & udpPort);
		PacketStartGame(const uint8_t *data);
		~PacketStartGame();

		std::string getGameName() const;
		uint16_t getUdpPort() const;

	protected:
		std::string _gameName;
		uint16_t _udpPort;
	};
};

#endif