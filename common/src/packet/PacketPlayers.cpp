//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketPlayers.hh"

PacketPlayers::PacketPlayers(const std::vector<DataPlayer *> & players)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::PLAYERS;
	_tickId = 0;
	_players = players;

	ps.add((uint16_t)_players.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _players.size(); i++)
	{

	  ps.add((uint16_t)__players[i]->getName().size());
	  ps.add(_players[i]->getName());
	  dataPacketSize += 2 + (uint32_t)_players[i]->getName().size();
	  
	  ps.add(_players[i]->getId());
	  dataPacketSize += 1;

		ps.add(_players[i]->getX());
		dataPacketSize += 2;

		ps.add(_players[i]->getY());
		dataPacketSize += 2;

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
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	uint64_t playersLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < playersLength; i++)
	{
		DataPlayer *playersTemp = new DataPlayer();

		playersTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
		
		playersTemp->setId(pd.get8(posInPacket));
		posInPacket += 1;

		playersTemp->setX(pd.get16(posInPacket));
		posInPacket += 2;

		playersTemp->setY(pd.get16(posInPacket));
		posInPacket += 2;

		playersTemp->setHealth(pd.get8(posInPacket));
		posInPacket += 1;
		_players.push_back(playersTemp);
	}
}

PacketPlayers::~PacketPlayers()
{
}

std::vector<DataPlayer *> PacketPlayers::getPlayers() const
{
	return (_players);
}

bool PacketPlayers::isTcp() const
{
	return (false);
}

bool PacketPlayers::isUdp() const
{
	return (true);
}
