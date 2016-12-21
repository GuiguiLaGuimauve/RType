//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETERROR_HH__
#define __PACKETERROR_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketError PacketError.hh
		\brief classe du paquet "error", envoyé en cas d'erreur
	*/
	class PacketError : public APacket {

	public:
		/**
		* \fn PacketError(const std::string &, const IPacket::PacketType &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param message Message qui sera contenu dans les données du paquet.
		* \param errorType Type du paquet qui à lancé l'erreur.
		*/
		PacketError(const std::string & message, const IPacket::PacketType & errorType);
		/**
		* \fn PacketError(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketError(const uint8_t *data);
		/**
		* \fn ~PacketError()
		* \brief Destructeur du packet.
		*/
		~PacketError();

		/**
		* \fn std::string getMessage() const
		* \brief Récuperation du message dans les données
		*
		* \return Une instance du message contenu dans les données
		*/
		std::string getMessage() const;
		/**
		* \fn std::string getErrorType() const
		* \brief Récuperation du type du paquet ayant lancé l'erreur dans les données
		*
		* \return Une instance du type du paquet ayant lancé l'erreur contenu dans les données
		*/
		IPacket::PacketType getErrorType() const;
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
		IPacket::PacketType _errorType; /** \brief _errorType : contiendra le type du paquet qui a lancé à serialiser dans le paquet */
	};
};

#endif
