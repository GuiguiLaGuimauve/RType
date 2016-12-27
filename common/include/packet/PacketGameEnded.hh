//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETGAMEENDED_HH__
#define __PACKETGAMEENDED_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketGameEnded PacketGameEnded.hh
		\brief Packet GameEnded pour signaler la fin d'une partie
	*/
	class PacketGameEnded : public APacket {

	public:
		/**
		* \fn PacketGameEnded()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketGameEnded();
		/**
		* \fn PacketGameEnded(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketGameEnded(const uint8_t *data);
		/**
		* \fn ~PacketGameEnded()
		* \brief Destructeur du packet.
		*/
		~PacketGameEnded();

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
