//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketPlayers.hh"

PacketPlayers::PacketPlayers(const std::vector<DataPlayerPosition *> & players)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::PLAYERS;
	_players = players;

	ps.add((uint16_t)_players.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _players.size(); i++)
	{
		ps.add(_players[i]->getId());
		dataPacketSize += 1;

		ps.add(_players[i]->getX());
		dataPacketSize += 1;

		ps.add(_players[i]->getY());
		dataPacketSize += 1;

		ps.add(_players[i]->getHealth());
		dataPacketSize += 1;
	}

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketPlayers::PacketPlayers(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::PLAYERS;
	_size = pd.getPacketSize();

	uint64_t playersLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < playersLength; i++)
	{
		DataPlayerPosition *playersTemp = new DataPlayerPosition();

		playersTemp->setId(pd.get8(posInPacket));
		posInPacket += 1;

		playersTemp->setX(pd.get8(posInPacket));
		posInPacket += 1;

		playersTemp->setY(pd.get8(posInPacket));
		posInPacket += 1;

		playersTemp->setHealth(pd.get8(posInPacket));
		posInPacket += 1;
		_players.push_back(playersTemp);
	}
}

PacketPlayers::~PacketPlayers()
{
}

std::vector<DataPlayerPosition *> PacketPlayers::getPlayers() const
{
	return (_players);
}