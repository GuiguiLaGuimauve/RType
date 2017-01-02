//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketGameEnded.hh"

PacketGameEnded::PacketGameEnded(const uint8_t &t)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_value = t;

	_type = IPacket::PacketType::GAMEENDED;
	_tickId = 0;

	ps.add((uint8_t)_value);
	dataPacketSize += 1;
	
	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketGameEnded::PacketGameEnded(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::GAMEENDED;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];


	_value = pd.get8(0);
}

PacketGameEnded::~PacketGameEnded()
{
}

bool PacketGameEnded::isTcp() const
{
	return (true);
}

bool PacketGameEnded::isUdp() const
{
	return (false);
}

uint8_t PacketGameEnded::getValue() const { return (_value); }
