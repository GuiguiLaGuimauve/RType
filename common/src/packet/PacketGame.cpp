//
// PacketGame.cpp for PacketGame in /home/lecoq/RType
// 
// Made by Lecoq Maxime
// Login   <lecoq@lecoq-epitechHP>
// 
// Started on  Mon Jan  2 00:03:04 2017 Lecoq Maxime
// Last update Mon Jan  2 11:18:23 2017 Lecoq Maxime
//

#include "PacketGame.hh"

PacketGame::PacketGame(const std::vector<DataPlayer *> &p, const std::vector<DataShoot *> &s, const std::vector<DataEnnemy *> &e, const std::vector<DataBackground *> &b, const uint8_t &l)
{
  PacketSerializer ps;
  uint32_t	dataPacketSize = 0;

  _type = IPacket::PacketType::GAMEDATA;
  _tickId = 0;
  _players = p;
  _ennemies = e;
  _shoots = s;
  _back = b;
  _lvl = l;

  ps.add((uint16_t)_players.size());
  dataPacketSize += 2;
  for (uint64_t i = 0; i < _players.size(); i++)
    {

      ps.add((uint16_t)_players[i]->getName().size());
      ps.add(_players[i]->getName());
      dataPacketSize += 2 + (uint32_t)_players[i]->getName().size();

      ps.add(_players[i]->getId());
      dataPacketSize += 1;

      ps.add((uint16_t)(_players[i]->getX()));
      dataPacketSize += 2;

      ps.add((uint16_t)(_players[i]->getY()));
      dataPacketSize += 2;

      ps.add((uint16_t)_players[i]->getHealth());
      dataPacketSize += 2;
    }

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

      ps.add((uint16_t)_shoots[i]->getSpriteName().size());
      ps.add(_shoots[i]->getSpriteName());
      dataPacketSize += 2 + (uint32_t)_shoots[i]->getSpriteName().size();
    }

  ps.add((uint16_t)_ennemies.size());
  dataPacketSize += 2;
  for (uint64_t i = 0; i < _ennemies.size(); i++)
    {
      ps.add((uint16_t)_ennemies[i]->getSpriteName().size());
      ps.add(_ennemies[i]->getSpriteName());
      dataPacketSize += 2 + (uint32_t)_ennemies[i]->getSpriteName().size();

      ps.add((uint16_t)(_ennemies[i]->getX()));
      dataPacketSize += 2;

      ps.add((uint16_t)(_ennemies[i]->getY()));
      dataPacketSize += 2;
    }
  
  ps.add((uint16_t)_back.size());
  dataPacketSize += 2;
  for (uint64_t i = 0; i < _back.size(); i++)
    {
      ps.add((uint16_t)(_back[i]->getX()));
      dataPacketSize += 2;

      ps.add((uint16_t)(_back[i]->getY()));
      dataPacketSize += 2;
      ps.add((uint16_t)_back[i]->getSpriteName().size());
      ps.add(_back[i]->getSpriteName());
      dataPacketSize += 2 + (uint32_t)_back[i]->getSpriteName().size();
    }
  ps.add((uint8_t)_lvl);
  dataPacketSize++;

  _data = ps.getPacket();
  _size = dataPacketSize; 
}

PacketGame::PacketGame(const uint8_t *data)
{
  PacketDeserializer pd(data);
  uint32_t posInPacket = 0;

  _type = IPacket::PacketType::GAMEDATA;
  _size = pd.getPacketSize();
  _tickId = pd.getPacketTickId();

  _data = new uint8_t[_size];
  for (uint32_t a = 0; a < _size; a++)
    _data[a] = data[a + 9];

  uint64_t playersLength = pd.get16(posInPacket);
  posInPacket += 2;
  for (uint64_t i = 0; i < playersLength; i++)
    {
      DataPlayer *playersTemp = new DataPlayer();

      playersTemp->setName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
      posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

      playersTemp->setId(pd.get8(posInPacket));
      posInPacket += 1;

      playersTemp->setX(pd.get16(posInPacket));
      posInPacket += 2;

      playersTemp->setY(pd.get16(posInPacket));
      posInPacket += 2;

      playersTemp->setHealth(pd.get16(posInPacket));
      posInPacket += 2;
      _players.push_back(playersTemp);
    }

  uint64_t shootsLength = (uint16_t)pd.get16(posInPacket);
  posInPacket += 2;
  for (uint64_t i = 0; i < shootsLength; i++)
    {
      DataShoot *shootsTemp = new DataShoot;

      shootsTemp->setX(pd.get16(posInPacket));
      posInPacket += 2;

      shootsTemp->setY(pd.get16(posInPacket));
      posInPacket += 2;

      shootsTemp->setDamage(pd.get8(posInPacket));
      posInPacket += 1;

      shootsTemp->setSpriteName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
      posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
      _shoots.push_back(shootsTemp);
    }

  uint64_t ennemiesLength = pd.get16(posInPacket);
  posInPacket += 2;
  for (uint64_t i = 0; i < ennemiesLength; i++)
    {
      DataEnnemy *ennemiesTemp = new DataEnnemy();

      ennemiesTemp->setSpriteName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
      posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

      ennemiesTemp->setX(pd.get16(posInPacket));
      posInPacket += 2;

      ennemiesTemp->setY(pd.get16(posInPacket));
      posInPacket += 2;
      _ennemies.push_back(ennemiesTemp);
    }

  uint64_t backLength = pd.get16(posInPacket);
  posInPacket += 2;
  for (uint64_t i = 0; i < backLength; i++)
    {
      DataBackground *backTemp = new DataBackground;

      backTemp->setX((int16_t)pd.get16(posInPacket));
      posInPacket += 2;

      backTemp->setY((int16_t)pd.get16(posInPacket));
      posInPacket += 2;

      backTemp->setSpriteName(pd.getString(posInPacket + 2, pd.get16(posInPacket)));
      posInPacket += 2 + (uint32_t)pd.get16(posInPacket);

      _back.push_back(backTemp);
    }
  _lvl = pd.get8(posInPacket);
  posInPacket += 1; 
}

PacketGame::~PacketGame() {}

bool PacketGame::isTcp() const { return (false); }

bool PacketGame::isUdp() const { return (true); }

std::vector<DataBackground *> PacketGame::getBackgrounds() const
{
  return (_back);
}

std::vector<DataEnnemy *> PacketGame::getEnnemies() const
{
  return (_ennemies);
}

std::vector<DataShoot *> PacketGame::getShoots() const
{
  return (_shoots);
}

std::vector<DataPlayer *> PacketGame::getPlayers() const
{
  return (_players);
}

uint8_t		PacketGame::getLevel() const { return (_lvl); }
