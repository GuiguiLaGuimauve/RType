//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketDisconnect.hh"

PacketDisconnect::PacketDisconnect()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::DISCONNECT;
	_tickId = 0;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketDisconnect::PacketDisconnect(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::DISCONNECT;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];
}

PacketDisconnect::~PacketDisconnect()
{
}

bool PacketDisconnect::isTcp() const
{
	return (false);
}

bool PacketDisconnect::isUdp() const
{
	return (true);
}