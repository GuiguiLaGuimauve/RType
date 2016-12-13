//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketShoot.hh"

PacketShoot::PacketShoot(const uint8_t & x, const uint8_t & y)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::SHOOT;
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

PacketShoot::PacketShoot(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::SHOOT;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_x = pd.get8(posInPacket);
	posInPacket += 1;

	_y = pd.get8(posInPacket);
	posInPacket += 1;
}

PacketShoot::~PacketShoot()
{
}

uint8_t PacketShoot::getX() const
{
	return (_x);
}

uint8_t PacketShoot::getY() const
{
	return (_y);
}

bool PacketShoot::isTcp() const
{
	return (false);
}

bool PacketShoot::isUdp() const
{
	return (true);
}