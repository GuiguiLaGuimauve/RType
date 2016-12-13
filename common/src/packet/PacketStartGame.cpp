//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketStartGame.hh"

PacketStartGame::PacketStartGame(const std::string & gameName, const uint16_t & udpPort)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::START_GAME;
	_tickId = 0;
	_gameName = gameName;
	_udpPort = udpPort;

	ps.add((uint16_t)_gameName.size());
	ps.add(_gameName);
	dataPacketSize += 2 + _gameName.size();

	ps.add(_udpPort);
	dataPacketSize += 2;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketStartGame::PacketStartGame(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::START_GAME;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_gameName = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);

	_udpPort = pd.get16(posInPacket);
	posInPacket += 2;
}

PacketStartGame::~PacketStartGame()
{
}

std::string PacketStartGame::getGameName() const
{
	return (_gameName);
}

uint16_t PacketStartGame::getUdpPort() const
{
	return (_udpPort);
}

bool PacketStartGame::isTcp() const
{
	return (true);
}

bool PacketStartGame::isUdp() const
{
	return (false);
}