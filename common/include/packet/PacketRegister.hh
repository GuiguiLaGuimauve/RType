//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETREGISTER_HH__
#define __PACKETREGISTER_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketRegister : public APacket {

	public:
		PacketRegister(const std::string & login, const std::string & password);
		PacketRegister(const uint8_t *data);
		~PacketRegister();

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