//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Sat Dec 17 12:09:23 2016 lecoq
//

#include	"PacketFactory.hh"

PacketFactory::PacketFactory()
{
  /*  _mapData2["error"] = &PacketFactory::getError;
  _mapData3["welcome"] = &PacketFactory::getWelcome;
  _mapData1["connect"] = &PacketFactory::getConnect;
  _mapData4["getrooms"] = &PacketFactory::getRooms;
  _mapData5["createroom"] = &PacketFactory::createRoom;
  _mapData3["joinroom"] = &PacketFactory::joinRoom;
  _mapData3["joinerror"] = &PacketFactory::joinError;
  _mapData3["startgame"] = &PacketFactory::startGame;
  _mapData3["starterror"] = &PacketFactory::startError;
  _mapData3["leaveroom"] = &PacketFactory::leaveRoom;
  _mapData6["udpdata"] = &PacketFactory::udpData;
  _mapData1["udpdatafree"] = &PacketFactory::udpDataFree;
  _mapData7["dataroom"] = &PacketFactory::getDataRoom;*/
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

PacketFactory::~PacketFactory() {}

IPacket		*PacketFactory::getPacket(const std::string &p) 
{
  /*  if (_ptr1.find(p) != _ptr1.end())
      return ((this->*_ptr1[p])());*/
  (void)p;
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p) 
{
  (void)p;
  /*  if (_mapConverter1.find(p) != _mapConverter1.end())
      return (getPacket(_mapConverter1[p]));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m, const IPacket::PacketType &t) 
{
  /*  if (_ptr2.find(p) != _ptr2.end())
      return ((this->*_ptr2[p])(m, t));*/
    (void)p;
      (void)m;
        (void)t;
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m, const IPacket::PacketType &t) 
{
  /*
  if (_mapConverter2.find(p) != _mapConverter2.end())
  return (getPacket(_mapConverter2[p], m, t));*/
  (void)p;

    (void)m;
    (void)t;
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m) 
{
  /*
  if (_ptr3.find(p) != _ptr3.end())
  return ((this->*_ptr3[p])(m));*/
  (void)p;
  (void)m;
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m) 
{
    (void)p;
    (void)m;
    /*if (_mapConverter3.find(p) != _mapConverter3.end())
      return (getPacket(_mapConverter3[p], m));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataRoom *> &m) 
{
  (void)p;
    (void)m;
    /*    if (_ptr4.find(p) != _ptr4.end())
	  return ((this->*_ptr4[p])(m));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataRoom *> &m) 
{
  (void)p;

  (void)m;
  /*if (_mapConverter4.find(p) != _mapConverter4.end())
    return (getPacket(_mapConverter4[p], m));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m, const uint8_t &t) 
{
  (void)p;
    (void)m;
    (void)t;
    /*if (_ptr5.find(p) != _ptr5.end())
      return ((this->*_ptr5[p])(m, t));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m, const uint8_t &t) 
{
  (void)p;
    (void)m;
      (void)t;
      /*  if (_mapConverter5.find(p) != _mapConverter5.end())
	  return (getPacket(_mapConverter5[p], m, t));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const uint8_t *m, const uint16_t &t) 
{
  (void)p;
    (void)m;
      (void)t;
      /*      if (_ptr6.find(p) != _ptr6.end())
	      return ((this->*_ptr6[p])(m, t));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const uint8_t *m, const uint16_t &t) 
{
  /*if (_mapConverter6.find(p) != _mapConverter6.end())
    return (getPacket(_mapConverter6[p], m, t));*/
    (void)p;
      (void)m;
        (void)t;
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::vector<DataPlayer *> &m, const uint8_t &t) 
{
    (void)p;
      (void)m;
        (void)t;
	/*  if (_ptr7.find(p) != _ptr7.end())
	    return ((this->*_ptr7[p])(m, t));*/
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::vector<DataPlayer *> &m, const uint8_t &t) 
{
  (void)p;
    (void)m;
      (void)t;
      /*if (_mapConverter7.find(p) != _mapConverter7.end())
	return (getPacket(_mapConverter7[p], m, t));*/
  return (NULL);
}

void		PacketFactory::getPacket(const uint8_t *p) const
{
  (void)p;
}

void		PacketFactory::enable(const std::string &packet)
{
  /*  if (_mapData1.find(packet) != _mapData1.end())
    _ptr1[packet] = _mapData1[packet];
  if (_mapData2.find(packet) != _mapData2.end())
    _ptr2[packet] = _mapData2[packet];
  if (_mapData3.find(packet) != _mapData3.end())
    _ptr3[packet] = _mapData3[packet];
  if (_mapData4.find(packet) != _mapData4.end())
    _ptr4[packet] = _mapData4[packet];
  if (_mapData5.find(packet) != _mapData5.end())
    _ptr5[packet] = _mapData5[packet];
  if (_mapData6.find(packet) != _mapData6.end())
    _ptr6[packet] = _mapData6[packet];
  if (_mapData7.find(packet) != _mapData7.end())
  _ptr7[packet] = _mapData7[packet];*/
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
