//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETROOMDATA_HH__
#define __PACKETROOMDATA_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataPlayer.hpp"
#include "DataRoom.hpp"

namespace Packet {

	class PacketRoomData : public APacket {

	public:
	  PacketRoomData(const DataRoom *);
	  PacketRoomData(const uint8_t *data);
	  ~PacketRoomData();
	  
	  std::vector<DataPlayer *> getPlayers() const;
	  uint16_t getNbPlayers() const;
	  uint8_t getMaxPlayers() const;
	  uint8_t getLevel() const;
	  bool isTcp() const;
	  bool isUdp() const;
	  
	private:
	  DataRoom *_dataroom;
	};
};

#endif
