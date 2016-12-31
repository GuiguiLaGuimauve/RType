//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETSHOOTSCLIENT_HH__
#define __PACKETSHOOTSCLIENT_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataShoot.hpp"

namespace Packet {

	class PacketShootsClient : public APacket {

	public:
		PacketShootsClient(const std::vector<DataShoot *> & shoots);
		PacketShootsClient(const uint8_t *data);
		~PacketShootsClient();

		std::vector<DataShoot *> getShoots() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::vector<DataShoot *> _shoots;
	};
};

#endif