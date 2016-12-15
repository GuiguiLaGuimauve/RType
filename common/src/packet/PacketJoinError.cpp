//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketJoinError.hh"

PacketJoinError::PacketJoinError(const std::string & gameName)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::JOIN_ERROR;
	_tickId = 0;
	_gameName = gameName;

	ps.add((uint16_t)_gameName.size());
	ps.add(_gameName);
	dataPacketSize += 2 + _gameName.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketJoinError::PacketJoinError(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::JOIN_ERROR;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_gameName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
}

PacketJoinError::~PacketJoinError()
{
}

std::string PacketJoinError::getGameName() const
{
	return (_gameName);
}

bool PacketJoinError::isTcp() const
{
	return (true);
}

bool PacketJoinError::isUdp() const
{
	return (false);
}