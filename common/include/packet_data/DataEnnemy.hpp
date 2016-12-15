//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAENNEMY_HH__
#define __DATAENNEMY_HH__

#include <stdint.h>

namespace Packet {

	class DataEnnemy {

	public:
		DataEnnemy() {};
		~DataEnnemy() {};

		uint8_t getType() const { return (_type); };
		uint8_t getX() const { return (_x); };
		uint8_t getY() const { return (_y); };

		void setType(const uint8_t & type) { _type = type; };
		void setX(const uint8_t & x) { _x = x; };
		void setY(const uint8_t & y) { _y = y; };

	protected:
		uint8_t _type;
		uint8_t _x;
		uint8_t _y;
	};
};

#endif