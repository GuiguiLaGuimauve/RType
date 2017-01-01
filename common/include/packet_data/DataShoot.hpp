//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATASHOOT_HH__
#define __DATASHOOT_HH__

#include <stdint.h>
#include <string>
#include "AData.hh"

namespace Data {

	class DataShoot : public AData {

	public:
		DataShoot() {};
	  DataShoot(const uint16_t &x, const uint16_t &y) { _x = x; _y = y; _damage = 10; };
		DataShoot(const DataShoot *c) { _x = c->_x; _y = c->_y; _damage = c->_damage; };
		DataShoot(const DataShoot &c) { _x = c._x; _y = c._y, _damage = c._damage; };
	  ~DataShoot() {};
	  
	  uint8_t getDamage() const { return (_damage); };

	  void setDamage(const uint8_t & damage) { _damage = damage; };
	  virtual void move() {};
	protected:
		uint8_t _damage;
	};
};

#endif
