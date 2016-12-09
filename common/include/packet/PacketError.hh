//
// This file was auto-generated, please do not edit it !
//

#ifndef __PACKETERROR_HH__
#define __PACKETERROR_HH__

#include <stdint.h>
#include <string>
#include "APacket.hh"

namespace Packet {

	class PacketError : public APacket {

	public:
		PacketError(const std::string & message, const IPacket::PacketType & errorType);
		PacketError(const uint8_t *data);
		~PacketError();

		std::string getMessage() const;
		IPacket::PacketType getErrorType() const;

	protected:
		std::string _message;
		IPacket::PacketType _errorType;
	};
};

#endif