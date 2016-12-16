//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATAPLAYERPOSITION_HH__
#define __DATAPLAYERPOSITION_HH__

#include <stdint.h>

namespace Packet {

	class DataPlayerPosition {

	public:
		DataPlayerPosition() {};
		~DataPlayerPosition() {};

		uint8_t getId() const { return (_id); };
		uint16_t getX() const { return (_x); };
		uint16_t getY() const { return (_y); };
		uint8_t getHealth() const { return (_health); };

		void setId(const uint8_t & id) { _id = id; };
		void setX(const uint16_t & x) { _x = x; };
		void setY(const uint16_t & y) { _y = y; };
		void setHealth(const uint8_t & health) { _health = health; };

	protected:
		uint8_t _id;
		uint16_t _x;
		uint16_t _y;
		uint8_t _health;
	};
};

#endif