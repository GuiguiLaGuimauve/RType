//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Sun Dec 18 01:27:39 2016 lecoq
//

#ifndef PACKETFACTORY_HH_
# define PACKETFACTORY_HH_

# include	<iostream>
# include	<string>
# include	<map>
# include	"IPacket.hh"
# include	"PacketList.h"

using namespace Packet;

template<typename ... Args>
class PacketContener;

class	PacketFactory
{
public:
  PacketFactory();
  ~PacketFactory();
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
  
  void		getPacket(const uint8_t *) const;
  void		enable(const std::string &);

  IPacket	*getConnect();
  IPacket	*udpDataFree();
  IPacket	*logout();
  IPacket	*disconnect();
  
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
};


template<>
class PacketContener<const std::vector<DataBackground *> &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataBackground *> &);
  PacketContener(PacketFactory *p) : _p(p)
  {
    _map["background"] = &PacketFactory::getBackgrounds;
    _converter[IPacket::PacketType::ERROR_PACKET] = "background";
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
    _converter[IPacket::PacketType::ERROR_PACKET] = "ennemies";
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
    _converter[IPacket::PacketType::ERROR_PACKET] = "move";
    _converter[IPacket::PacketType::ERROR_PACKET] = "shoot";
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
    _converter[IPacket::PacketType::ERROR_PACKET] = "shoots";
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
    _converter[IPacket::PacketType::ERROR_PACKET] = "login";
    _converter[IPacket::PacketType::ERROR_PACKET] = "register";
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
    _map["dataroom"] = &PacketFactory::getDataRoom;
    _converter[IPacket::PacketType::ERROR_PACKET] = "dataroom";
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
    _converter[IPacket::PacketType::ERROR_PACKET] = "udpdata";
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
  _converter[IPacket::PacketType::ERROR_PACKET] = "createroom";
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
  _map["getrooms"] = &PacketFactory::getRooms;
  _converter[IPacket::PacketType::ERROR_PACKET] = "getrooms";
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
  _converter[IPacket::PacketType::ERROR_PACKET] = "welcome";
  _converter[IPacket::PacketType::ERROR_PACKET] = "joinroom";
  _converter[IPacket::PacketType::ERROR_PACKET] = "joinerror";
  _converter[IPacket::PacketType::ERROR_PACKET] = "startgame";
  _converter[IPacket::PacketType::ERROR_PACKET] = "leaveroom";
  _converter[IPacket::PacketType::ERROR_PACKET] = "watchgame";
  _converter[IPacket::PacketType::ERROR_PACKET] = "music";
  _converter[IPacket::PacketType::ERROR_PACKET] = "sound";
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
  _converter[IPacket::PacketType::ERROR_PACKET] = "connect";
  _converter[IPacket::PacketType::ERROR_PACKET] = "udpdatafree";
  _converter[IPacket::PacketType::ERROR_PACKET] = "logout";
  _converter[IPacket::PacketType::ERROR_PACKET] = "disconnect";
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
private:
  std::map<std::string, ptr>    _map;
  std::map<IPacket::PacketType, std::string>    _converter;
  std::map<std::string, ptr>    _enableMap;
  PacketFactory                 *_p;
};

#endif /* !PACKETFACTORY_HH_ */
