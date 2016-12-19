//
// IPacket.hh
//

#ifndef __IPACKET_HH__
#define __IPACKET_HH__

#include <stdint.h>
#include <iostream>
#include <string.h>

#include "PacketSerializer.hh"
#include "PacketDeserializer.hh"

#include "PacketUnknown.hpp"

namespace Packet
{
  /*! IPacket define all methods for all packets */
  class	IPacket
  {
  public:
#define PACKET_GROUP 6
#define PACKET_VERSION 2
#define ERROR_CONNECT "Connection to the server failed"
#define ACCEPT_MESSAGE "Hi, you are accepted by rembur_g server's"

    /*! PacketType contains all differents values in the packets for the common protocol */
     enum class PacketType : uint8_t {
        ERROR_PACKET	= 0x00,
        WELCOME			= 0x01,
        CONNECT			= 0x02,
        ROOMS			= 0x03,
        CREATE_ROOM		= 0x04,
        JOIN_ROOM		= 0x05,
        JOIN_ERROR		= 0x06,
        START_GAME		= 0x07,
        START_ERROR		= 0x08,
        LEAVE_ROOM		= 0x09,
        UDP_DATA		= 0x10,
        UDP_DATA_FREE	= 0x11,
        ROOM_DATA		= 0x12,
        WATCH_GAME		= 0x13,
        LOGIN			= 0x14,
        REGISTER		= 0x15,
        LOGOUT			= 0x16,
        ASKROOMDATA = 0x17,
		ACCEPT = 0x18,
        
        DISCONNECT		= 0x20,
        SHOOT			= 0x21,
        MOVE			= 0x22,

        PLAYERS			= 0x81,
        SHOOTS			= 0x82,
        ENNEMIES		= 0x83,
        BACKGROUNDS		= 0x84,
        MUSIC			= 0x85,
        SOUND			= 0x86,
		PING			= 0x87,
		PONG			= 0x88
    };

    /*! Clean all necessary data for packet management */
    virtual ~IPacket(){};

    /*! Return the packet's type */
    virtual PacketType getType() const = 0;

	/*! Return the packet's timer ID */
	virtual uint32_t getTickId() const = 0;

	/*! Change the packet's timer ID */
	virtual void setTickId(uint32_t tickId) = 0;

    /*! Return the packet's data size  */
    virtual uint32_t getSize() const = 0;

    /*! Return packet's data */
    virtual uint8_t* getData() const = 0;

	/*! Generate the packet for network transition */
    virtual uint8_t *generate() const = 0;

	/*! Return true if the packet is a TCP packet */
	virtual bool isTcp() const = 0;

	/*! Return true if the packet is a UDP packet */
	virtual bool isUdp() const = 0;

	/*! Instanciate a PacketUnknown from the current packet */
    virtual PacketUnknown getPacketUnknown() const = 0;
  };
};
using namespace Packet;

#endif
