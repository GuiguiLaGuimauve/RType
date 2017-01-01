//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETACCEPT_HH__
#define __PACKETACCEPT_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketAccept PacketAccept.hh
		\brief classe du paquet "accept", renvoyé lorsque la connexion à été acceptée
	*/
	class PacketAccept : public APacket {

	public:
		/**
 		* \fn PacketAccept(const std::string &)
 		* \brief Constructeur du packet utilisé pour la serialization.
 		*
 		* \param message Message qui sera contenu dans les données du paquet.
 		*/
		PacketAccept(const std::string & message);
		/**
 		* \fn PacketAccept(const uint8_t *)
 		* \brief Constructeur du packet utilisé pour la déserialization.
 		*
 		* \param data données à desarializé.
 		*/
		PacketAccept(const uint8_t *data);
		/**
 		* \fn ~PacketAccept()
 		* \brief Destructeur du packet.
 		*/
		~PacketAccept();

		/**
		* \fn std::string getMessage() const
		* \brief Récuperation du message dans les données
		*
		* \return Une instance du message contenu dans les données
		*/
		std::string getMessage() const;
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

#endif
