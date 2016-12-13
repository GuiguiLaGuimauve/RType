//
// APacket.cpp for  in /home/baconn_m/rendu/Tek3/cpp_babel
// 
// Made by Maxime Baconnais
// Login   <baconn_m@epitech.net>
// 
// Started on  Thu Oct 27 15:56:10 2016 Maxime Baconnais
// Last update Sat Nov 12 14:16:52 2016 lecoq
//

#include "APacket.hh"

IPacket::PacketType APacket::getType() const
{
  return (_type);
}

uint32_t APacket::getSize() const
{
  return (_size);
}

uint8_t *APacket::getData() const
{
  return (_data);
}

uint8_t *APacket::generate() const
{
  uint8_t	*exp;
  PacketSerializer ps;
  uint32_t	i = 0;
  uint32_t	j = 0;

  ps.add((uint8_t)_type);
  ps.add(_size);
  ps.add(_tickId);
  exp = new uint8_t[_size + sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t)];
  while (j < sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t))
      exp[i++] = ps.getPacket()[j++];
  j = 0;
  while (j < _size)
    exp[i++] = _data[j++];
  return (exp);
}

PacketUnknown	APacket::getPacketUnknown() const
{
  PacketUnknown	pkt(generate(), getSize() + 9);
  return (pkt);
}