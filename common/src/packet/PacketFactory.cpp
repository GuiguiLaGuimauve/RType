//
// PacketFactory.cpp for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:43:18 2016 Maxime Lecoq
// Last update Thu Dec 15 11:45:11 2016 lecoq
//

#include	"PacketFactory.hh"

PacketFactory::PacketFactory() {}
PacketFactory::~PacketFactory() {}

IPacket		*PacketFactory::getPacket(const std::string &p)
{
  (void)p;
}

IPacket		*PacketFactory::getPacket(const IPacket::PacketType &p)
{
  (void)p;
}

void		PacketFactory::getPacket(const uint8_t *p)
{
  (void)p;
}
