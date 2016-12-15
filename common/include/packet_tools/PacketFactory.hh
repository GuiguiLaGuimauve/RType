//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Thu Dec 15 17:31:46 2016 lecoq
//

#ifndef PACKETFACTORY_HH_
# define PACKETFACTORY_HH_

# include	<iostream>
# include	<string>
# include	<map>
# include	"IPacket.hh"

class	PacketFactory
{
public:
  //  template<typename ... Args>
  typedef IPacket *(PacketFactory::*ptrPacket)(/*Args ...*/);
  PacketFactory();
  ~PacketFactory();
  //template<typename ... Args>
  IPacket	*getPacket(const std::string &/*, Args ...*/) const;
  //  template<typename ... Args>
  IPacket	*getPacket(const IPacket::PacketType &/*, Args ...*/) const;
  void		getPacket(const uint8_t *) const;
  void		enable(const std::string &);
private:
  std::map<std::string, ptrPacket>		_mapData;
  std::map<IPacket::PacketType, std::string>	_mapConverter;
  std::map<std::string, ptrPacket>		_ptr;
};

#endif /* !PACKETFACTORY_HH_ */
