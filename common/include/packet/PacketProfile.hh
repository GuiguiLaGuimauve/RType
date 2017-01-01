//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPROFILE_HH__
#define __PACKETPROFILE_HH__

#include <stdint.h>
#include <string>
#include "DataPlayer.hpp"
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketProfile PacketProfile.hh
		\brief classe du paquet "profile", envoi le profil du joueur
	*/
	class PacketProfile : public APacket {

	public:
		/**
		* \fn PacketProfile(const std::string &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param player est une classe qui contient les informations relatives au joueur
		*/
		PacketProfile(const DataPlayer * player);
		/**
		* \fn PacketProfile(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketProfile(const uint8_t *data);
		/**
		* \fn ~PacketProfile()
		* \brief Destructeur du packet.
		*/
		~PacketProfile();

		/**
		* \fn DataPlayer *getPlayer() const
		* \brief Récuperation des informations du joueur dans les données
		*
		* \return Une instance des informations du joueur contenu dans les données
		*/
		DataPlayer *getPlayer() const;
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
		DataPlayer *_player; /** \brief _player : contiendra les informations du joueur à serialiser dans le paquet */
	};
};

#endif
