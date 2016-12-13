//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketMove.hh"

PacketMove::PacketMove(const uint8_t & x, const uint8_t & y)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::MOVE;
	_tickId = 0;
	_x = x;
	_y = y;

	ps.add(_x);
	dataPacketSize += 1;

	ps.add(_y);
	dataPacketSize += 1;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketMove::PacketMove(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::MOVE;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_x = pd.get8(posInPacket);
	posInPacket += 1;

	_y = pd.get8(posInPacket);
	posInPacket += 1;
}

PacketMove::~PacketMove()
{
}

uint8_t PacketMove::getX() const
{
	return (_x);
}

uint8_t PacketMove::getY() const
{
	return (_y);
}

bool PacketMove::isTcp() const
{
	return (false);
}

bool PacketMove::isUdp() const
{
	return (true);
}