//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketSound.hh"

PacketSound::PacketSound(const std::string & sound)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::SOUND;
	_sound = sound;

	ps.add((uint16_t)_sound.size());
	ps.add(_sound);
	dataPacketSize += 2 + _sound.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketSound::PacketSound(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::SOUND;
	_size = pd.getPacketSize();

	_sound = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
}

PacketSound::~PacketSound()
{
}

std::string PacketSound::getSound() const
{
	return (_sound);
}