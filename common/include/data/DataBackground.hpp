//
// This file was auto-generated, please do not edit it !
//

#ifndef __DATABACKGROUND_HH__
#define __DATABACKGROUND_HH__

#include <stdint.h>
#include "AData.hh"

namespace Data {

	class DataBackground : public AData {

	public:
	  DataBackground() : AData() {};
	  DataBackground(const uint16_t &x, const uint16_t &y) : AData() { _x = x; _y = y; _speed = -1;};
	  ~DataBackground() {};

	  int8_t getSpeed() const { return (_speed); };
	  
	  void setSpeed(const int8_t &s) { _speed = s; }
	  void setSpriteName(const std::string &s)
	  {
	    _spriteFileName = s;
	  }
	private:
	  int8_t _speed;
	};
};

#endif
