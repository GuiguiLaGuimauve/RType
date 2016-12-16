//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Fri Dec 16 10:31:15 2016 lecoq
//

#include	"PacketFactory.hh"

PacketFactory::PacketFactory()
{
  /*  _mapData["error"] = &PacketFactory::getError;
  _mapData["welcome"] = &PacketFactory::getWelcome;
  _mapData["connect"] = &PacketFactory::getConnect;
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

IPacket		*PacketFactory::getPacket(const std::string &p) const
{
  (void)p;
  return (NULL);
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p) const
{
  (void)p;
  return (NULL);
}

void		PacketFactory::getPacket(const uint8_t *p) const
{
  (void)p;
}

void		PacketFactory::enable(const std::string &packet)
{
  if (_mapData.find(packet) != _mapData.end())
    _ptr[packet] = _mapData[packet];
}
