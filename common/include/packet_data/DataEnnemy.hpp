//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAENNEMY_HH__
#define __DATAENNEMY_HH__

#include <string>
#include <stdint.h>

namespace Packet {

	class DataEnnemy {

	public:
		DataEnnemy() {};
		~DataEnnemy() {};

		std::string getName() const { return (_name); };
		uint16_t getX() const { return (_x); };
		uint16_t getY() const { return (_y); };

		void setName(const std::string & name) { _name = name; };
		void setX(const uint16_t & x) { _x = x; };
		void setY(const uint16_t & y) { _y = y; };

	private:
		std::string _name;
		uint16_t _x;
		uint16_t _y;
	};
};

#endif