//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketConnect.hh"
#include <ctime>
#pragma warning(disable : 4996)

PacketConnect::PacketConnect()
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	_type = IPacket::PacketType::CONNECT;
	_tickId = 0;
	_code = (uint16_t)timePtr->tm_yday + 6;

	std::cout << "code : " << _code << std::endl;
	ps.add(_code);
	dataPacketSize += 2;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketConnect::PacketConnect(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::CONNECT;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_code = pd.get16(posInPacket);
	posInPacket += 2;
}

PacketConnect::~PacketConnect()
{
}

uint16_t PacketConnect::getCode() const
{
	return (_code);
}

bool PacketConnect::isTcp() const
{
	return (true);
}

bool PacketConnect::isUdp() const
{
	return (false);
}
