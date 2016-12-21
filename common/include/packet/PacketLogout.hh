//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETLOGOUT_HH__
#define __PACKETLOGOUT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketLogout PacketLogout.hh
		\brief classe du paquet "logout", envoyé lorsque le client se deconnecte sur le serveur
	*/
	class PacketLogout : public APacket {

	public:
		/**
		* \fn PacketLogout()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketLogout();
		/**
		* \fn PacketLogout(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketLogout(const uint8_t *data);
		/**
		* \fn ~PacketLogin()
		* \brief Destructeur du packet.
		*/
		~PacketLogout();
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
