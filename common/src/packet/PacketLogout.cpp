//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketLogout.hh"

PacketLogout::PacketLogout()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::LOGOUT;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketLogout::PacketLogout(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::LOGOUT;
	_size = pd.getPacketSize();
}

PacketLogout::~PacketLogout()
{
}