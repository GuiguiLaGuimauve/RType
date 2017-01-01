//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "DataBackground.hpp"
#include "PacketBackgrounds.hh"

PacketBackgrounds::PacketBackgrounds(const std::vector<DataBackground *> & backgrounds)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::BACKGROUNDS;
	_tickId = 0;
	_backgrounds = backgrounds;

	ps.add((uint16_t)_backgrounds.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _backgrounds.size(); i++)
	{
		ps.add((uint16_t)(_backgrounds[i]->getX()));
		dataPacketSize += 2;

		ps.add((uint16_t)(_backgrounds[i]->getY()));
		dataPacketSize += 2;

	        ps.add((uint16_t)_spriteName.size());
	        ps.add(_spriteName);
	        dataPacketSize += 2 + (uint32_t)_spriteName.size();
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
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	uint64_t backgroundsLength = pd.get16(posInPacket);
	posInPacket += 2;
	for (uint64_t i = 0; i < backgroundsLength; i++)
	{
		DataBackground *backgroundsTemp = new DataBackground;
		
		backgroundsTemp->setX((int16_t)pd.get16(posInPacket));
		posInPacket += 2;

		backgroundsTemp->setY((int16_t)pd.get16(posInPacket));
		posInPacket += 2;

		backgroundsTemp->setSpriteName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
		posInPacket += 2 + (uint32_t)pd.get16(posInPacket); 
		
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

bool PacketBackgrounds::isTcp() const
{
	return (false);
}

bool PacketBackgrounds::isUdp() const
{
	return (true);
}
