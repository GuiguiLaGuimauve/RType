//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATABACKGROUND_HH__
#define __DATABACKGROUND_HH__

#include <stdint.h>

namespace Packet {

	class DataBackground {

	public:
		DataBackground() {};
		~DataBackground() {};

		uint8_t getType() const { return (_type); };
		uint16_t getX() const { return (_x); };
		uint16_t getY() const { return (_y); };

		void setType(const uint8_t & type) { _type = type; };
		void setX(const uint16_t & x) { _x = x; };
		void setY(const uint16_t & y) { _y = y; };

	protected:
		uint8_t _type;
		uint16_t _x;
		uint16_t _y;
	};
};

#endif