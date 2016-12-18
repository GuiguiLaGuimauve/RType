//
// C:\Users\Guimauve\Documents\RType\common\src\packet\PacketAskRoom.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Dec 18 14:49:43 2016 La Guimauve
// Last update Sun Dec 18 14:56:12 2016 La Guimauve
//

#include "PacketRoomData.hh"

PacketAskRoomData::PacketAskRoomData(const std::string &roomname)
{
  PacketSerializer ps;
  uint32_t dataPacketSize = 0;

  _type = IPacket::PacketType::ASKROOMDATA;
  _tickId = 0;

  _data = ps.getPacket();
  _size = dataPacketSize;
}

PacketAskRoomData::PacketAskRoomData(const uint8_t *data)
{
  PacketDeserializer pd(data);

  _type = IPacket::PacketType::ASKROOMDATA;
  _size = pd.getPacketSize();
  _tickId = pd.getPacketTickId();

  _data = new uint8_t[_size];
  for (uint32_t a = 0; a < _size; a++)
    _data[a] = data[a + 9]
}

bool PacketConnect::isTcp() const
{
	return (true);
}

bool PacketConnect::isUdp() const
{
	return (false);
}
