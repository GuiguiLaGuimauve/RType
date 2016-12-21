//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketChatMessage.hh"

PacketChatMessage::PacketChatMessage(const std::string & login, const std::string & message)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::CHAT_MESSAGE;
	_tickId = 0;
	_login = login;
	_message = message;

	ps.add((uint16_t)_login.size());
	ps.add(_login);
	dataPacketSize += 2 + (uint32_t)_login.size();

	ps.add((uint16_t)_message.size());
	ps.add(_message);
	dataPacketSize += 2 + (uint32_t)_message.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketChatMessage::PacketChatMessage(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::CHAT_MESSAGE;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_login = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

	_message = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
}

PacketChatMessage::~PacketChatMessage()
{
}

std::string PacketChatMessage::getLogin() const
{
	return (_login);
}

std::string PacketChatMessage::getMessage() const
{
	return (_message);
}

bool PacketChatMessage::isTcp() const
{
	return (true);
}

bool PacketChatMessage::isUdp() const
{
	return (false);
}