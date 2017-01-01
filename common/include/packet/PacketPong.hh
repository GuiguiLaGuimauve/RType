//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPONG_HH__
#define __PACKETPONG_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketPong PacketPong.hh
		\brief classe du paquet "pong", envoi un pong réponse au ping
	*/
	class PacketPong : public APacket {

	public:
		/**
		* \fn PacketPong()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketPong();
		/**
		* \fn PacketPong(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketPong(const uint8_t *data);
		/**
		* \fn ~PacketPong()
		* \brief Destructeur du packet.
		*/
		~PacketPong();

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
