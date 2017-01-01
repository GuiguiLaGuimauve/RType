//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketCreateRoom.hh"

PacketCreateRoom::PacketCreateRoom(const std::string & gameName, const uint8_t & maxPlayers)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::CREATE_ROOM;
	_tickId = 0;
	_gameName = gameName;
	_maxPlayers = maxPlayers;

	ps.add((uint16_t)_gameName.size());
	ps.add(_gameName);
	dataPacketSize += 2 + (uint32_t)_gameName.size();

	ps.add(_maxPlayers);
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
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

	_maxPlayers = pd.get8(posInPacket);
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

bool PacketCreateRoom::isTcp() const
{
	return (true);
}

bool PacketCreateRoom::isUdp() const
{
	return (false);
}