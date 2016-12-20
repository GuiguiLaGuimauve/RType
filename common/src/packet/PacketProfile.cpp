//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketProfile.hh"

PacketProfile::PacketProfile(DataPlayer * player)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::PROFILE;
	_tickId = 0;
	_player = player;
	
	ps.add(player->getName());
	dataPacketSize += 2 + (uint32_t)player->getName().size();

	ps.add(player->getStageSucceed());
	dataPacketSize += 2;
	
	ps.add(player->getGamePlayed());
	dataPacketSize += 2;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketProfile::PacketProfile(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::PROFILE;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_player = new DataPlayer();
	
	_player->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

	_player->setStageSucceed(pd.get16(posInPacket));
	posInPacket += 2;

	_player->setGamePlayed(pd.get16(posInPacket));
	posInPacket += 2;
}

PacketProfile::~PacketProfile()
{
}

bool PacketProfile::isTcp() const
{
	return (true);
}

bool PacketProfile::isUdp() const
{
	return (false);
}