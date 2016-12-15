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
  /*!
  en : IPacket define all methods for all packets
    L'interface IPacket définie des méthode pour la totalitée des paquets
  */
  class	IPacket
  {
  public:
    /*!
    en :PacketType correspond to all differents values in the packets for the common protocol
    fr :Le PacketType correspond aux différentes valeurs contenu dans les paquets réseau en fonction de notre protocole en commun avec les autres groupes */
     enum class PacketType : uint8_t {
        ERROR			= 0x00,
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

        DISCONNNECT		= 0x20,
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

    /*!
    en :Clean all necessary data for packet management
    fr :Permet de vider les données nécessaires à la gestion du packet */
    virtual ~IPacket(){};
    /*!
    en :Return the packet's type
    fr :Retourne le type du paquet */
    virtual PacketType getType() const = 0;

    /*!
    en :Return the packet's data size
    fr :Retourne la taille de la partie data du paquet */
    virtual uint32_t getSize() const = 0;

    /*!
    en :Return packet's data
    fr :Retourne les données du paquet */
    virtual uint8_t* getData() const = 0;
    virtual uint8_t *generate() const = 0;
    virtual PacketUnknown getPacketUnknown() const = 0;
  };
};
using namespace Packet;

#endif
