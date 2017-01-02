//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETDISCONNECT_HH__
#define __PACKETDISCONNECT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketDisconnect PacketDisconnect.hh
		\brief classe du paquet "disconnect", envoyé lorsque le client se deconnecte
	*/
	class PacketDisconnect : public APacket {

	public:
		/**
		* \fn PacketDisconnect()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketDisconnect();
		/**
		* \fn PacketDisconnect(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketDisconnect(const uint8_t *data);
		/**
		* \fn ~PacketDisconnect()
		* \brief Destructeur du packet.
		*/
		~PacketDisconnect();

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
