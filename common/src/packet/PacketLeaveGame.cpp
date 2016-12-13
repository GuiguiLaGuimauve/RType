//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketLeaveGame.hh"

PacketLeaveGame::PacketLeaveGame(const std::string & gameName, const std::string & playerName)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::LEAVE_GAME;
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

PacketLeaveGame::PacketLeaveGame(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::LEAVE_GAME;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_gameName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);

	_playerName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
}

PacketLeaveGame::~PacketLeaveGame()
{
}

std::string PacketLeaveGame::getGameName() const
{
	return (_gameName);
}

std::string PacketLeaveGame::getPlayerName() const
{
	return (_playerName);
}

bool PacketLeaveGame::isTcp() const
{
	return (true);
}

bool PacketLeaveGame::isUdp() const
{
	return (false);
}