//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketLeaveRoom.hh"

PacketLeaveRoom::PacketLeaveRoom(const std::string & gameName, const std::string & playerName)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::LEAVE_ROOM;
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

PacketLeaveRoom::PacketLeaveRoom(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::LEAVE_ROOM;
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

PacketLeaveRoom::~PacketLeaveRoom()
{
}

std::string PacketLeaveRoom::getGameName() const
{
	return (_gameName);
}

std::string PacketLeaveRoom::getPlayerName() const
{
	return (_playerName);
}

bool PacketLeaveRoom::isTcp() const
{
	return (true);
}

bool PacketLeaveRoom::isUdp() const
{
	return (false);
}