//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETJOINROOM_HH__
#define __PACKETJOINROOM_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketJoinRoom PacketJoinRoom.hh
		\brief classe du paquet "join room", envoyé lorsqu'un joueur veux rejoindre une partie
	*/
	class PacketJoinRoom : public APacket {

	public:
		/**
		* \fn PacketJoinRoom(const std::string &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param gameName Nom de la partie qui sera contenu dans les données du paquet.
		*/
		PacketJoinRoom(const std::string & gameName);
		/**
		* \fn PacketJoinRoom(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketJoinRoom(const uint8_t *data);
		/**
		* \fn ~PacketJoinRoom()
		* \brief Destructeur du packet.
		*/
		~PacketJoinRoom();

		/**
		* \fn std::string getGameName() const
		* \brief Récuperation du nom de la partie dans les données
		*
		* \return Une instance du nom de la partie contenu dans les données
		*/
		std::string getGameName() const;
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
		std::string _gameName; /** \brief _gameName : contiendra le nom de la partie à serialiser dans le paquet */
	};
};

#endif
