//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketError.hh"

PacketError::PacketError(const std::string & message, const IPacket::PacketType & errorType)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::ERROR;
	_tickId = 0;
	_message = message;
	_errorType = errorType;

	ps.add((uint16_t)_message.size());
	ps.add(_message);
	dataPacketSize += 2 + _message.size();

	ps.add((uint8_t)_errorType);
	dataPacketSize += 1;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketError::PacketError(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::ERROR;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
		_data[a] = data[a + 9];

	_message = pd.getString(posInPacket + 2, pd.get16(posInPacket));
	posInPacket += 2 + pd.get16(posInPacket);

	_errorType = (IPacket::PacketType)pd.get8(posInPacket);
	posInPacket += 1;
}

PacketError::~PacketError()
{
}

std::string PacketError::getMessage() const
{
	return (_message);
}

IPacket::PacketType PacketError::getErrorType() const
{
	return (_errorType);
}

bool PacketError::isTcp() const
{
	return (true);
}

bool PacketError::isUdp() const
{
	return (false);
}