//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETCHATMESSAGE_HH__
#define __PACKETCHATMESSAGE_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketChatMessage : public APacket {

	public:
		PacketChatMessage(const std::string & login, const std::string & message);
		PacketChatMessage(const uint8_t *data);
		~PacketChatMessage();

		std::string getLogin() const;
		std::string getMessage() const;
		bool isTcp() const;
		bool isUdp() const;

	private:
		std::string _login;
		std::string _message;
	};
};

#endif