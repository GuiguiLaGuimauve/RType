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
		PacketStartGame(const std::string & gameName);
		PacketStartGame(const uint8_t *data);
		~PacketStartGame();

		std::string getGameName() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _gameName;
	};
};

#endif