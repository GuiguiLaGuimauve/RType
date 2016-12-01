//
// PacketGlobalError.cpp
// 

#include <iostream>
#include "PacketGlobalError.hh"

PacketGlobalError::PacketGlobalError(const IPacket::PacketType & type, const std::string & message, const IPacket::PacketType & error)
{
  PacketSerializer ps;

  _type = type;
  _message = message;
  ps.add((uint16_t)_message.size());
  ps.add(message);
  ps.add((uint8_t)error);
  _data = ps.getPacket();
  _size = (uint32_t)(_message.size() + 3);
  _error = error;
}

PacketGlobalError::PacketGlobalError(const IPacket::PacketType & type, const uint8_t *data)
{
  PacketDeserializer pd(data);
  uint16_t size;
  
  _type = type;
  size = pd.get16(0);
  _message = pd.getString(2, size);
  _size = pd.getPacketSize();
  _error = (IPacket::PacketType)pd.get8(2 + size);
}

PacketGlobalError::~PacketGlobalError()
{

}

std::string PacketGlobalError::getMessage() const
{
  return (_message);
}


IPacket::PacketType PacketGlobalError::getError() const
{
  return (_error);
}
