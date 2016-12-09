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
	_rooms = rooms;

	ps.add((uint16_t)_rooms.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _rooms.size(); i++)
	{
		ps.add((uint16_t)_rooms[i]->getName().size());
		ps.add(_rooms[i]->getName());
		dataPacketSize += 2 + _rooms[i]->getName().size();

		ps.add((uint16_t)_rooms[i]->getPlayers().size());
		dataPacketSize += 2;
		for (uint64_t j = 0; j < _rooms[i]->getPlayers().size(); j++)
		{
			ps.add((uint16_t)_rooms[i]->getPlayers()[j]->getName().size());
			ps.add(_rooms[i]->getPlayers()[j]->getName());
			dataPacketSize += 2 + _rooms[i]->getPlayers()[j]->getName().size();
		}

		ps.add(_rooms[i]->getMaxPlayers());
		dataPacketSize += 1;

		ps.add(_rooms[i]->getLevel());
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

	uint64_t roomsLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < roomsLength; i++)
	{
		DataRoom *roomsTemp = new DataRoom();

		roomsTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + pd.get16(posInPacket);

		uint64_t playersLength = pd.get16(posInPacket);
		posInPacket += 2;
		for (uint64_t j = 0; j < playersLength; j++)
		{
			DataPlayerName *playersTemp = new DataPlayerName();

			playersTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
			posInPacket += 2 + pd.get16(posInPacket);
			roomsTemp->getPlayers().push_back(playersTemp);
		}

		roomsTemp->setMaxPlayers(pd.get8(posInPacket));
		posInPacket += 1;

		roomsTemp->setLevel(pd.get8(posInPacket));
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