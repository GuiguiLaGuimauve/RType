//
// PacketGame.hh for PacketGame in /home/lecoq/RType
// 
// Made by Lecoq Maxime
// Login   <lecoq@lecoq-epitechHP>
// 
// Started on  Mon Jan  2 00:03:18 2017 Lecoq Maxime
// Last update Mon Jan  2 00:35:01 2017 Lecoq Maxime
//

#ifndef PACKETGAME_HH_
# define PACKETGAME_HH_

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataPlayer.hpp"
#include "DataShoot.hpp"
#include "DataEnnemy.hpp"
#include "DataBackground.hpp"

namespace Packet
{
  class PacketGame : public APacket
  {
  public:
    PacketGame(const std::vector<DataPlayer *> &, const std::vector<DataShoot *> &, const std::vector<DataEnnemy *> &, const std::vector<DataBackground *> &);
    PacketGame(const std::vector<DataPlayer *> &, const std::vector<DataShoot *> &, const std::vector<DataEnnemy *> &);
    PacketGame(const uint8_t *);
    ~PacketGame();
    bool isTcp() const;
    bool isUdp() const;
    std::vector<DataPlayer *> getPlayers() const;
    std::vector<DataShoot *> getShoots() const;
    std::vector<DataEnnemy *> getEnnemies() const;
    std::vector<DataBackground *> getBackgrounds() const;
  private:
    std::vector<DataBackground *> _back;
    std::vector<DataEnnemy *>	_ennemies;
    std::vector<DataShoot *>	_shoots;
    std::vector<DataPlayer *>	_players;
  };
};

#endif /* !PACKETGAME_HH_ */
