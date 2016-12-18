//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Sun Dec 18 14:11:50 2016 lecoq
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
  delete _pktDeserialiser;
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

void		PacketFactory::getPacket(const uint8_t *p) const
{
  (void)p;
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

IPacket		*PacketFactory::move(const uint16_t &m, const uint16_t &t)
{
  IPacket	*ret= new PacketMove(m, t);

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

void		PacketFactory::revErrorPacket(const uint8_t *p)
{
  PacketError	pa(p);
  throw CatchIt<PacketError>(pa);
}

void		PacketFactory::revWelcome(const uint8_t *p)
{
  PacketWelcome pa(p);
  throw CatchIt<PacketWelcome>(pa);
}

void		PacketFactory::revConnect(const uint8_t *p)
{
  PacketConnect pa(p);
  throw CatchIt<PacketConnect>(pa);
}

void		PacketFactory::revRooms(const uint8_t *p)
{
  PacketRooms pa(p);
  throw CatchIt<PacketRooms>(pa); 
}

void		PacketFactory::revCreateRoom(const uint8_t *p)
{
  PacketCreateRoom pa(p);
  throw CatchIt<PacketCreateRoom>(pa); 
}

void		PacketFactory::revJoinRoom(const uint8_t *p)
{
  PacketJoinRoom pa(p);
  throw CatchIt<PacketJoinRoom>(pa); 
}

void		PacketFactory::revJoinError(const uint8_t *p)
{
  PacketJoinError pa(p);
  throw CatchIt<PacketJoinError>(pa);
}

void		PacketFactory::revStartGame(const uint8_t *p)
{
  PacketStartGame pa(p);
  throw CatchIt<PacketStartGame>(pa); 
}

void		PacketFactory::revStartError(const uint8_t *p)
{
  PacketStartError pa(p);
  throw CatchIt<PacketStartError>(pa);
  
}

void		PacketFactory::revLeaveRoom(const uint8_t *p)
{
  PacketLeaveRoom pa(p);
  throw CatchIt<PacketLeaveRoom>(pa);
}

void		PacketFactory::revUdpData(const uint8_t *p)
{
  PacketUdpData pa(p);
  throw CatchIt<PacketUdpData>(pa);
}

void		PacketFactory::revUdpDataFree(const uint8_t *p)
{
  PacketUdpDataFree pa(p);
  throw CatchIt<PacketUdpDataFree>(pa);
}

void		PacketFactory::revRoomData(const uint8_t *p)
{
  PacketRoomData pa(p);
  throw CatchIt<PacketRoomData>(pa);  
}

void		PacketFactory::revWatchGame(const uint8_t *p)
{
  PacketWatchGame pa(p);
  throw CatchIt<PacketWatchGame>(pa);
}

void		PacketFactory::revLogin(const uint8_t *p)
{
  PacketLogin pa(p);
  throw CatchIt<PacketLogin>(pa);
}

void		PacketFactory::revRegister(const uint8_t *p)
{
  PacketRegister pa(p);
  throw CatchIt<PacketRegister>(pa);
}

void		PacketFactory::revLogout(const uint8_t *p)
{
  PacketLogout pa(p);
  throw CatchIt<PacketLogout>(pa);
}

void		PacketFactory::revDisconnect(const uint8_t *p)
{
  PacketDisconnect pa(p);
  throw CatchIt<PacketDisconnect>(pa);
}

void		PacketFactory::revShoot(const uint8_t *p)
{
  PacketShoot pa(p);
  throw CatchIt<PacketShoot>(pa);  
}

void		PacketFactory::revMove(const uint8_t *p)
{
  PacketMove pa(p);
  throw CatchIt<PacketMove>(pa);
}

void		PacketFactory::revPlayers(const uint8_t *p)
{
  PacketPlayers pa(p);
  throw CatchIt<PacketPlayers>(pa);
}

void		PacketFactory::revShoots(const uint8_t *p)
{
  PacketShoots pa(p);
  throw CatchIt<PacketShoots>(pa);
}

void		PacketFactory::revEnnemies(const uint8_t *p)
{
  PacketEnnemies pa(p);
  throw CatchIt<PacketEnnemies>(pa);
}


void		PacketFactory::revBackgrounds(const uint8_t *p)
{
  PacketBackgrounds pa(p);
  throw CatchIt<PacketBackgrounds>(pa);
}

void		PacketFactory::revMusic(const uint8_t *p)
{
  PacketMusic pa(p);
  throw CatchIt<PacketMusic>(pa);  
}

void		PacketFactory::revSound(const uint8_t *p)
{
  PacketSound pa(p);
  throw CatchIt<PacketSound>(pa);  
}

void		PacketFactory::revPing(const uint8_t *p)
{
  PacketPing pa(p);
  throw CatchIt<PacketPing>(pa);
  
}

void		PacketFactory::revPong(const uint8_t *p)
{
  PacketPong pa(p);
  throw CatchIt<PacketPong>(pa);
}
