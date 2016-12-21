//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCHATMESSAGE_HH__
#define __PACKETCHATMESSAGE_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketChatMessage PacketChatMessage.hh
		\brief classe du paquet "ChatMessage", envoyé lorsqu'un client veut chatter avec un autre client
	*/
	class PacketChatMessage : public APacket {

	public:
		/**
		* \fn PacketChatMessage(const std::string &, const std::string &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param login   A qui sera envoyé le message
		* \param message Message qui sera contenu dans les données du paquet.
		*/
		PacketChatMessage(const std::string & login, const std::string & message);
		/**
		* \fn PacketChatMessage(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketChatMessage(const uint8_t *data);
		/**
		* \fn ~PacketChatMessage()
		* \brief Destructeur du packet.
		*/
		~PacketChatMessage();

		/**
		* \fn std::string getLogin() const
		* \brief Récuperation du login dans les données
		*
		* \return Une instance du login contenu dans les données
		*/
		std::string getLogin() const;
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
		std::string _login; /** \brief _login : contiendra le login à serialiser dans le paquet */
		std::string _message; /** \brief _message : contiendra le message à serialiser dans le paquet */
	};
};

#endif
