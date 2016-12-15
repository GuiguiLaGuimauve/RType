//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATASHOOT_HH__
#define __DATASHOOT_HH__

#include <stdint.h>
#include <string>

namespace Packet {

	class DataShoot {

	public:
		DataShoot() {};
		~DataShoot() {};

		std::string getName() const { return (_name); };
		uint8_t getX() const { return (_x); };
		uint8_t getY() const { return (_y); };
		uint8_t getDamage() const { return (_damage); };

		void setName(const std::string & name) { _name = name; };
		void setX(const uint8_t & x) { _x = x; };
		void setY(const uint8_t & y) { _y = y; };
		void setDamage(const uint8_t & damage) { _damage = damage; };

	protected:
		std::string _name;
		uint8_t _x;
		uint8_t _y;
		uint8_t _damage;
	};
};

#endif