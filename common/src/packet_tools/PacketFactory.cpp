//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Tue Dec 20 13:32:01 2016 lecoq
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
  _pkt7 = new PacketContener<const DataRoom *>(this);
  _pkt8 = new PacketContener<const std::string &, const std::string &>(this);
  _pkt9 = new PacketContener<const uint16_t &, const uint16_t &>(this);
  _pkt10 = new PacketContener<const std::vector<DataShoot *> &>(this);
  _pkt11 = new PacketContener<const std::vector<DataEnnemy *> &>(this);
  _pkt12 = new PacketContener<const std::vector<DataBackground *> &>(this);
  _pkt13 = new PacketContener<const std::vector<DataPlayer *> &>(this);
  _pkt14 = new PacketContener<const DataPlayer *>(this);
  _pktDeserialiser = new PacketContener<const uint8_t *>(this);
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
  delete _pkt8;
  delete _pkt9;
  delete _pkt10;
  delete _pkt11;
  delete _pkt12;
  delete _pkt13;
  delete _pkt14;
  delete _pktDeserialiser;
}

bool		PacketFactory::isEnableSerialise(const std::string &s)
{
  if (_pkt1->isEnable(s) == true || _pkt2->isEnable(s) == true || _pkt3->isEnable(s) == true
      || _pkt4->isEnable(s) == true || _pkt5->isEnable(s) == true || _pkt6->isEnable(s) == true
      || _pkt7->isEnable(s) == true || _pkt8->isEnable(s) == true || _pkt9->isEnable(s) == true
      || _pkt10->isEnable(s) == true || _pkt11->isEnable(s) == true || _pkt12->isEnable(s) == true || _pkt13->isEnable(s) == true)
    return (true);
  else
    return (false);
}

bool		PacketFactory::isEnableDeserialise(const std::string &s)
{
  return (_pktDeserialiser->isEnable(s));
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

IPacket		*PacketFactory::getPacket(const std::string &p, const DataRoom *m) 
{
  return (_pkt7->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const DataRoom *m) 
{
  return (_pkt7->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m, const std::string &t) 
{
  return (_pkt8->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m, const std::string &t) 
{
  return (_pkt8->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const uint16_t &m, const uint16_t &t) 
{
  return (_pkt9->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const uint16_t &m, const uint16_t &t) 
{
  return (_pkt9->getPacket(p, m, t));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataShoot *> &m) 
{
  return (_pkt10->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataShoot *> &m) 
{
  return (_pkt10->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataEnnemy *> &m) 
{
  return (_pkt11->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataEnnemy *> &m) 
{
  return (_pkt11->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataBackground *> &m) 
{
  return (_pkt12->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataBackground *> &m) 
{
  return (_pkt12->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataPlayer *> &m) 
{
  return (_pkt13->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataPlayer *> &m) 
{
  return (_pkt13->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const std::string &p, const DataPlayer *m) 
{
  return (_pkt14->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const DataPlayer *m) 
{
  return (_pkt14->getPacket(p, m));
}

IPacket		*PacketFactory::getPacket(const uint8_t *p) const
{
  return (_pktDeserialiser->getPacket(p));
}

void		PacketFactory::enableSerialiser(const std::string &packet)
{
  _pkt1->enable(packet);
  _pkt2->enable(packet);
  _pkt3->enable(packet);
  _pkt4->enable(packet);
  _pkt5->enable(packet);
  _pkt6->enable(packet);
  _pkt7->enable(packet);
  _pkt8->enable(packet);
  _pkt9->enable(packet);
  _pkt10->enable(packet);
  _pkt11->enable(packet);
  _pkt12->enable(packet);
  _pkt13->enable(packet);
  _pkt14->enable(packet);
}

void		PacketFactory::enableDeserialiser(const std::string &packet)
{
  _pktDeserialiser->enable(packet);
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
  IPacket	*ret = new PacketJoinRoom(m);

  return (ret);
}

IPacket		*PacketFactory::joinError(const std::string &m) 
{
  IPacket	*ret = new PacketJoinError(m);

  return (ret);
}

IPacket		*PacketFactory::startGame(const std::string &m) 
{
  IPacket	*ret = new PacketStartGame(m);

  return (ret);
}

IPacket		*PacketFactory::startError(const std::string &m) 
{
  IPacket	*ret = new PacketStartError(m);

  return (ret);
}

IPacket		*PacketFactory::leaveRoom(const std::string &m) 
{
  IPacket	*ret = new PacketLeaveRoom(m);

  return (ret);
}

IPacket		*PacketFactory::watchGame(const std::string &m) 
{
  IPacket	*ret = new PacketWatchGame(m);

  return (ret);
}

IPacket		*PacketFactory::music(const std::string &m) 
{
  IPacket	*ret = new PacketMusic(m);

  return (ret);
}

IPacket		*PacketFactory::sound(const std::string &m) 
{
  IPacket	*ret = new PacketSound(m);

  return (ret);
}

IPacket		*PacketFactory::askRoomData(const std::string &m) 
{
  IPacket	*ret = new PacketAskRoomData(m);

  return (ret);
}

IPacket		*PacketFactory::accept(const std::string &m) 
{
  IPacket	*ret = new PacketAccept(m);

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

IPacket		*PacketFactory::logout() 
{
  IPacket	*ret = new PacketLogout;

  return (ret);
}

IPacket		*PacketFactory::ping() 
{
  IPacket	*ret = new PacketPing;

  return (ret);
}

IPacket		*PacketFactory::pong() 
{
  IPacket	*ret = new PacketPong;

  return (ret);
}

IPacket		*PacketFactory::disconnect() 
{
  IPacket	*ret = new PacketDisconnect;

  return (ret);
}

IPacket		*PacketFactory::getRooms(const std::vector<DataRoom *> &d) 
{
  IPacket	*ret = new PacketRooms(d);

  return (ret);
}

IPacket		*PacketFactory::createRoom(const std::string &m, const uint8_t &t) 
{
  IPacket	*ret = new PacketCreateRoom(m, t);

  return (ret);
}

IPacket		*PacketFactory::udpData(const uint8_t *m, const uint16_t &t) 
{
  IPacket	*ret = new PacketUdpData(m, t);

  return (ret);
}

IPacket		*PacketFactory::getDataRoom(const DataRoom *m)
{
  IPacket	*ret= new PacketRoomData(m);

  return (ret);  
}

IPacket		*PacketFactory::login(const std::string &m, const std::string &t)
{
  IPacket	*ret= new PacketLogin(m, t);

  return (ret);  
}

IPacket		*PacketFactory::tryRegister(const std::string &m, const std::string &t)
{
  IPacket	*ret= new PacketRegister(m, t);

  return (ret);  
}

IPacket		*PacketFactory::positionPlayer(const uint16_t &m, const uint16_t &t)
{
  IPacket	*ret= new PacketPositionPlayer(m, t);

  return (ret);  
}

IPacket		*PacketFactory::shoot(const uint16_t &m, const uint16_t &t)
{
  IPacket	*ret= new PacketShoot(m, t);

  return (ret);  
}

IPacket		*PacketFactory::getShoots(const std::vector<DataShoot *> &m)
{
  IPacket	*ret= new PacketShoots(m);

  return (ret);  
}

IPacket		*PacketFactory::getEnnemies(const std::vector<DataEnnemy *> &m)
{
  IPacket	*ret= new PacketEnnemies(m);

  return (ret);  
}

IPacket		*PacketFactory::getBackgrounds(const std::vector<DataBackground *> &m)
{
  IPacket	*ret= new PacketBackgrounds(m);

  return (ret);  
}

IPacket		*PacketFactory::getPlayers(const std::vector<DataPlayer *> &m)
{
  IPacket	*ret= new PacketPlayers(m);

  return (ret);  
}

IPacket		*PacketFactory::getProfile(const DataPlayer *m)
{
  IPacket	*ret= new PacketProfile(m);

  return (ret);  
}


IPacket		*PacketFactory::revErrorPacket(const uint8_t *p)
{
  IPacket	*pa = new PacketError(p);
  return (pa);
}

IPacket		*PacketFactory::revWelcome(const uint8_t *p)
{
  IPacket *pa = new PacketWelcome(p);
  return (pa);
}

IPacket		*PacketFactory::revConnect(const uint8_t *p)
{
  IPacket *pa = new PacketConnect(p);
  return (pa);
}

IPacket		*PacketFactory::revRooms(const uint8_t *p)
{
  IPacket *pa = new PacketRooms(p);
  return (pa); 
}

IPacket		*PacketFactory::revCreateRoom(const uint8_t *p)
{
  IPacket *pa = new PacketCreateRoom(p);
  return (pa); 
}

IPacket		*PacketFactory::revJoinRoom(const uint8_t *p)
{
  IPacket *pa = new PacketJoinRoom(p);
  return (pa); 
}

IPacket		*PacketFactory::revJoinError(const uint8_t *p)
{
  IPacket *pa = new PacketJoinError(p);
  return (pa);
}

IPacket		*PacketFactory::revStartGame(const uint8_t *p)
{
  IPacket *pa = new PacketStartGame(p);
  return (pa); 
}

IPacket		*PacketFactory::revStartError(const uint8_t *p)
{
  IPacket *pa = new PacketStartError(p);
  return (pa);
  
}

IPacket		*PacketFactory::revLeaveRoom(const uint8_t *p)
{
  IPacket *pa = new PacketLeaveRoom(p);
  return (pa);
}

IPacket		*PacketFactory::revUdpData(const uint8_t *p)
{
  IPacket *pa = new PacketUdpData(p);
  return (pa);
}

IPacket		*PacketFactory::revUdpDataFree(const uint8_t *p)
{
  IPacket *pa = new PacketUdpDataFree(p);
  return (pa);
}

IPacket		*PacketFactory::revRoomData(const uint8_t *p)
{
  IPacket *pa = new PacketRoomData(p);
  return (pa);  
}

IPacket		*PacketFactory::revWatchGame(const uint8_t *p)
{
  IPacket *pa = new PacketWatchGame(p);
  return (pa);
}

IPacket		*PacketFactory::revLogin(const uint8_t *p)
{
  IPacket *pa = new PacketLogin(p);
  return (pa);
}

IPacket		*PacketFactory::revRegister(const uint8_t *p)
{
  IPacket *pa = new PacketRegister(p);
  return (pa);
}

IPacket		*PacketFactory::revLogout(const uint8_t *p)
{
  IPacket *pa = new PacketLogout(p);
  return (pa);
}

IPacket		*PacketFactory::revDisconnect(const uint8_t *p)
{
  IPacket *pa = new PacketDisconnect(p);
  return (pa);
}

IPacket		*PacketFactory::revShoot(const uint8_t *p)
{
  IPacket *pa = new PacketShoot(p);
  return (pa);  
}

IPacket		*PacketFactory::revPositionPlayer(const uint8_t *p)
{
  IPacket *pa = new PacketPositionPlayer(p);
  return (pa);
}

IPacket		*PacketFactory::revPlayers(const uint8_t *p)
{
  IPacket *pa = new PacketPlayers(p);
  return (pa);
}

IPacket		*PacketFactory::revShoots(const uint8_t *p)
{
  IPacket *pa = new PacketShoots(p);
  return (pa);
}

IPacket		*PacketFactory::revEnnemies(const uint8_t *p)
{
  IPacket *pa = new PacketEnnemies(p);
  return (pa);
}


IPacket		*PacketFactory::revBackgrounds(const uint8_t *p)
{
  IPacket *pa = new PacketBackgrounds(p);
  return (pa);
}

IPacket		*PacketFactory::revMusic(const uint8_t *p)
{
  IPacket *pa = new PacketMusic(p);
  return (pa);  
}

IPacket		*PacketFactory::revSound(const uint8_t *p)
{
  IPacket *pa = new PacketSound(p);
  return (pa);  
}

IPacket		*PacketFactory::revPing(const uint8_t *p)
{
  IPacket *pa = new PacketPing(p);
  return (pa);
  
}

IPacket		*PacketFactory::revPong(const uint8_t *p)
{
  IPacket *pa = new PacketPong(p);
  return (pa);
}

IPacket		*PacketFactory::revAskRoomData(const uint8_t *p)
{
  IPacket *pa = new PacketAskRoomData(p);
  return (pa);
}

IPacket		*PacketFactory::revAccept(const uint8_t *p)
{
  IPacket *pa = new PacketAccept(p);
  return (pa);
}

IPacket		*PacketFactory::revProfile(const uint8_t *p)
{
  IPacket *pa = new PacketProfile(p);
  return (pa);
}
