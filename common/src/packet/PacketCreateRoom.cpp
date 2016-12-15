//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketCreateRoom.hh"

PacketCreateRoom::PacketCreateRoom(const std::string & gameName, const uint8_t & maxPlayers, const uint8_t & level)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::CREATE_ROOM;
	_tickId = 0;
	_gameName = gameName;
	_maxPlayers = maxPlayers;
	_level = level;

	ps.add((uint16_t)_gameName.size());
	ps.add(_gameName);
	dataPacketSize += 2 + _gameName.size();

	ps.add(_maxPlayers);
	dataPacketSize += 1;

	ps.add(_level);
	dataPacketSize += 1;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketCreateRoom::PacketCreateRoom(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::CREATE_ROOM;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_gameName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);

	_maxPlayers = pd.get8(posInPacket);
	posInPacket += 1;

	_level = pd.get8(posInPacket);
	posInPacket += 1;
}

PacketCreateRoom::~PacketCreateRoom()
{
}

std::string PacketCreateRoom::getGameName() const
{
	return (_gameName);
}

uint8_t PacketCreateRoom::getMaxPlayers() const
{
	return (_maxPlayers);
}

uint8_t PacketCreateRoom::getLevel() const
{
	return (_level);
}

bool PacketCreateRoom::isTcp() const
{
	return (true);
}

bool PacketCreateRoom::isUdp() const
{
	return (false);
}