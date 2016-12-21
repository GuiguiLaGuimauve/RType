//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETBACKGROUNDS_HH__
#define __PACKETBACKGROUNDS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataBackground.hpp"

namespace Packet {

	/*!
		\class PacketBackgrounds PacketBackgrounds.hh
		\brief classe du paquet "backgrounds", envoi les données relatives au fond dans le jeu
	*/
	class PacketBackgrounds : public APacket {

	public:
		/**
		* \fn PacketBackgrounds(const std::vector<DataBackground *> & backgrounds)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param backgrounds vecteur contenant toutes les informations sur le fond
		*/
		PacketBackgrounds(const std::vector<DataBackground *> & backgrounds);
		/**
		* \fn PacketBackgrounds(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketBackgrounds(const uint8_t *data);
		/**
		* \fn ~PacketBackgrounds()
		* \brief Destructeur du packet.
		*/
		~PacketBackgrounds();

		/**
		* \fn std::vector<DataBackground *> getBackgrounds() const
		* \brief Récuperation du fond dans les données
		*
		* \return Une instance d'un conteneur comprenant tout les fonds contenu dans les données
		*/
		std::vector<DataBackground *> getBackgrounds() const;
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
		std::vector<DataBackground *> _backgrounds;  /** \brief _backgrounds : contiendra un conteneur à serialiser dans le paquet */
	};
};

#endif
