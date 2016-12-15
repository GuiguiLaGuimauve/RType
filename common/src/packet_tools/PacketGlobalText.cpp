//
// PacketWelcomeServer.cpp
// 

#include <iostream>
#include "PacketGlobalText.hh"

PacketGlobalText::PacketGlobalText(const IPacket::PacketType & type, const std::string & message)
{
  PacketSerializer ps;

  _type = type;
  _message = message;
  ps.add((uint16_t)_message.size());
  ps.add(message);
  _data = ps.getPacket();
  _size = (uint32_t)(_message.size() + 2);
}

PacketGlobalText::PacketGlobalText(const IPacket::PacketType & type, const uint8_t *data)
{
  PacketDeserializer pd(data);
  uint16_t size;
  
  _type = type;
  size = pd.get16(0);
  _message = pd.getString(2, size);
  _size = pd.getPacketSize();
}

PacketGlobalText::~PacketGlobalText()
{

}

std::string PacketGlobalText::getMessage() const
{
  return (_message);
}
