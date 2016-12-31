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
	  DataShoot(const uint16_t &x, const uint16_t &y) :  _x(x), _y(y), _damage(10) {};
	  DataShoot(const DataShoot *c) : _x(c->_x), _y(c->_y), _damage(c->_damage) {};
	  DataShoot(const DataShoot &c) : _x(c._x), _y(c._y), _damage(c._damage) {};
	  ~DataShoot() {};
	  
		uint16_t getX() const { return (_x); };
		uint16_t getY() const { return (_y); };
		uint8_t getDamage() const { return (_damage); };

		void setX(const uint16_t & x) { _x = x; };
		void setY(const uint16_t & y) { _y = y; };
		void setDamage(const uint8_t & damage) { _damage = damage; };

	private:
		uint16_t _x;
		uint16_t _y;
		uint8_t _damage;
	};
};

#endif
