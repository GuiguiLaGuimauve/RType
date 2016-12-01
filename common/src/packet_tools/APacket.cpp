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

IPacket::PacketType APacket::getPacketType() const
{
  return (_type);
}

uint32_t APacket::getPacketSize() const
{
  return (_size);
}

uint8_t *APacket::getPacketData() const
{
  return (_data);
}

uint8_t *APacket::generatePacket() const
{
  uint8_t	*exp;
  PacketSerializer ps;
  uint32_t	i = 0;
  uint32_t	j = 0;

  ps.add((uint8_t)_type);
  ps.add(_size);
  exp = new uint8_t[_size + sizeof(uint8_t) + sizeof(uint32_t)];
  while (j < sizeof(uint8_t) + sizeof(uint32_t))
      exp[i++] = ps.getPacket()[j++];
  j = 0;
  while (j < _size)
    exp[i++] = _data[j++];
  return (exp);
}

PacketUnknown	APacket::getPacketUnknown() const
{
  PacketUnknown	pkt(generatePacket(), getPacketSize() + 5);
  return (pkt);
}
