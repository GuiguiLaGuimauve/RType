//
// PacketPlayerData.cpp for PacketPlayerData in /home/lecoq/RType
// 
// Made by Lecoq Maxime
// Login   <lecoq@lecoq-epitechHP>
// 
// Started on  Mon Jan  2 03:36:12 2017 Lecoq Maxime
// Last update Mon Jan  2 03:40:49 2017 Lecoq Maxime
//

#include "PacketPlayerData.hh"

PacketPlayerData::PacketPlayerData(const uint16_t &x, const uint16_t &y, const std::vector<DataShoot *> &s)
{
  PacketSerializer ps;
  uint32_t dataPacketSize = 0;

  _type = IPacket::PacketType::PLAYERDATA;
  _tickId = 0;
  _x = x;
  _y = y;
  _shoots = s;

  ps.add(_x);
  dataPacketSize += 2;

  ps.add(_y);
  dataPacketSize += 2;

  ps.add((uint16_t)_shoots.size());
  dataPacketSize += 2;
  for (uint64_t i = 0; i < _shoots.size(); i++)
    {
      ps.add((uint16_t)(_shoots[i]->getX()));
      dataPacketSize += 2;

      ps.add((uint16_t)(_shoots[i]->getY()));
      dataPacketSize += 2;

      ps.add(_shoots[i]->getDamage());
      dataPacketSize += 1;
    }
  
  _data = ps.getPacket();
  _size = dataPacketSize;
}

PacketPlayerData::~PacketPlayerData() {}

PacketPlayerData::PacketPlayerData(const uint8_t *data)
{
  PacketDeserializer pd(data);
  uint32_t posInPacket = 0;    

  _type = IPacket::PacketType::PLAYERDATA;
  _size = pd.getPacketSize();
  _tickId = pd.getPacketTickId();

  _data = new uint8_t[_size];
  for (uint32_t a = 0; a < _size; a++)
    _data[a] = data[a + 9];

  _x = pd.get16(posInPacket);
  posInPacket += 2;

  _y = pd.get16(posInPacket);
  posInPacket += 2;

  uint64_t shootsLength = (uint16_t)pd.get16(posInPacket);
  posInPacket += 2;
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

bool PacketPlayerData::isTcp() const { return (false); }

bool PacketPlayerData::isUdp() const { return (true); }

uint16_t PacketPlayerData::getX() const { return (_x); }

uint16_t PacketPlayerData::getY() const { return (_y); }

std::vector<DataShoot *>  PacketPlayerData::getShoots() const { return (_shoots); }
