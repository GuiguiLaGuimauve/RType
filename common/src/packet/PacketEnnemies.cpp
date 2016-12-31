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
	_tickId = 0;
	_ennemies = ennemies;

	ps.add((uint16_t)_ennemies.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _ennemies.size(); i++)
	{
		ps.add((uint16_t)_ennemies[i]->getName().size());
		ps.add(_ennemies[i]->getName());
		dataPacketSize += 2 + (uint32_t)_ennemies[i]->getName().size();

		ps.add(_ennemies[i]->getX());
		dataPacketSize += 2;

		ps.add(_ennemies[i]->getY());
		dataPacketSize += 2;
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
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	uint64_t ennemiesLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < ennemiesLength; i++)
	{
		DataEnnemy *ennemiesTemp = new DataEnnemy();

		ennemiesTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

		ennemiesTemp->setX(pd.get16(posInPacket));
		posInPacket += 2;

		ennemiesTemp->setY(pd.get16(posInPacket));
		posInPacket += 2;
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

bool PacketEnnemies::isTcp() const
{
	return (false);
}

bool PacketEnnemies::isUdp() const
{
	return (true);
}