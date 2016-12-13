//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketJoinGame.hh"

PacketJoinGame::PacketJoinGame(const std::string & gameName, const std::string & playerName)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::JOIN_GAME;
	_tickId = 0;
	_gameName = gameName;
	_playerName = playerName;

	ps.add((uint16_t)_gameName.size());
	ps.add(_gameName);
	dataPacketSize += 2 + _gameName.size();

	ps.add((uint16_t)_playerName.size());
	ps.add(_playerName);
	dataPacketSize += 2 + _playerName.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketJoinGame::PacketJoinGame(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::JOIN_GAME;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_gameName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);

	_playerName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
}

PacketJoinGame::~PacketJoinGame()
{
}

std::string PacketJoinGame::getGameName() const
{
	return (_gameName);
}

std::string PacketJoinGame::getPlayerName() const
{
	return (_playerName);
}

bool PacketJoinGame::isTcp() const
{
	return (true);
}

bool PacketJoinGame::isUdp() const
{
	return (false);
}