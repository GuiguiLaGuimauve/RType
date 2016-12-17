//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Sat Dec 17 01:08:18 2016 lecoq
//

#include	"PacketFactory.hh"

PacketFactory::PacketFactory()
{
  _mapData2["error"] = &PacketFactory::getError;
  _mapData3["welcome"] = &PacketFactory::getWelcome;
  /*_mapData["connect"] = &PacketFactory::getConnect;
  _mapData["getrooms"] = &PacketFactory::getRooms;
  _mapData["createroom"] = &PacketFactory::createRoom;
  _mapData["joinroom"] = &PacketFactory::joinRoom;
  _mapData["joinerror"] = &PacketFactory::joinError;
  _mapData["startgame"] = &PacketFactory::startGame;
  _mapData["starterror"] = &PacketFactory::startError;
  _mapData["leaveroom"] = &PacketFactory::leaveRoom;
  _mapData["udpdata"] = &PacketFactory::udpData;
  _mapData["udpdatafree"] = &PacketFactory::udpDataFree;
  _mapData["dataroom"] = &PacketFactory::dataRoom;
  _mapData["watchgame"] = &PacketFactory::watchGame;
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
  if (_ptr1.find(p) != _ptr1.end())
    return ((this->*_ptr1[p])());
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p) 
{
  if (_mapConverter1.find(p) != _mapConverter1.end())
    return (getPacket(_mapConverter1[p]));
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m, const IPacket::PacketType &t) 
{
  if (_ptr2.find(p) != _ptr2.end())
    return ((this->*_ptr2[p])(m, t));
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m, const IPacket::PacketType &t) 
{
  if (_mapConverter2.find(p) != _mapConverter2.end())
    return (getPacket(_mapConverter2[p], m, t));
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const std::string &p, const std::string &m) 
{
  if (_ptr3.find(p) != _ptr3.end())
    return ((this->*_ptr3[p])(m));
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p, const std::string &m) 
{
  if (_mapConverter3.find(p) != _mapConverter3.end())
    return (getPacket(_mapConverter3[p], m));
  return (NULL);
}

void		PacketFactory::getPacket(const uint8_t *p) const
{
  (void)p;
}

void		PacketFactory::enable(const std::string &packet)
{
  if (_mapData1.find(packet) != _mapData1.end())
    _ptr1[packet] = _mapData1[packet];
  if (_mapData2.find(packet) != _mapData2.end())
    _ptr2[packet] = _mapData2[packet];
  if (_mapData3.find(packet) != _mapData3.end())
    _ptr3[packet] = _mapData3[packet];
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
