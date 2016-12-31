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
	  DataBackground(const uint16_t &x, const uint16_t &y) : _x(x), _y(y), _speed(-1) {};
	  ~DataBackground() {};

	  uint8_t getType() const { return (_type); };
	  int16_t getX() const { return (_x); };
	  int16_t getY() const { return (_y); };
	  uint8_t getSpeed() const { return (_speed); };
	  
	  void setType(const uint8_t & type) { _type = type; };
	  void setX(const int16_t & x) { _x = x; };
	  void setY(const int16_t & y) { _y = y; };
	  void setSpeed(const uint8_t &s) { _speed = s; }
	private:
	  uint8_t _type;
	  int16_t _x;
	  int16_t _y;
	  int8_t _speed;
	};
};

#endif
