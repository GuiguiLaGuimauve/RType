//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETLOGIN_HH__
#define __PACKETLOGIN_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketLogin : public APacket {

	public:
		PacketLogin(const std::string & login, const std::string & password);
		PacketLogin(const uint8_t *data);
		~PacketLogin();

		std::string getLogin() const;
		std::string getPassword() const;
		bool isTcp() const;
		bool isUdp() const;

	protected:
		std::string _login;
		std::string _password;
	};
};

#endif