//
// C:\Users\Guimauve\Documents\RType\common\include\packet\PacketAskRoomData.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Dec 18 14:39:31 2016 La Guimauve
// Last update Sun Dec 18 15:48:59 2016 lecoq
//

#ifndef _PACKETASKROOMDATA_HH_
# define _PACKETASKROOMDATA_HH_

#include <stdint.h>
#include <vector>
#include <iostream>
#include <string>
#include "APacket.hh"
#include "DataPlayer.hpp"
#include "DataRoom.hpp"

namespace Packet {

  class PacketAskRoomData : public APacket {

  public:
    PacketAskRoomData(const std::string &);
    PacketAskRoomData(const uint8_t *);
    ~PacketAskRoomData() {};

    bool isTcp() const;
    bool isUdp() const;
private:
  std::string _message;
};

};

#endif // _PACKETASKROOMDATA_HH_
