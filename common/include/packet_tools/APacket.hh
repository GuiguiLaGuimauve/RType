//
// APacket.hh
//

#ifndef __APACKET_HH__
#define __APACKET_HH__

#include "IPacket.hh"

namespace Packet
{
  /*! APacket abstract class regroup the methods and attributs of all packet */
  class	APacket : public IPacket
  {
  public:
    APacket(){};
    virtual ~APacket(){};
    IPacket::PacketType getType() const;
    uint32_t getSize() const;
    uint32_t getTickId() const;
    void setTickId(uint32_t tickId);
    uint8_t *getData() const;
    uint8_t *generate() const;
    PacketUnknown getPacketUnknown() const;
	virtual bool isTcp() const = 0;
	virtual bool isUdp() const = 0;
	
  protected:
    /*! Type of packet depend of the protocol */
    IPacket::PacketType _type;

    /*! Size of data var */
    uint32_t _size;
	
	 /*! Tick ID (Timer unique identifier) */
    uint32_t _tickId;

    /*! Data in the packet */
    uint8_t *_data;
  };
};

#endif
