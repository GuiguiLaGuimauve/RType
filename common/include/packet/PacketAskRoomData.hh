//
// C:\Users\Guimauve\Documents\RType\common\include\packet\PacketAskRoomData.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Dec 18 14:39:31 2016 La Guimauve
// Last update Wed Dec 21 09:54:50 2016 La Guimauve
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
  /*!
		\class PacketAskRoomData PacketAskRoomData.hh
		\brief classe du paquet "ASKROOMDATA", envoyé lorsque que le client demande des informations sur la "Room"/partie
	*/
  class PacketAskRoomData : public APacket {

  public:
    /**
 		* \fn PacketAskRoomData(const std::string &)
 		* \brief Constructeur du packet utilisé pour la serialization.
 		*
 		* \param data Nom de la partie (Room).
 		*/
    PacketAskRoomData(const std::string &);
    /**
    * \fn PacketAskRoomData(const uint8_t *)
    * \brief Constructeur du packet utilisé pour la déserialization.
    *
    * \param data données à desarializé.
    */
    PacketAskRoomData(const uint8_t *);
    /**
    * \fn ~PacketAskRoomData()
    * \brief Destructeur du packet.
    */
    ~PacketAskRoomData() {};

    /**
    * \fn bool isTcp() const
    * \brief Savoir si le paquet est envoyable en TCP
    *
    * \return True si le paquet en envoyé en TCP, sinon false
    */
    bool isTcp() const;
    /**
    * \fn bool isUdp() const
    * \brief Savoir si le paquet est envoyable en UDP
    *
    * \return True si le paquet en envoyé en UDP, sinon false
    */
    bool isUdp() const;
private:
  std::string _message; /** \brief _message : contiendra le message à serialiser dans le paquet */
};

};

#endif // _PACKETASKROOMDATA_HH_
