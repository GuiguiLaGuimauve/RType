//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPING_HH__
#define __PACKETPING_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketPing PacketPing.hh
		\brief classe du paquet "ping", envoi un ping
	*/
	class PacketPing : public APacket {

	public:
		/**
		* \fn PacketPing()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketPing();
		/**
		* \fn PacketPing(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketPing(const uint8_t *data);
		/**
		* \fn ~PacketPing()
		* \brief Destructeur du packet.
		*/
		~PacketPing();

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
