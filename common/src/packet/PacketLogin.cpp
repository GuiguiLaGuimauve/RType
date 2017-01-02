//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketLogin.hh"

PacketLogin::PacketLogin(const std::string & login, const std::string & password)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;
	Crypt	cr;
	
	_type = IPacket::PacketType::LOGIN;
	_tickId = 0;
	_login = login;
	_password = cr._sha1(password);

	ps.add((uint16_t)_login.size());
	ps.add(_login);
	dataPacketSize += 2 + (uint32_t)_login.size();

	ps.add((uint16_t)_password.size());
	ps.add(_password);
	dataPacketSize += 2 + (uint32_t)_password.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketLogin::PacketLogin(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::LOGIN;
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

PacketLogin::~PacketLogin()
{
}

std::string PacketLogin::getLogin() const
{
	return (_login);
}

std::string PacketLogin::getPassword() const
{
	return (_password);
}

bool PacketLogin::isTcp() const
{
	return (true);
}

bool PacketLogin::isUdp() const
{
	return (false);
}
