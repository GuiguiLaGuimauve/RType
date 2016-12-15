//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAPLAYERNAME_HH__
#define __DATAPLAYERNAME_HH__

#include <stdint.h>
#include <string>

namespace Packet {

	class DataPlayerName {

	public:
		DataPlayerName() {};
		~DataPlayerName() {};

		std::string getName() const { return (_name); };

		void setName(const std::string & name) { _name = name; };

	protected:
		std::string _name;
	};
};

#endif