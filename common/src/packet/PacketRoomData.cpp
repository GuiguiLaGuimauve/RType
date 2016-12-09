//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketRoomData.hh"

PacketRoomData::PacketRoomData(const std::vector<DataPlayer *> & players, const uint8_t & maxPlayers, const uint8_t & level)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ROOM_DATA;
	_players = players;
	_maxPlayers = maxPlayers;
	_level = level;

	ps.add((uint16_t)_players.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _players.size(); i++)
	{
		ps.add((uint16_t)_players[i]->getName().size());
		ps.add(_players[i]->getName());
		dataPacketSize += 2 + _players[i]->getName().size();

		ps.add(_players[i]->getStageSucceed());
		dataPacketSize += 2;

		ps.add(_players[i]->getGamePlayed());
		dataPacketSize += 2;
	}

	ps.add(_maxPlayers);
	dataPacketSize += 1;

	ps.add(_level);
	dataPacketSize += 1;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketRoomData::PacketRoomData(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::ROOM_DATA;
	_size = pd.getPacketSize();

	uint64_t playersLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < playersLength; i++)
	{
		DataPlayer *playersTemp = new DataPlayer();

		playersTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + pd.get16(posInPacket);

		playersTemp->setStageSucceed(pd.get16(posInPacket));
		posInPacket += 2;

		playersTemp->setGamePlayed(pd.get16(posInPacket));
		posInPacket += 2;
		_players.push_back(playersTemp);
	}

	_maxPlayers = pd.get8(posInPacket);
	posInPacket += 1;

	_level = pd.get8(posInPacket);
	posInPacket += 1;
}

PacketRoomData::~PacketRoomData()
{
}

std::vector<DataPlayer *> PacketRoomData::getPlayers() const
{
	return (_players);
}

uint8_t PacketRoomData::getMaxPlayers() const
{
	return (_maxPlayers);
}

uint8_t PacketRoomData::getLevel() const
{
	return (_level);
}