//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketUdpData.hh"

PacketUdpData::PacketUdpData(const uint8_t *ip, const uint16_t & port)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::UDP_DATA;
	_tickId = 0;
	_ip[0] = ip[0];
	_ip[1] = ip[1];
	_ip[2] = ip[2];
	_ip[3] = ip[3];
	_port = port;

	ps.add(_ip[0]);
	ps.add(_ip[1]);
	ps.add(_ip[2]);
	ps.add(_ip[3]);
	dataPacketSize += 4;

	ps.add(_port);
	dataPacketSize += 2;

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketUdpData::PacketUdpData(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::UDP_DATA;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_ip[0] = pd.get8(posInPacket);
	posInPacket += 1;
	_ip[1] = pd.get8(posInPacket);
	posInPacket += 1;
	_ip[2] = pd.get8(posInPacket);
	posInPacket += 1;
	_ip[3] = pd.get8(posInPacket);
	posInPacket += 1;

	_port = pd.get16(posInPacket);
	posInPacket += 2;
}

PacketUdpData::~PacketUdpData()
{
}

uint8_t *PacketUdpData::getIp()
{
	return (_ip);
}

uint16_t PacketUdpData::getPort() const
{
	return (_port);
}

bool PacketUdpData::isTcp() const
{
	return (true);
}

bool PacketUdpData::isUdp() const
{
	return (false);
}