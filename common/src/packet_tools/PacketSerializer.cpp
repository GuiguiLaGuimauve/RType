//
// PacketSerializer.cpp for PacketSerializer in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Oct 27 14:44:31 2016 Maxime Lecoq
// Last update Thu Oct 27 17:26:37 2016 lecoq
//

#include	"PacketSerializer.hh"

PacketSerializer::PacketSerializer() {}

PacketSerializer::~PacketSerializer() {}

void			PacketSerializer::add(const uint32_t &d)
{
  _string += d >> 0;
  _string += d >> 8;
  _string += d >> 16;
  _string += d >> 24;
}

void			PacketSerializer::add(const uint16_t &d)
{
  _string += d >> 0;
  _string += d >> 8;
}

void			PacketSerializer::add(const uint8_t &d)
{
  _string += d;
}

void			PacketSerializer::add(const std::string &d)
{
  _string += d;
}

void			PacketSerializer::add(const char *d)
{
  std::string tmp(d);
  add(tmp);
}

uint8_t			*PacketSerializer::getPacket() const
{
  uint8_t		*ret = new uint8_t[_string.size()];

  for (uint64_t i = 0; i < _string.size(); i++)
    ret[i] = _string[i];
  return (ret);
}

uint32_t		PacketSerializer::getPacketSize() const
{
  return ((uint32_t)_string.size());
}
