//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Sat Dec 17 11:08:08 2016 lecoq
//

#ifndef PACKETFACTORY_HH_
# define PACKETFACTORY_HH_

# include	<iostream>
# include	<string>
# include	<map>
# include	"IPacket.hh"
# include	"PacketList.h"

using namespace Packet;

class	PacketFactory
{
public:
  typedef IPacket *(PacketFactory::*ptr1)();
  typedef IPacket *(PacketFactory::*ptr2)(const std::string &, const IPacket::PacketType &);
  typedef IPacket *(PacketFactory::*ptr3)(const std::string &);
  typedef IPacket *(PacketFactory::*ptr4)(const std::vector<DataRoom *> &);
  typedef IPacket *(PacketFactory::*ptr5)(const std::string &, const uint8_t &);
  typedef IPacket *(PacketFactory::*ptr6)(const uint8_t *, const uint16_t &);
  typedef IPacket *(PacketFactory::*ptr7)(const std::vector<DataPlayer *> &, const uint8_t &);
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

private:
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

  IPacket	*getDataRoom(const std::vector<DataPlayer *> &, const uint8_t &);
private:
  std::map<std::string, ptr1>			_mapData1;
  std::map<IPacket::PacketType, std::string>	_mapConverter1;
  std::map<std::string, ptr1>		_ptr1;

  std::map<std::string, ptr2>			_mapData2;
  std::map<IPacket::PacketType, std::string>	_mapConverter2;
  std::map<std::string, ptr2>		_ptr2;

  std::map<std::string, ptr3>			_mapData3;
  std::map<IPacket::PacketType, std::string>	_mapConverter3;
  std::map<std::string, ptr3>		_ptr3;

  std::map<std::string, ptr4>			_mapData4;
  std::map<IPacket::PacketType, std::string>	_mapConverter4;
  std::map<std::string, ptr4>		_ptr4;
  
  std::map<std::string, ptr5>			_mapData5;
  std::map<IPacket::PacketType, std::string>	_mapConverter5;
  std::map<std::string, ptr5>		_ptr5;

  std::map<std::string, ptr6>			_mapData6;
  std::map<IPacket::PacketType, std::string>	_mapConverter6;
  std::map<std::string, ptr6>		_ptr6;

  std::map<std::string, ptr7>			_mapData7;
  std::map<IPacket::PacketType, std::string>	_mapConverter7;
  std::map<std::string, ptr7>		_ptr7;
};

#endif /* !PACKETFACTORY_HH_ */
