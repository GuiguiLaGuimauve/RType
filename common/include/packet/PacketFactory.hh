//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Thu Dec 15 14:33:30 2016 lecoq
//

#ifndef PACKETFACTORY_HH_
# define PACKETFACTORY_HH_

# include	<iostream>
# include	<string>
# include	"IPacket.hh"

class	PacketFactory
{
public:
  PacketFactory();
  ~PacketFactory();
  IPacket	*getPacket(const std::string &) const;
  IPacket	*getPacket(const IPacket::PacketType &) const;
  void		getPacket(const uint8_t *) const;
};

#endif /* !PACKETFACTORY_HH_ */
