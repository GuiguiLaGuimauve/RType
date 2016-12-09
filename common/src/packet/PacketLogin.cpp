//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketLogin.hh"

PacketLogin::PacketLogin(const std::string & login, const std::string & password)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::LOGIN;
	_login = login;
	_password = password;

	ps.add((uint16_t)_login.size());
	ps.add(_login);
	dataPacketSize += 2 + _login.size();

	ps.add((uint16_t)_password.size());
	ps.add(_password);
	dataPacketSize += 2 + _password.size();

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketLogin::PacketLogin(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::LOGIN;
	_size = pd.getPacketSize();

	_login = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);

	_password = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);
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