//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketShoots.hh"

PacketShoots::PacketShoots(const std::vector<DataShoot *> & shoots)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::SHOOTS;
	_tickId = 0;
	_shoots = shoots;

	ps.add((uint16_t)_shoots.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _shoots.size(); i++)
	{
		ps.add((uint16_t)_shoots[i]->getName().size());
		ps.add(_shoots[i]->getName());
		dataPacketSize += 2 + _shoots[i]->getName().size();

		ps.add(_shoots[i]->getX());
		dataPacketSize += 1;

		ps.add(_shoots[i]->getY());
		dataPacketSize += 1;

		ps.add(_shoots[i]->getDamage());
		dataPacketSize += 1;
	}

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketShoots::PacketShoots(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::SHOOTS;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	uint64_t shootsLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < shootsLength; i++)
	{
		DataShoot *shootsTemp = new DataShoot();

		shootsTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + pd.get16(posInPacket);

		shootsTemp->setX(pd.get8(posInPacket));
		posInPacket += 1;

		shootsTemp->setY(pd.get8(posInPacket));
		posInPacket += 1;

		shootsTemp->setDamage(pd.get8(posInPacket));
		posInPacket += 1;
		_shoots.push_back(shootsTemp);
	}
}

PacketShoots::~PacketShoots()
{
}

std::vector<DataShoot *> PacketShoots::getShoots() const
{
	return (_shoots);
}

bool PacketShoots::isTcp() const
{
	return (false);
}

bool PacketShoots::isUdp() const
{
	return (true);
}