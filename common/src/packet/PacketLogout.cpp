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
	_tickId = 0;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketLogout::PacketLogout(const uint8_t *data)
{
	PacketDeserializer pd(data);

	_type = IPacket::PacketType::LOGOUT;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];
}

PacketLogout::~PacketLogout()
{
}

bool PacketLogout::isTcp() const
{
	return (true);
}

bool PacketLogout::isUdp() const
{
	return (false);
}