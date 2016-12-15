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
	_tickId = 0;
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
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

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

bool PacketMusic::isTcp() const
{
	return (false);
}

bool PacketMusic::isUdp() const
{
	return (true);
}