
#ifndef __BYDOSSHOOT_HH__
#define __BYDOSSHOOT_HH__

#include <stdint.h>
#include <string>
#include "AData.hh"


class BydosShoot : public DataShoot {

public:
	BydosShoot() : DataShoot() {
		this->_spriteFileName = "Shot-Bydos";
		this->setSizeX(8 * 3);
		this->setSizeY(8 * 3);
		this->setHitBoxSizeX(8 * 3);
		this->setHitBoxSizeY(8 * 3);
		this->_damage = 30;
	};
	void move() { _x += -1; };
};

#endif
