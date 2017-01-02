
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
		this->_damage = 5;
	};
void move() {

		static uint8_t shot = 0;
		if (shot % 2 == 0)		{			_y += -1;			if (_x % 100 == 0)			{				_y += 5;			}			_x -= 1;			shot++;		}		else		{			_y += 1;			if (_x % 100 == 0)			{				_y -= 5;			}			_x -= 1;			shot++;
		}
	};
};

#endif
