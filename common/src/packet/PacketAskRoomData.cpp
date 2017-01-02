//
// C:\Users\Guimauve\Documents\RType\common\src\packet\PacketAskRoom.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Dec 18 14:49:43 2016 La Guimauve
// Last update Sun Dec 18 15:49:15 2016 lecoq
//

#include "PacketAskRoomData.hh"

PacketAskRoomData::PacketAskRoomData(const std::string &roomname)
{
  PacketSerializer ps;
  uint32_t dataPacketSize = 0;

  _type = IPacket::PacketType::ASKROOMDATA;
  _tickId = 0;

  _message = roomname;

  ps.add((uint16_t)_message.size());
  ps.add(_message);
  dataPacketSize += 2 + (uint32_t)_message.size();
  
  _data = ps.getPacket();
  _size = dataPacketSize;
}

PacketAskRoomData::PacketAskRoomData(const uint8_t *data)
{
  PacketDeserializer pd(data);
  uint32_t posInPacket = 0;
  
  _type = IPacket::PacketType::ASKROOMDATA;
  _size = pd.getPacketSize();
  _tickId = pd.getPacketTickId();
  
  _data = new uint8_t[_size];
  for (uint32_t a = 0; a < _size; a++)
    _data[a] = data[a + 9];

  _message = pd.getString(posInPacket + 2, pd.get16(posInPacket));
  posInPacket += 2 + (uint32_t)pd.get16(posInPacket);
}

bool PacketAskRoomData::isTcp() const
{
  return (true);
}

bool PacketAskRoomData::isUdp() const
{
  return (false);
}
