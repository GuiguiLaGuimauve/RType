
#ifndef __BYDOSSHOOT_HH__
#define __BYDOSSHOOT_HH__

#include <stdint.h>
#include <string>
#include "AData.hh"


class BydosShoot : public DataShoot {

public:
	BydosShoot() : DataShoot() {
		this->_spriteFileName = "Shot-Bydos";
		this->setSizeX(8 * 2);
		this->setSizeY(8 * 2);
		this->setHitBoxSizeX(8 * 2);
		this->setHitBoxSizeY(8 * 2);
		_damage = 30;
	};
	void move() { _x += -4; };
protected:
	uint8_t _damage;
};

#endif