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
		int16_t getX() const { return (_x); };
		int16_t getY() const { return (_y); };

		void setType(const uint8_t & type) { _type = type; };
		void setX(const int16_t & x) { _x = x; };
		void setY(const int16_t & y) { _y = y; };

	private:
		uint8_t _type;
		int16_t _x;
		int16_t _y;
	};
};

#endif