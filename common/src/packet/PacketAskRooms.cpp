//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketAskRooms.hh"

PacketAskRooms::PacketAskRooms()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ASK_ROOMS;
	_tickId = 0;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketAskRooms::PacketAskRooms(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::ASK_ROOMS;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];
}

PacketAskRooms::~PacketAskRooms()
{
}

bool PacketAskRooms::isTcp() const
{
	return (true);
}

bool PacketAskRooms::isUdp() const
{
	return (false);
}