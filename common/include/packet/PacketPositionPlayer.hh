//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPOSITIONPLAYER_HH__
#define __PACKETPOSITIONPLAYER_HH__

#include <stdint.h>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketPositionPlayer PacketPositionPlayer.hh
		\brief classe du paquet "position player", envoi les positions du joueur
	*/
	class PacketPositionPlayer : public APacket {

	public:
		/**
		* \fn PacketPositionPlayer(const uint16_t &, const uint16_t &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param x Position en x du joueur
		* \param y Position en y du joueur
		*/
		PacketPositionPlayer(const uint16_t & x, const uint16_t & y);
		/**
		* \fn PacketPositionPlayer(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketPositionPlayer(const uint8_t *data);
		/**
		* \fn ~PacketPositionPlayer()
		* \brief Destructeur du packet.
		*/
		~PacketPositionPlayer();

		/**
		* \fn std::string getX() const
		* \brief Récuperation de la position en x dans les données
		*
		* \return Une instance de la position en x dans les données
		*/
		uint16_t getX() const;
		/**
		* \fn std::string getY() const
		* \brief Récuperation de la position en y dans les données
		*
		* \return Une instance de la position en y dans les données
		*/
		uint16_t getY() const;
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
		uint16_t _x; /** \brief _x : contiendra la position en x à serialiser dans le paquet */
		uint16_t _y; /** \brief _y : contiendra la position en y à serialiser dans le paquet */
	};
};

#endif
