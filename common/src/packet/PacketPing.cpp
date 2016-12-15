//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketPing.hh"

PacketPing::PacketPing()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::PING;
	_tickId = 0;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketPing::PacketPing(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::PING;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];
}

PacketPing::~PacketPing()
{
}

bool PacketPing::isTcp() const
{
	return (false);
}

bool PacketPing::isUdp() const
{
	return (true);
}
