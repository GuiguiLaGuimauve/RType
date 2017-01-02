//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketAccept.hh"

PacketAccept::PacketAccept(const std::string & message)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ACCEPT;
	_tickId = 0;
	_message = message;

	ps.add((uint16_t)_message.size());
	ps.add(_message);
	dataPacketSize += 2 + (uint32_t)_message.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketAccept::PacketAccept(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::ACCEPT;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_message = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
}

PacketAccept::~PacketAccept()
{
}

std::string PacketAccept::getMessage() const
{
	return (_message);
}

bool PacketAccept::isTcp() const
{
	return (true);
}

bool PacketAccept::isUdp() const
{
	return (false);
}