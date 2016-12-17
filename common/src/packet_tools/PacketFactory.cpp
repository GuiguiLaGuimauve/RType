//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Sat Dec 17 16:31:09 2016 lecoq
//

#include	"PacketFactory.hh"

PacketFactory::PacketFactory()
{
  _pkt1 = new PacketContener<void>(this);
  _pkt2 = new PacketContener<const std::string &, const IPacket::PacketType &>(this);
  _pkt3 = new PacketContener<const std::string &>(this);
  _pkt4 = new PacketContener<const std::vector<DataRoom *> &>(this);
  _pkt5 = new PacketContener<const std::string &, const uint8_t &>(this);
  _pkt6 = new PacketContener<const uint8_t *, const uint16_t &>(this);
  _pkt7 = new PacketContener<const std::vector<DataPlayer *> &, const uint8_t &>(this);
  /*_mapData["watchgame"] = &PacketFactory::watchGame;
  _mapData["login"] = &PacketFactory::login;
  _mapData["register"] = &PacketFactory::tryRegister;
  _mapData["logout"] = &PacketFactory::logout;
  _mapData["disconnect"] = &PacketFactory::disconnect;
  _mapData["move"] = &PacketFactory::move;
  _mapData["shoot"] = &PacketFactory::shoot;
  _mapData["players"] = &PacketFactory::players;
  _mapData["shoots"] = &PacketFactory::shoots;
  _mapData["ennemy"] = &PacketFactory::ennemy;
  _mapData["background"] = &PacketFactory::background;
  _mapData["music"] = &PacketFactory::music;
  _mapData["sound"] = &PacketFactory::sound;*/
}

PacketFactory::~PacketFactory()
{
  delete _pkt1;
  delete _pkt2;
  delete _pkt3;
  delete _pkt4;
  delete _pkt5;
  delete _pkt6;
  delete _pkt7;
}

IPacket		*PacketFactory::getPacket(const std::string &p) 
{
  return (_pkt1->getPacket(p));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p) 
{
  return (_pkt1->getPacket(p));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m, const IPacket::PacketType &t) 
{
  return (_pkt2->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m, const IPacket::PacketType &t) 
{
  return (_pkt2->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m) 
{
  return (_pkt3->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m) 
{
  return (_pkt3->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataRoom *> &m) 
{
  return (_pkt4->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataRoom *> &m) 
{
  return (_pkt4->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m, const uint8_t &t) 
{
  return (_pkt5->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m, const uint8_t &t) 
{
  return (_pkt5->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const uint8_t *m, const uint16_t &t) 
{
  return (_pkt6->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const uint8_t *m, const uint16_t &t) 
{
  return (_pkt6->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataPlayer *> &m, const uint8_t &t) 
{
  return (_pkt7->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataPlayer *> &m, const uint8_t &t) 
{
  return (_pkt7->getPacket(p, m, t));
}

void		PacketFactory::getPacket(const uint8_t *p) const
{
  (void)p;
}

void		PacketFactory::enable(const std::string &packet)
{
  _pkt1->enable(packet);
  _pkt2->enable(packet);
  _pkt3->enable(packet);
  _pkt4->enable(packet);
  _pkt5->enable(packet);
  _pkt6->enable(packet);
  _pkt7->enable(packet);
}

IPacket		*PacketFactory::getError(const std::string &m, const IPacket::PacketType &p) 
{
  IPacket	*ret = new PacketError(m, p);

  return (ret);
}

IPacket		*PacketFactory::getWelcome(const std::string &m) 
{
  IPacket	*ret = new PacketWelcome(m);

  return (ret);
}

IPacket		*PacketFactory::joinRoom(const std::string &m) 
{
  IPacket	*ret = NULL; /*new PacketJoinRoom(m);*/
  (void)m;
  return (ret);
}

IPacket		*PacketFactory::joinError(const std::string &m) 
{
  IPacket	*ret = new PacketJoinError(m);

  return (ret);
}

IPacket		*PacketFactory::startGame(const std::string &m) 
{
  IPacket	*ret = NULL; /*new PacketStartGame(m);*/
  (void)m;
  return (ret);
}

IPacket		*PacketFactory::startError(const std::string &m) 
{
  IPacket	*ret = NULL; /*new PacketStartError(m);*/
  (void)m;
  return (ret);
}

IPacket		*PacketFactory::leaveRoom(const std::string &m) 
{
  IPacket	*ret = NULL; /*new PacketLeaveRoom(m);*/
  (void)m;
  return (ret);
}

IPacket		*PacketFactory::getConnect() 
{
  IPacket	*ret = new PacketConnect;

  return (ret);
}

IPacket		*PacketFactory::udpDataFree() 
{
  IPacket	*ret = new PacketUdpDataFree;

  return (ret);
}

IPacket		*PacketFactory::getRooms(const std::vector<DataRoom *> &d) 
{
  IPacket	*ret = new PacketRooms(d);

  return (ret);
}

IPacket		*PacketFactory::createRoom(const std::string &m, const uint8_t &t) 
{
  IPacket	*ret = NULL;/*= new PacketCreateRoom(m, t);*/
  (void)m;
  (void)t;

  return (ret);
}

IPacket		*PacketFactory::udpData(const uint8_t *m, const uint16_t &t) 
{
  IPacket	*ret = new PacketUdpData(m, t);

  return (ret);
}

IPacket		*PacketFactory::getDataRoom(const std::vector<DataPlayer *> &m, const uint8_t &t)
{
  IPacket	*ret = NULL; /* = new PacketRoomData(m, t);*/

  (void)m;
  (void)t;

  return (ret);  
}
