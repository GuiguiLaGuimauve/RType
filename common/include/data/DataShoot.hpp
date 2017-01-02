//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATASHOOT_HH__
#define __DATASHOOT_HH__

#include <stdint.h>
#include <string>
#include <utility>
#include "AData.hh"

namespace Data {

	class DataShoot : public AData {

	public:
	  DataShoot() {_patternPos = 0; std::pair<int8_t, int8_t> a(1, 0); _pattern.push_back(a); _health = 1; _patternPos = 0; _spriteFileName = "Shot-1";  };
	  DataShoot(const uint16_t &x, const uint16_t &y) { _x = x; _y = y; _damage = 10; _health = 1; _patternPos = 0;};
	  DataShoot(const DataShoot *c) { _x = c->_x; _y = c->_y; _damage = c->_damage; _health = 1; _patternPos = c->_patternPos; _pattern = c->_pattern; };
	  DataShoot(const DataShoot &c) { _x = c._x; _y = c._y, _damage = c._damage; _health = 1; _patternPos = c._patternPos; _pattern = c._pattern; };
	  ~DataShoot() {};
	  
	  uint8_t getDamage() const { return (_damage); };

	  void setDamage(const uint8_t & damage) { _damage = damage; };
	  void move()
	  {
	    _x += _pattern[_patternPos].first;
	    _y += _pattern[_patternPos].second;
	    _patternPos++;
	    if (_patternPos >= _pattern.size())
	      _patternPos = 0;
	  };
	protected:
	  std::vector<std::pair<int8_t, int8_t> > _pattern;
	  uint64_t                              _patternPos;
	  uint8_t _damage;
	};
};

#endif
