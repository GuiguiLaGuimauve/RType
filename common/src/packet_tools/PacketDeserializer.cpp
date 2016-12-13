//
// PacketDeserializer.cpp for PacketDeserializer in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Oct 27 15:50:53 2016 Maxime Lecoq
// Last update Sat Nov 12 11:42:44 2016 lecoq
//

#include	"PacketDeserializer.hh"

PacketDeserializer::PacketDeserializer(const uint8_t *data) : _msg((uint8_t *)data)
{
	_headerSize = 9;
}

PacketDeserializer::~PacketDeserializer() {}

uint32_t		PacketDeserializer::getPacketSize() const
{
  uint32_t		ret;

  ret = _msg[1] << 0 | _msg[2] << 8 | _msg[3] << 16 | _msg[4] << 24;

  return (ret);
}

uint32_t		PacketDeserializer::getPacketTickId() const
{
  uint32_t		ret;

  ret = _msg[5] << 0 | _msg[6] << 8 | _msg[7] << 16 | _msg[8] << 24;

  return (ret);
}


uint32_t		PacketDeserializer::get32(const uint32_t &d) const
{
  uint32_t		ret;

  ret = _msg[d + _headerSize] << 0 | _msg[d + _headerSize] << 8 | _msg[d + _headerSize] << 16 | _msg[d + _headerSize] << 24;

  return (ret);
}

uint16_t		PacketDeserializer::get16(const uint32_t &d) const
{
  uint16_t		ret;

  ret = _msg[d + _headerSize] << 0 | _msg[d + _headerSize] << 8;
  return (ret);
}

uint8_t			PacketDeserializer::get8(const uint32_t &d) const
{
  return (_msg[d + _headerSize]);
}

std::string		PacketDeserializer::getString(const uint32_t &d, const uint32_t &size) const
{
  std::string		tmp;
  uint32_t		i = 0;

  while (i < size)
    {
      tmp += _msg[d + i + _headerSize];
      i++;
    }
  return (tmp);
}
