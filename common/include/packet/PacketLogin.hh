//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETLOGIN_HH__
#define __PACKETLOGIN_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {
	/*!
		\class PacketLogin PacketLogin.hh
		\brief classe du paquet "login", envoyé lorsque le client s'identifie sur le serveur
	*/
	class PacketLogin : public APacket {

	public:
		/**
		* \fn PacketLogin(const std::string &, const std::string &)
		* \brief Constructeur du packet utilisé pour la serialization.
		*
		* \param login Identifiant du joueur
		* \param password Mot de passe du joueur
		*/
		PacketLogin(const std::string & login, const std::string & password);
		/**
		* \fn PacketLogin(const uint8_t *)
		* \brief Constructeur du packet utilisé pour la déserialization.
		*
		* \param data données à desarializé.
		*/
		PacketLogin(const uint8_t *data);
		/**
		* \fn ~PacketLogin()
		* \brief Destructeur du packet.
		*/
		~PacketLogin();

		/**
		* \fn std::string getLogin() const
		* \brief Récuperation de l'identifant du joueur dans les données
		*
		* \return Une instance de l'identifant du joueur contenu dans les données
		*/
		std::string getLogin() const;
		/**
		* \fn std::string getPassword() const
		* \brief Récuperation le mot de passe du joueur dans les données
		*
		* \return Une instance de l'identifant du joueur contenu dans les données
		*/
		std::string getPassword() const;
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
		std::string _login; /** \brief _login : contiendra l'identifant du joueur à serialiser dans le paquet */
		std::string _password; /** \brief _password : contiendra le mot de passe du joueur à serialiser dans le paquet */
	};
};

#endif
