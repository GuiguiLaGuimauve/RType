//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketRooms.hh"

PacketRooms::PacketRooms(const std::vector<DataRoom *> & rooms)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ROOMS;
	_tickId = 0;
	_rooms = rooms;

	ps.add((uint16_t)_rooms.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _rooms.size(); i++)
	{
		ps.add((uint16_t)_rooms[i]->getName().size());
		ps.add(_rooms[i]->getName());
		dataPacketSize += 2 + (uint32_t)_rooms[i]->getName().size();

		ps.add((uint16_t)_rooms[i]->getPlayers().size());
		dataPacketSize += 2;
		for (uint64_t j = 0; j < _rooms[i]->getPlayers().size(); j++)
		{
			ps.add((uint16_t)_rooms[i]->getPlayers()[j]->getName().size());
			ps.add(_rooms[i]->getPlayers()[j]->getName());
			dataPacketSize += 2 + (uint32_t)_rooms[i]->getPlayers()[j]->getName().size();

			ps.add(_rooms[i]->getPlayers()[j]->getStageSucceed());
			dataPacketSize += 2;

			ps.add(_rooms[i]->getPlayers()[j]->getGamePlayed());
			dataPacketSize += 2;
		}

		ps.add((uint16_t)_rooms[i]->getWatchers().size());
		dataPacketSize += 2;
		for (uint64_t j = 0; j < _rooms[i]->getWatchers().size(); j++)
		{
			ps.add((uint16_t)_rooms[i]->getWatchers()[j]->getName().size());
			ps.add(_rooms[i]->getWatchers()[j]->getName());
			dataPacketSize += 2 + (uint32_t)_rooms[i]->getWatchers()[j]->getName().size();
		}

		ps.add(_rooms[i]->getMaxPlayers());
		dataPacketSize += 1;

		ps.add(_rooms[i]->getLevel());
		dataPacketSize += 1;

		ps.add((uint8_t)_rooms[i]->getStarted());
		dataPacketSize += 1;
	}

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketRooms::PacketRooms(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::ROOMS;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	uint64_t roomsLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < roomsLength; i++)
	{
		DataRoom *roomsTemp = new DataRoom();

		roomsTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

		uint64_t playersLength = pd.get16(posInPacket);
		posInPacket += 2;
		std::vector<DataPlayer *> tmpData;
		for (uint64_t j = 0; j < playersLength; j++)
		{
			DataPlayer *playersTemp = new DataPlayer();

			playersTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
			posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

			playersTemp->setStageSucceed(pd.get16(posInPacket));
			posInPacket += 2;

			playersTemp->setGamePlayed(pd.get16(posInPacket));
			posInPacket += 2;
			
			tmpData.push_back(playersTemp);
		}
		roomsTemp->setPlayers(tmpData);
		uint64_t viewersLength = pd.get16(posInPacket);
		posInPacket += 2;
		std::vector<DataPlayer *> tmpDataV;
		for (uint64_t j = 0; j < viewersLength; j++)
		{
			DataPlayer *temp = new DataPlayer();

			temp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
			posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
			tmpDataV.push_back(temp);
		}
		roomsTemp->setWatchers(tmpDataV);
		roomsTemp->setMaxPlayers(pd.get8(posInPacket));
		posInPacket += 1;

		roomsTemp->setLevel(pd.get8(posInPacket));
		posInPacket += 1;

		roomsTemp->setStarted(((pd.get8(posInPacket)) ? true : false));
		posInPacket += 1;

		_rooms.push_back(roomsTemp);
	}
}

PacketRooms::~PacketRooms()
{
}

std::vector<DataRoom *> PacketRooms::getRooms() const
{
	return (_rooms);
}

bool PacketRooms::isTcp() const
{
	return (true);
}

bool PacketRooms::isUdp() const
{
	return (false);
}
