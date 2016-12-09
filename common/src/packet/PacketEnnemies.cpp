//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketEnnemies.hh"

PacketEnnemies::PacketEnnemies(const std::vector<DataEnnemy *> & ennemies)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ENNEMIES;
	_ennemies = ennemies;

	ps.add((uint16_t)_ennemies.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _ennemies.size(); i++)
	{
		ps.add(_ennemies[i]->getType());
		dataPacketSize += 1;

		ps.add(_ennemies[i]->getX());
		dataPacketSize += 1;

		ps.add(_ennemies[i]->getY());
		dataPacketSize += 1;
	}

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketEnnemies::PacketEnnemies(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::ENNEMIES;
	_size = pd.getPacketSize();

	uint64_t ennemiesLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < ennemiesLength; i++)
	{
		DataEnnemy *ennemiesTemp = new DataEnnemy();

		ennemiesTemp->setType(pd.get8(posInPacket));
		posInPacket += 1;

		ennemiesTemp->setX(pd.get8(posInPacket));
		posInPacket += 1;

		ennemiesTemp->setY(pd.get8(posInPacket));
		posInPacket += 1;
		_ennemies.push_back(ennemiesTemp);
	}
}

PacketEnnemies::~PacketEnnemies()
{
}

std::vector<DataEnnemy *> PacketEnnemies::getEnnemies() const
{
	return (_ennemies);
}