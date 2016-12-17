//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Sat Dec 17 01:09:13 2016 lecoq
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
  typedef IPacket *(PacketFactory::*ptr1)() ;
  typedef IPacket *(PacketFactory::*ptr2)(const std::string &, const IPacket::PacketType &) ;
  typedef IPacket *(PacketFactory::*ptr3)(const std::string &) ;
  PacketFactory();
  ~PacketFactory();
  IPacket	*getPacket(const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &);
  IPacket	*getPacket(const std::string &, const std::string &, const IPacket::PacketType &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &, const IPacket::PacketType &);
  IPacket	*getPacket(const std::string &, const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &);
  void		getPacket(const uint8_t *) const;
  void		enable(const std::string &);

  IPacket	*getError(const std::string &, const IPacket::PacketType &);
  
  IPacket	*getWelcome(const std::string &);  
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
};

#endif /* !PACKETFACTORY_HH_ */
