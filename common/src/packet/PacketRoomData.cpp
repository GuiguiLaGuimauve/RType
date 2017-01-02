//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketRoomData.hh"

PacketRoomData::PacketRoomData(const DataRoom *dataroom)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ROOM_DATA;
	_tickId = 0;
	_dataroom = (DataRoom *)dataroom;
	
	ps.add((uint16_t)dataroom->getName().size());
	ps.add(dataroom->getName());
	dataPacketSize += 2 + (uint32_t)(dataroom->getName().size());
	
	ps.add((uint16_t)_dataroom->getNbPlayers());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _dataroom->getPlayers().size(); i++)
	{
	  ps.add((uint16_t)_dataroom->getPlayers()[i]->getName().size());
	  ps.add(_dataroom->getPlayers()[i]->getName());
	  dataPacketSize += 2 + (uint32_t)_dataroom->getPlayers()[i]->getName().size();

		ps.add(_dataroom->getPlayers()[i]->getStageSucceed());
		dataPacketSize += 2;

		ps.add(_dataroom->getPlayers()[i]->getGamePlayed());
		dataPacketSize += 2;
	}

	ps.add(_dataroom->getMaxPlayers());
	dataPacketSize += 1;

	ps.add(_dataroom->getLevel());
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
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	_dataroom = new DataRoom;
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_dataroom->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
	
	uint64_t playersLength = pd.get16(posInPacket);
	posInPacket += 2;
	std::vector<DataPlayer *> tmp;
	for (uint64_t i = 0; i < playersLength; i++)
	{
		DataPlayer *playersTemp = new DataPlayer();

		playersTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

		playersTemp->setStageSucceed(pd.get16(posInPacket));
		posInPacket += 2;

		playersTemp->setGamePlayed(pd.get16(posInPacket));
		posInPacket += 2;
		tmp.push_back(playersTemp);
	}
	_dataroom->setPlayers(tmp);
	_dataroom->setMaxPlayers(pd.get8(posInPacket));
	posInPacket += 1;

	_dataroom->setLevel(pd.get8(posInPacket));
	posInPacket += 1;
}

PacketRoomData::~PacketRoomData()
{
}

std::vector<DataPlayer *> PacketRoomData::getPlayers() const
{
	return (_dataroom->getPlayers());
}

uint8_t PacketRoomData::getMaxPlayers() const
{
  return (_dataroom->getMaxPlayers());
}

uint8_t PacketRoomData::getLevel() const
{
  return (_dataroom->getLevel());
}

bool PacketRoomData::isTcp() const
{
	return (true);
}

bool PacketRoomData::isUdp() const
{
	return (false);
}
