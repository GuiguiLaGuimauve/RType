//
// This file was auto-generated, please do not edit it !
//

#include <iostream>
#include "PacketShootsClient.hh"

PacketShootsClient::PacketShootsClient(const std::vector<DataShoot *> & shoots)
{
	PacketSerializer ps;
	uint32_t dataPacketSize = 0;

	_type = IPacket::PacketType::SHOOTS_CLIENT;
	_tickId = 0;
	_shoots = shoots;

	ps.add((uint16_t)_shoots.size());
	dataPacketSize += 2;
	for (uint64_t i = 0; i < _shoots.size(); i++)
	{
		ps.add(_shoots[i]->getX());
		dataPacketSize += 2;

		ps.add(_shoots[i]->getY());
		dataPacketSize += 2;

		ps.add(_shoots[i]->getDamage());
		dataPacketSize += 1;
	}

	_data = ps.getPacket();
	_size = dataPacketSize;
}

PacketShootsClient::PacketShootsClient(const uint8_t *data)
{
	PacketDeserializer pd(data);
	uint32_t posInPacket = 0;

	_type = IPacket::PacketType::SHOOTS_CLIENT;
	_size = pd.getPacketSize();
	_tickId = pd.getPacketTickId();

	_data = new uint8_t[_size];
	for (uint32_t a = 0; a < _size; a++)
	  {
	    _data[a] = data[a + 9];
	    std::cout << (int)_data[a] << " ";
	  }
	std::cout << std::endl;

	uint64_t shootsLength = (uint16_t)pd.get16(posInPacket);
	posInPacket += 2;
	std::cout << "shootClientlenght " << shootsLength << std::endl;
	for (uint64_t i = 0; i < shootsLength; i++)
	{
		DataShoot *shootsTemp = new DataShoot();

		shootsTemp->setX(pd.get16(posInPacket));
		posInPacket += 2;

		shootsTemp->setY(pd.get16(posInPacket));
		posInPacket += 2;

		shootsTemp->setDamage(pd.get8(posInPacket));
		posInPacket += 1;
		_shoots.push_back(shootsTemp);
	}
}

PacketShootsClient::~PacketShootsClient()
{
}

std::vector<DataShoot *> PacketShootsClient::getShoots() const
{
	return (_shoots);
}

bool PacketShootsClient::isTcp() const
{
	return (false);
}

bool PacketShootsClient::isUdp() const
{
	return (true);
}
