//
// PacketPlayerData.hh for PacketPlayerData in /home/lecoq/RType
// 
// Made by Lecoq Maxime
// Login   <lecoq@lecoq-epitechHP>
// 
// Started on  Mon Jan  2 03:32:21 2017 Lecoq Maxime
// Last update Mon Jan  2 03:35:59 2017 Lecoq Maxime
//

#ifndef PACKETPLAYERDATA_HH_
# define PACKETPLAYERDATA_HH_

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataShoot.hpp"

namespace Packet {
  class PacketPlayerData : public APacket {
  public:
    PacketPlayerData(const uint16_t &, const uint16_t &, const std::vector<DataShoot *> &);
    PacketPlayerData(const uint8_t *);
    ~PacketPlayerData();
    uint16_t getX() const;
    uint16_t getY() const;
    bool isTcp() const;
    bool isUdp() const;
    std::vector<DataShoot *> getShoots() const;
  private:
    uint16_t _x;
    uint16_t _y;
    std::vector<DataShoot *> _shoots;
  };
};

#endif /* !PACKETPLAYERDATA_HH_ */
