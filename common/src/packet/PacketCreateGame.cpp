//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketCreateGame.hh"

PacketCreateGame::PacketCreateGame(const std::string & gameName, const uint8_t & maxPlayers, const uint8_t & level)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::CREATE_GAME;
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

PacketCreateGame::PacketCreateGame(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::CREATE_GAME;
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

PacketCreateGame::~PacketCreateGame()
{
}

std::string PacketCreateGame::getGameName() const
{
	return (_gameName);
}

uint8_t PacketCreateGame::getMaxPlayers() const
{
	return (_maxPlayers);
}

uint8_t PacketCreateGame::getLevel() const
{
	return (_level);
}

bool PacketCreateGame::isTcp() const
{
	return (true);
}

bool PacketCreateGame::isUdp() const
{
	return (false);
}