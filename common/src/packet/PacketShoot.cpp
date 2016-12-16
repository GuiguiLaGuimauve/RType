//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketShoot.hh"

PacketShoot::PacketShoot(const uint16_t & x, const uint16_t & y)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::SHOOT;
	_tickId = 0;
	_x = x;
	_y = y;

	ps.add(_x);
	dataPacketSize += 2;

	ps.add(_y);
	dataPacketSize += 2;

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

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_x = pd.get16(posInPacket);
	posInPacket += 2;

	_y = pd.get16(posInPacket);
	posInPacket += 2;
}

PacketShoot::~PacketShoot()
{
}

uint16_t PacketShoot::getX() const
{
	return (_x);
}

uint16_t PacketShoot::getY() const
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