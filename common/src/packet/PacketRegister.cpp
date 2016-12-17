//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketRegister.hh"

PacketRegister::PacketRegister(const std::string & login, const std::string & password)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::REGISTER;
	_tickId = 0;
	_login = login;
	_password = password;

	ps.add((uint16_t)_login.size());
	ps.add(_login);
	dataPacketSize += 2 + (uint32_t)_login.size();

	ps.add((uint16_t)_password.size());
	ps.add(_password);
	dataPacketSize += 2 + (uint32_t)_password.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketRegister::PacketRegister(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::REGISTER;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_login = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

	_password = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
}

PacketRegister::~PacketRegister()
{
}

std::string PacketRegister::getLogin() const
{
	return (_login);
}

std::string PacketRegister::getPassword() const
{
	return (_password);
}

bool PacketRegister::isTcp() const
{
	return (true);
}

bool PacketRegister::isUdp() const
{
	return (false);
}