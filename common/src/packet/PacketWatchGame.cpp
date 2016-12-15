//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketWatchGame.hh"

PacketWatchGame::PacketWatchGame(const std::string & gameName)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::WATCH_GAME;
	_tickId = 0;
	_gameName = gameName;

	ps.add((uint16_t)_gameName.size());
	ps.add(_gameName);
	dataPacketSize += 2 + _gameName.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketWatchGame::PacketWatchGame(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::WATCH_GAME;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_gameName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
}

PacketWatchGame::~PacketWatchGame()
{
}

std::string PacketWatchGame::getGameName() const
{
	return (_gameName);
}

bool PacketWatchGame::isTcp() const
{
	return (true);
}

bool PacketWatchGame::isUdp() const
{
	return (false);
}