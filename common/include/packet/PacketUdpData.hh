//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETUDPDATA_HH__
#define __PACKETUDPDATA_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {

	class PacketUdpData : public APacket {

	public:
		PacketUdpData(const uint8_t *ip, const uint16_t & port);
		PacketUdpData(const uint8_t *data);
		~PacketUdpData();

		uint8_t *getIp();
		uint16_t getPort() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		uint8_t _ip[4];
		uint16_t _port;
	};
};

#endif