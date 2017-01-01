
#ifndef __BYDOSSHOOT_HH__
#define __BYDOSSHOOT_HH__

#include <stdint.h>
#include <string>
#include "AData.hh"


class BydosShoot : public DataShoot {

public:
	BydosShoot() : DataShoot() { _damage = 10; _spriteFileName = "ShootBydos"; };
	virtual void move() { _x += -10; };
protected:
	uint8_t _damage;
};

#endif