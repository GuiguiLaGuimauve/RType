//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETASKROOMS_HH__
#define __PACKETASKROOMS_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketAskRooms PacketAskRooms.hh
		\brief classe du paquet "askrooms", demande au serveur l'envoi des rooms
	*/
	class PacketAskRooms : public APacket {

	public:
		/**
		* \fn PacketAskRooms()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketAskRooms();
		/**
		* \fn PacketAskRooms(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketAskRooms(const uint8_t *data);
		/**
		* \fn ~PacketAskRooms()
		* \brief Destructeur du packet.
		*/
		~PacketAskRooms();

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
	};
};

#endif
