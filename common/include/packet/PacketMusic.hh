//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETMUSIC_HH__
#define __PACKETMUSIC_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketMusic PacketMusic.hh
		\brief classe du paquet "music", envoi les données relatives à la musique du jeu
	*/
	class PacketMusic : public APacket {

	public:
		/**
		* \fn PacketMusic(const std::string &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param music Nom du fichier de musique à lire
		*/
		PacketMusic(const std::string & music);
		/**
		* \fn PacketMusic(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketMusic(const uint8_t *data);
		/**
		* \fn ~PacketMusic()
		* \brief Destructeur du packet.
		*/
		~PacketMusic();

		/**
		* \fn std::string getMusic() const
		* \brief Récuperation du nom du fichier audio dans les données
		*
		* \return Une instance du nom du fichier audio contenu dans les données
		*/
		std::string getMusic() const;
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
		std::string _music; /** \brief _music : contiendra le nom du fichier audio à serialiser dans le paquet */
	};
};

#endif
