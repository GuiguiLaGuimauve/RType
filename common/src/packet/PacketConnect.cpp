//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketConnect.hh"

PacketConnect::PacketConnect()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::CONNECT;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketConnect::PacketConnect(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::CONNECT;
	_size = pd.getPacketSize();
}

PacketConnect::~PacketConnect()
{
}