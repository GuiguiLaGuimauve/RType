//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCREATEROOM_HH__
#define __PACKETCREATEROOM_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketCreateRoom PacketCreateRoom.hh
		\brief classe du paquet "create room", envoyé lorsque le client veut créer une nouvelle partie
	*/
	class PacketCreateRoom : public APacket {

	public:
		/**
		* \fn PacketCreateRoom(const std::string &,  const uint8_t & )
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param gameName Nom de la partie qui sera créée
		* \param maxPlayers Nombre maximum de joueurs pouvant rejoindre la partie
		*/
		PacketCreateRoom(const std::string & gameName, const uint8_t & maxPlayers);
		/**
		* \fn PacketCreateRoom(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketCreateRoom(const uint8_t *data);
		/**
		* \fn ~PacketCreateRoom()
		* \brief Destructeur du packet.
		*/
		~PacketCreateRoom();

		/**
		* \fn std::string getGameName() const;
		* \brief Récuperation du nom de la partie dans les données
		*
		* \return Une instance du nom de la partie contenu dans les données
		*/
		std::string getGameName() const;
		/**
		* \fn uint8_t getMaxPlayers() const;
		* \brief Récuperation du nombre maximum de joueurs dans la partie dans les données
		*
		* \return Une instance du nombre maximum de joueurs dans la partie contenu dans les données
		*/
		uint8_t getMaxPlayers() const;
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
		uint8_t _maxPlayers; /** \brief _maxPlayers : contiendra le nombre maximum de joueurs à serialiser dans le paquet */
	};
};

#endif
