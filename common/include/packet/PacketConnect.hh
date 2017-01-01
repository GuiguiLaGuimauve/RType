//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCONNECT_HH__
#define __PACKETCONNECT_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketConnect PacketConnect.hh
		\brief classe du paquet "connect", envoyé par le client lorsque celui-ci se connecte au serveur
	*/
	class PacketConnect : public APacket {

	public:
		/**
		* \fn PacketConnect()
		* \brief Constructeur du packet utilisé pour la serialization.
		*/
		PacketConnect();
		/**
		* \fn PacketConnect(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketConnect(const uint8_t *data);
		/**
		* \fn ~PacketConnect()
		* \brief Destructeur du packet.
		*/
		~PacketConnect();

		/**
		* \fn std::string getCode() const
		* \brief Récuperation du code dans les données
		*
		* \return Une instance du code contenu dans les données
		*/
		uint16_t getCode() const;
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
    uint16_t _code; /** \brief _code : contiendra le code à serialier dans le paquet */
	};
};

#endif
