//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETPLAYERS_HH__
#define __PACKETPLAYERS_HH__

#include <stdint.h>
#include <vector>
#include "APacket.hh"
#include "DataPlayer.hpp"

namespace Packet {
	/*!
		\class PacketPlayers PacketPlayers.hh
		\brief classe du paquet "players", envoi toutes les informations relatives aux joueurs
	*/
	class PacketPlayers : public APacket {

	public:
		/**
		* \fn PacketPlayers(const std::vector<DataPlayer *> &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param player Containeur qui contient toutes les informations relatives aux joueurs
		*/
		PacketPlayers(const std::vector<DataPlayer *> & players);
		/**
		* \fn PacketPlayers(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketPlayers(const uint8_t *data);
		/**
		* \fn ~PacketPlayers()
		* \brief Destructeur du packet.
		*/
		~PacketPlayers();

		/**
		* \fn std::vector<DataPlayer *> getPlayers() const
		* \brief Récuperation du message dans les données
		*
		* \return Un containeur regroupant toutes les informations des joueurs
		*/
		std::vector<DataPlayer *> getPlayers() const;
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
		std::vector<DataPlayer *> _players; /** \brief _players : containeur regroupant les informations sur tout les joueurs à serialiser dans le paquet */
	};
};

#endif
