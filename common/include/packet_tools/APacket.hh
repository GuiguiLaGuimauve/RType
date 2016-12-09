//
// APacket.hh
//

#ifndef __APACKET_HH__
#define __APACKET_HH__

#include "IPacket.hh"

namespace Packet
  {
  /*!
  en : APacket abstract class regroup the methods and attributs of all packet
  fr :La classe abstraite APacket regroupe les méthodes et les attributs de tous les paquet */
  class	APacket : public IPacket
  {
  public:
    APacket(){};
    virtual ~APacket(){};

    IPacket::PacketType getType() const;
    uint32_t getSize() const;
    uint8_t *getData() const;
    uint8_t *generate() const;
    PacketUnknown getPacketUnknown() const;
  protected:
    /*!
    en :Type of packet depend of the protocol
    fr :Type du paquet en fonction du protocole */
    IPacket::PacketType _type;

    /*!
    en :Size of data var
    fr :Taille de la variable data */
    uint32_t _size;

    /*!
    en : data from packet
    fr :Données du paquet */
    uint8_t *_data;
  };
};

#endif
