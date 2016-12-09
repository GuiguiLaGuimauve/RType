//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketUdpDataFree.hh"

PacketUdpDataFree::PacketUdpDataFree()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::UDP_DATA_FREE;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketUdpDataFree::PacketUdpDataFree(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::UDP_DATA_FREE;
	_size = pd.getPacketSize();
}

PacketUdpDataFree::~PacketUdpDataFree()
{
}