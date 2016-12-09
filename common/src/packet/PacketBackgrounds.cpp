//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketBackgrounds.hh"

PacketBackgrounds::PacketBackgrounds(const std::vector<DataBackground *> & backgrounds)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::BACKGROUNDS;
	_backgrounds = backgrounds;

	ps.add((uint16_t)_backgrounds.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _backgrounds.size(); i++)
	{
		ps.add(_backgrounds[i]->getType());
		dataPacketSize += 1;

		ps.add(_backgrounds[i]->getX());
		dataPacketSize += 1;

		ps.add(_backgrounds[i]->getY());
		dataPacketSize += 1;
	}

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketBackgrounds::PacketBackgrounds(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::BACKGROUNDS;
	_size = pd.getPacketSize();

	uint64_t backgroundsLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < backgroundsLength; i++)
	{
		DataBackground *backgroundsTemp = new DataBackground();

		backgroundsTemp->setType(pd.get8(posInPacket));
		posInPacket += 1;

		backgroundsTemp->setX(pd.get8(posInPacket));
		posInPacket += 1;

		backgroundsTemp->setY(pd.get8(posInPacket));
		posInPacket += 1;
		_backgrounds.push_back(backgroundsTemp);
	}
}

PacketBackgrounds::~PacketBackgrounds()
{
}

std::vector<DataBackground *> PacketBackgrounds::getBackgrounds() const
{
	return (_backgrounds);
}