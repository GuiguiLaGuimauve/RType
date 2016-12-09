//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketMusic.hh"

PacketMusic::PacketMusic(const std::string & music)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::MUSIC;
	_music = music;

	ps.add((uint16_t)_music.size());
	ps.add(_music);
	dataPacketSize += 2 + _music.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketMusic::PacketMusic(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::MUSIC;
	_size = pd.getPacketSize();

	_music = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
}

PacketMusic::~PacketMusic()
{
}

std::string PacketMusic::getMusic() const
{
	return (_music);
}