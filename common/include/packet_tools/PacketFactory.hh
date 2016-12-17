//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Sat Dec 17 17:17:35 2016 lecoq
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

  IPacket	*getPacket(const std::string &, const std::vector<DataPlayer *> &, const uint8_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataPlayer *> &, const uint8_t &);

  void		getPacket(const uint8_t *) const;
  void		enable(const std::string &);

  IPacket	*getConnect();
  IPacket	*udpDataFree();
  
  IPacket	*getError(const std::string &, const IPacket::PacketType &);
  
  IPacket	*getWelcome(const std::string &);
  IPacket	*joinRoom(const std::string &);
  IPacket	*joinError(const std::string &);
  IPacket	*startGame(const std::string &);
  IPacket	*startError(const std::string &);
  IPacket	*leaveRoom(const std::string &);

  IPacket	*getRooms(const std::vector<DataRoom *> &);

  IPacket	*createRoom(const std::string &, const uint8_t &);

  IPacket	*udpData(const uint8_t *, const uint16_t &);

  IPacket	*getDataRoom(const DataRoom *);

private:
  PacketContener<void>										*_pkt1;
  PacketContener<const std::string &, const IPacket::PacketType &>				*_pkt2;
  PacketContener<const std::string &>								*_pkt3;
  PacketContener<const std::vector<DataRoom *> &>						*_pkt4;
  PacketContener<const std::string &, const uint8_t &>						*_pkt5;
  PacketContener<const uint8_t *, const uint16_t &>						*_pkt6;
  PacketContener<const DataRoom *>								*_pkt7;
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
  _converter[IPacket::PacketType::ERROR_PACKET] = "welcome";
  _converter[IPacket::PacketType::ERROR_PACKET] = "joinroom";
  _converter[IPacket::PacketType::ERROR_PACKET] = "joinerror";
  _converter[IPacket::PacketType::ERROR_PACKET] = "startgame";
  _converter[IPacket::PacketType::ERROR_PACKET] = "leaveroom";
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
  _converter[IPacket::PacketType::ERROR_PACKET] = "connect";
  _converter[IPacket::PacketType::ERROR_PACKET] = "udpdatafree";
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
