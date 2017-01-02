//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETENNEMIES_HH__
#define __PACKETENNEMIES_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataEnnemy.hpp"

namespace Packet {
	/*!
		\class PacketEnnemies PacketEnnemies.hh
		\brief classe du paquet "ennemies", paquet contenant toutes les informations relatives au ennemis
	*/
	class PacketEnnemies : public APacket {

	public:
		/**
		* \fn PacketEnnemies(const std::vector<DataEnnemy *> &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param ennemies Conteneur regroupant toutes les informations des ennemis/monstres
		*/
		PacketEnnemies(const std::vector<DataEnnemy *> & ennemies);
		/**
		* \fn PacketEnnemies(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketEnnemies(const uint8_t *data);
		/**
		* \fn ~PacketEnnemies()
		* \brief Destructeur du packet.
		*/
		~PacketEnnemies();

		/**
		* \fn std::vector<DataEnnemy *> getEnnemies() const
		* \brief Récuperation des informations des monstres dans les données
		*
		* \return Une instance d'un conteneur regroupant les informations des monstres contenu dans les données
		*/
		std::vector<DataEnnemy *> getEnnemies() const;
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
		std::vector<DataEnnemy *> _ennemies; /** \brief _ennemies : conteneur qui contient les informations sur les ennemis à serialiser */
	};
};

#endif
