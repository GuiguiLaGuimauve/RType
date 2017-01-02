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
		if (_spriteFileName == "Env-1")
		{
			this->setSizeX(128 * 2);
			this->setSizeY(128 * 2);
			this->setHitBoxSizeX(128 * 2);
			this->setHitBoxSizeY(128 * 2);
			this->setDeltaHitBoxX(0);
			this->setDeltaHitBoxY(0);
		}
		if (_spriteFileName == "Env-2")
		{
			this->setSizeX(128 * 2);
			this->setSizeY(66 * 2);
			this->setHitBoxSizeX(128 * 2);
			this->setHitBoxSizeY(66 * 2);
			this->setDeltaHitBoxX(0);
			this->setDeltaHitBoxY(0);
		}
	  }
	private:
	  int8_t _speed;
	};
};

#endif
