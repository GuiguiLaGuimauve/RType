//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Mon Dec 19 16:34:12 2016 lecoq
//

#ifndef PACKETFACTORY_HH_
# define PACKETFACTORY_HH_

# include	<iostream>
# include	<string>
# include	<map>
# include	"IPacket.hh"
# include	"PacketList.h"
# include	"CatchIt.hpp"

using namespace Packet;

template<typename ... Args>
class PacketContener;

class	PacketFactory
{
public:
  PacketFactory();
  ~PacketFactory();
  bool		isEnableSerialise(const std::string &);
  bool		isEnableDeserialise(const std::string &);
  IPacket	*getPacket(const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &);
  IPacket	*getPacket(const std::string &, const std::string &, const IPacket::PacketType &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &, const IPacket::PacketType &);
  IPacket	*getPacket(const std::string &, const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &);
  IPacket	*getPacket(const std::string &, const std::vector<DataRoom *> &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataRoom *> &);
  IPacket	*getPacket(const std::string &, const std::string &, const uint8_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &, const uint8_t &);
  IPacket	*getPacket(const std::string &, const uint8_t *, const uint16_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const uint8_t *, const uint16_t &);
  IPacket	*getPacket(const std::string &, const DataRoom *);
  IPacket	*getPacket(const IPacket::PacketType &, const DataRoom *);
  IPacket	*getPacket(const std::string &, const std::string &, const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &, const std::string &);
  IPacket	*getPacket(const std::string &, const uint16_t &, const uint16_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const uint16_t &, const uint16_t &);
  IPacket	*getPacket(const std::string &, const std::vector<DataShoot *> &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataShoot *> &);
  IPacket	*getPacket(const std::string &, const std::vector<DataEnnemy *> &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataEnnemy *> &);
  IPacket	*getPacket(const std::string &, const std::vector<DataBackground *> &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataBackground *> &);
  IPacket	*getPacket(const std::string &, const std::vector<DataPlayer *> &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataPlayer *> &);
  
  IPacket *	getPacket(const uint8_t *) const;
  void		enableSerialiser(const std::string &);
  void		enableDeserialiser(const std::string &);

  IPacket	*getConnect();
  IPacket	*udpDataFree();
  IPacket	*logout();
  IPacket	*disconnect();
  IPacket	*ping();
  IPacket	*pong();
  
  IPacket	*getError(const std::string &, const IPacket::PacketType &);
  
  IPacket	*getWelcome(const std::string &);
  IPacket	*joinRoom(const std::string &);
  IPacket	*joinError(const std::string &);
  IPacket	*startGame(const std::string &);
  IPacket	*startError(const std::string &);
  IPacket	*leaveRoom(const std::string &);
  IPacket	*watchGame(const std::string &);
  IPacket	*music(const std::string &);
  IPacket	*sound(const std::string &);
  IPacket	*askRoomData(const std::string &);
  IPacket	*accept(const std::string &);

  IPacket	*getRooms(const std::vector<DataRoom *> &);

  IPacket	*createRoom(const std::string &, const uint8_t &);

  IPacket	*udpData(const uint8_t *, const uint16_t &);

  IPacket	*getDataRoom(const DataRoom *);

  IPacket	*login(const std::string &, const std::string &);
  IPacket	*tryRegister(const std::string &, const std::string &);

  IPacket	*move(const uint16_t &, const uint16_t &);
  IPacket	*shoot(const uint16_t &, const uint16_t &);

  IPacket	*getShoots(const std::vector<DataShoot *>&);

  IPacket	*getEnnemies(const std::vector<DataEnnemy *>&);

  IPacket	*getBackgrounds(const std::vector<DataBackground *>&);

  IPacket	*getPlayers(const std::vector<DataPlayer *>&);

  IPacket		*revErrorPacket(const uint8_t *);
  IPacket		*revWelcome(const uint8_t *);
  IPacket		*revConnect(const uint8_t *);
  IPacket		*revRooms(const uint8_t *);
  IPacket		*revCreateRoom(const uint8_t *);
  IPacket		*revJoinRoom(const uint8_t *);
  IPacket		*revJoinError(const uint8_t *);
  IPacket		*revStartGame(const uint8_t *);
  IPacket		*revStartError(const uint8_t *);
  IPacket		*revLeaveRoom(const uint8_t *);
  IPacket		*revUdpData(const uint8_t *);
  IPacket		*revUdpDataFree(const uint8_t *);
  IPacket		*revRoomData(const uint8_t *);
  IPacket		*revWatchGame(const uint8_t *);
  IPacket		*revLogin(const uint8_t *);
  IPacket		*revRegister(const uint8_t *);
  IPacket		*revLogout(const uint8_t *);
  IPacket		*revDisconnect(const uint8_t *);
  IPacket		*revShoot(const uint8_t *);
  IPacket		*revMove(const uint8_t *);
  IPacket		*revPlayers(const uint8_t *);
  IPacket		*revShoots(const uint8_t *);
  IPacket		*revEnnemies(const uint8_t *);
  IPacket		*revBackgrounds(const uint8_t *);
  IPacket		*revMusic(const uint8_t *);
  IPacket		*revSound(const uint8_t *);
  IPacket		*revPing(const uint8_t *);
  IPacket		*revPong(const uint8_t *);
  IPacket		*revAskRoomData(const uint8_t *);
  IPacket		*revAccept(const uint8_t *);
private:
  PacketContener<void>										*_pkt1;
  PacketContener<const std::string &, const IPacket::PacketType &>				*_pkt2;
  PacketContener<const std::string &>								*_pkt3;
  PacketContener<const std::vector<DataRoom *> &>						*_pkt4;
  PacketContener<const std::string &, const uint8_t &>						*_pkt5;
  PacketContener<const uint8_t *, const uint16_t &>						*_pkt6;
  PacketContener<const DataRoom *>								*_pkt7;
  PacketContener<const std::string &, const std::string &>					*_pkt8;
  PacketContener<const uint16_t &, const uint16_t &>						*_pkt9;
  PacketContener<const std::vector<DataShoot *> &>						*_pkt10;
  PacketContener<const std::vector<DataEnnemy *> &>						*_pkt11;
  PacketContener<const std::vector<DataBackground *> &>						*_pkt12;
  PacketContener<const std::vector<DataPlayer *> &>						*_pkt13;
  PacketContener<const uint8_t *>								*_pktDeserialiser;
};


template<>
class PacketContener<const uint8_t *>
{
public:
  typedef IPacket  *(PacketFactory::*ptr)(const uint8_t *);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map[IPacket::PacketType::ERROR_PACKET] = &PacketFactory::revErrorPacket;
    _map[IPacket::PacketType::WELCOME] = &PacketFactory::revWelcome;
    _map[IPacket::PacketType::CONNECT] = &PacketFactory::revConnect;
    _map[IPacket::PacketType::ROOMS] = &PacketFactory::revRooms;
    _map[IPacket::PacketType::CREATE_ROOM] = &PacketFactory::revCreateRoom;
    _map[IPacket::PacketType::JOIN_ROOM] = &PacketFactory::revJoinRoom;
    _map[IPacket::PacketType::JOIN_ERROR] = &PacketFactory::revJoinError;
    _map[IPacket::PacketType::START_GAME] = &PacketFactory::revStartGame;
    _map[IPacket::PacketType::START_ERROR] = &PacketFactory::revStartError;
    _map[IPacket::PacketType::LEAVE_ROOM] = &PacketFactory::revLeaveRoom;
    _map[IPacket::PacketType::UDP_DATA] = &PacketFactory::revUdpData;
    _map[IPacket::PacketType::UDP_DATA_FREE] = &PacketFactory::revUdpDataFree;
    _map[IPacket::PacketType::ROOM_DATA] = &PacketFactory::revRoomData;
    _map[IPacket::PacketType::WATCH_GAME] = &PacketFactory::revWatchGame;
    _map[IPacket::PacketType::LOGIN] = &PacketFactory::revLogin;
    _map[IPacket::PacketType::REGISTER] = &PacketFactory::revRegister;
    _map[IPacket::PacketType::LOGOUT] = &PacketFactory::revLogout;
    _map[IPacket::PacketType::DISCONNECT] = &PacketFactory::revDisconnect;
    _map[IPacket::PacketType::SHOOT] = &PacketFactory::revShoot;
    _map[IPacket::PacketType::MOVE] = &PacketFactory::revMove;
    _map[IPacket::PacketType::PLAYERS] = &PacketFactory::revPlayers;
    _map[IPacket::PacketType::SHOOTS] = &PacketFactory::revShoots;
    _map[IPacket::PacketType::ENNEMIES] = &PacketFactory::revEnnemies;
    _map[IPacket::PacketType::BACKGROUNDS] = &PacketFactory::revBackgrounds;
    _map[IPacket::PacketType::MUSIC] = &PacketFactory::revMusic;
    _map[IPacket::PacketType::SOUND] = &PacketFactory::revSound;
    _map[IPacket::PacketType::PING] = &PacketFactory::revPing;
    _map[IPacket::PacketType::PONG] = &PacketFactory::revPong;
    _map[IPacket::PacketType::ASKROOMDATA] = &PacketFactory::revAskRoomData;
    _map[IPacket::PacketType::ACCEPT] = &PacketFactory::revAccept;
    _converter["error"] = IPacket::PacketType::ERROR_PACKET;
    _converter["welcome"] = IPacket::PacketType::WELCOME;
    _converter["connect"] = IPacket::PacketType::CONNECT;
    _converter["rooms"] = IPacket::PacketType::ROOMS;
    _converter["createroom"] = IPacket::PacketType::CREATE_ROOM;
    _converter["joinroom"] = IPacket::PacketType::JOIN_ROOM;
    _converter["joinerror"] = IPacket::PacketType::JOIN_ERROR;
    _converter["startgame"] = IPacket::PacketType::START_GAME;
    _converter["starterror"] = IPacket::PacketType::START_ERROR;
    _converter["leaveroom"] = IPacket::PacketType::LEAVE_ROOM;
    _converter["udpdata"] = IPacket::PacketType::UDP_DATA;
    _converter["udpdatafree"] = IPacket::PacketType::UDP_DATA_FREE;
    _converter["roomdata"] = IPacket::PacketType::ROOM_DATA;
    _converter["watchgame"] = IPacket::PacketType::WATCH_GAME;
    _converter["login"] = IPacket::PacketType::LOGIN;
    _converter["register"] = IPacket::PacketType::REGISTER;
    _converter["logout"] = IPacket::PacketType::LOGOUT;
    _converter["disconnect"] = IPacket::PacketType::DISCONNECT;
    _converter["shoot"] = IPacket::PacketType::SHOOT;
    _converter["move"] = IPacket::PacketType::MOVE;
    _converter["players"] = IPacket::PacketType::PLAYERS;
    _converter["shoots"] = IPacket::PacketType::SHOOTS;
    _converter["ennemies"] = IPacket::PacketType::ENNEMIES;
    _converter["background"] = IPacket::PacketType::BACKGROUNDS;
    _converter["music"] = IPacket::PacketType::MUSIC;
    _converter["sound"] = IPacket::PacketType::SOUND;
    _converter["ping"] = IPacket::PacketType::PING;
    _converter["pong"] = IPacket::PacketType::PONG;
    _converter["askroomdata"] = IPacket::PacketType::ASKROOMDATA;
    _converter["accept"] = IPacket::PacketType::ACCEPT;
};
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_converter.find(s) != _converter.end() && _map.find(_converter[s]) != _map.end())
      _enableMap[_converter[s]] = _map[_converter[s]];
  }
  IPacket	*getPacket(const uint8_t *pa)
  {
    IPacket::PacketType p = (IPacket::PacketType)pa[0];

    if (_enableMap.find(p) != _enableMap.end())
      return ((_p->*_enableMap[p])(pa));
    return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<IPacket::PacketType, ptr>    _map;
  std::map<std::string, IPacket::PacketType>    _converter;
  std::map<IPacket::PacketType, ptr>    _enableMap;
  PacketFactory                 *_p;
};

template<>
class PacketContener<const std::vector<DataPlayer *> &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataPlayer *> &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["players"] = &PacketFactory::getPlayers;
    _converter[IPacket::PacketType::PLAYERS] = "players";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::vector<DataPlayer *> &m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const std::vector<DataPlayer *> &m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

template<>
class PacketContener<const std::vector<DataBackground *> &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataBackground *> &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["background"] = &PacketFactory::getBackgrounds;
    _converter[IPacket::PacketType::BACKGROUNDS] = "background";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::vector<DataBackground *> &m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const std::vector<DataBackground *> &m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

template<>
class PacketContener<const std::vector<DataEnnemy *> &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataEnnemy *> &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["ennemies"] = &PacketFactory::getEnnemies;
    _converter[IPacket::PacketType::ENNEMIES] = "ennemies";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::vector<DataEnnemy *> &m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const std::vector<DataEnnemy *> &m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

template<>
class PacketContener<const uint16_t &, const uint16_t &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const uint16_t &, const uint16_t &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["move"] = &PacketFactory::move;
    _map["shoot"] = &PacketFactory::shoot;
    _converter[IPacket::PacketType::MOVE] = "move";
    _converter[IPacket::PacketType::SHOOT] = "shoot";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const uint16_t &m, const uint16_t &t)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m, t));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const uint16_t &m, const uint16_t &t)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m, t));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

template<>
class PacketContener<const std::vector<DataShoot *> &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataShoot *> &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["shoots"] = &PacketFactory::getShoots;
    _converter[IPacket::PacketType::SHOOTS] = "shoots";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::vector<DataShoot *> &m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const std::vector<DataShoot *> &m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

template<>
class PacketContener<const std::string &, const std::string &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &, const std::string &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["login"] = &PacketFactory::login;
    _map["register"] = &PacketFactory::tryRegister;
    _converter[IPacket::PacketType::LOGIN] = "login";
    _converter[IPacket::PacketType::REGISTER] = "register";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::string &m, const std::string &t)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m, t));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const std::string &m, const std::string &t)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m, t));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};



template<>
class PacketContener<const DataRoom *>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const DataRoom *);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["roomdata"] = &PacketFactory::getDataRoom;
    _converter[IPacket::PacketType::ROOM_DATA] = "roomdata";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const DataRoom *m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const DataRoom *m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};





template<>
class PacketContener<const uint8_t *, const uint16_t &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const uint8_t *, const uint16_t &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["udpdata"] = &PacketFactory::udpData;
    _converter[IPacket::PacketType::UDP_DATA] = "udpdata";
  };
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const uint8_t *m, const uint16_t &t)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m, t));
  return (NULL);
  }
  IPacket	*getPacket(const IPacket::PacketType &s, const uint8_t *m, const uint16_t &t)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m, t));
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};




template<>
class PacketContener<const std::string &, const uint8_t &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &, const uint8_t &);
  PacketContener(PacketFactory *p) : _p(p)
  {
  _map["createroom"] = &PacketFactory::createRoom;
  _converter[IPacket::PacketType::CREATE_ROOM] = "createroom";
};
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::string &m, const uint8_t &t)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m, t));
  return (NULL);
}
  IPacket	*getPacket(const IPacket::PacketType &s, const std::string &m, const uint8_t &t)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m, t));
  return (NULL);
}
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};




  
  template<>
  class PacketContener<const std::vector<DataRoom *> &>  
  {
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataRoom *> &);
public:
  PacketContener(PacketFactory *p) : _p(p)
  {
  _map["rooms"] = &PacketFactory::getRooms;
  _converter[IPacket::PacketType::ROOMS] = "rooms";
};
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::vector<DataRoom *> &m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
}
  IPacket	*getPacket(const IPacket::PacketType &s, const std::vector<DataRoom *> &m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
}
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
  private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};




  
  template<> 
  class PacketContener<const std::string &, const IPacket::PacketType &>
  {
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &, const IPacket::PacketType &);
  PacketContener(PacketFactory *p) : _p(p)
  {
  _map["error"] = &PacketFactory::getError;
  _converter[IPacket::PacketType::ERROR_PACKET] = "error";
};
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::string &m, const IPacket::PacketType &t)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m, t));
  return (NULL);
}
  IPacket	*getPacket(const IPacket::PacketType &s, const std::string &m, const IPacket::PacketType &t)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m, t));
  return (NULL);
}
    bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
}; 




  
  template<>
  class PacketContener<const std::string &>
  {
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &);
  PacketContener(PacketFactory *p) : _p(p)
  {
  _map["welcome"] = &PacketFactory::getWelcome;
  _map["joinroom"] = &PacketFactory::joinRoom;
  _map["joinerror"] = &PacketFactory::joinError;
  _map["startgame"] = &PacketFactory::startGame;
  _map["leaveroom"] = &PacketFactory::leaveRoom;
  _map["watchgame"] = &PacketFactory::watchGame;
  _map["music"] = &PacketFactory::music;
  _map["sound"] = &PacketFactory::sound;
  _map["askroomdata"] = &PacketFactory::askRoomData;
  _map["accept"] = &PacketFactory::accept;
  _converter[IPacket::PacketType::WELCOME] = "welcome";
  _converter[IPacket::PacketType::JOIN_ROOM] = "joinroom";
  _converter[IPacket::PacketType::JOIN_ERROR] = "joinerror";
  _converter[IPacket::PacketType::START_GAME] = "startgame";
  _converter[IPacket::PacketType::LEAVE_ROOM] = "leaveroom";
  _converter[IPacket::PacketType::WATCH_GAME] = "watchgame";
  _converter[IPacket::PacketType::MUSIC] = "music";
  _converter[IPacket::PacketType::SOUND] = "sound";
  _converter[IPacket::PacketType::ASKROOMDATA] = "askroomdata";
  _converter[IPacket::PacketType::ACCEPT] = "accept";
};
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
  }
  IPacket	*getPacket(const std::string &s, const std::string &m)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])(m));
  return (NULL);
}
  IPacket	*getPacket(const IPacket::PacketType &s, const std::string &m)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])(m));
  return (NULL);
  }
    bool	isEnable(const std::string &s)
    {
      if (_enableMap.find(s) != _enableMap.end())
	return (true);
      else
	return (false);
    }
  private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};


  
template<>
class PacketContener<void>
{
public:
  typedef IPacket *(PacketFactory::*ptr)();
  PacketContener(PacketFactory *p) : _p(p)
  {
  _map["connect"] = &PacketFactory::getConnect;
  _map["udpdatafree"] = &PacketFactory::udpDataFree;
  _map["logout"] = &PacketFactory::logout;
  _map["disconnect"] = &PacketFactory::disconnect;
  _map["ping"] = &PacketFactory::ping;
  _map["pong"] = &PacketFactory::pong;
  _converter[IPacket::PacketType::CONNECT] = "connect";
  _converter[IPacket::PacketType::UDP_DATA_FREE] = "udpdatafree";
  _converter[IPacket::PacketType::LOGOUT] = "logout";
  _converter[IPacket::PacketType::DISCONNECT] = "disconnect";
  _converter[IPacket::PacketType::PING] = "ping";
  _converter[IPacket::PacketType::PONG] = "pong";
};
  ~PacketContener() {};
  void	enable(const std::string &s)
  {
    if (_map.find(s) != _map.end())
      _enableMap[s] = _map[s]; 
}
  IPacket	*getPacket(const std::string &s)
  {
  if (_enableMap.find(s) != _enableMap.end())
    return ((_p->*_enableMap[s])());
  return (NULL);
}
  IPacket	*getPacket(const IPacket::PacketType &s)
  {
  if (_converter.find(s) != _converter.end() && _enableMap.find(_converter[s]) != _enableMap.end())
    return ((_p->*_enableMap[_converter[s]])());
  return (NULL);
  }
  bool	isEnable(const std::string &s)
  {
    if (_enableMap.find(s) != _enableMap.end())
      return (true);
    else
      return (false);
  }
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

#endif /* !PACKETFACTORY_HH_ */
