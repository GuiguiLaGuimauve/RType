
#ifndef __SHOOTBYDOS_HH__
#define __SHOOTBYDOS_HH__

#include <stdint.h>
#include <string>
#include "AData.hh"


class ShootBydos : public DataShoot {

public:
	ShootBydos() : DataShoot() { _damage = 10; };
	virtual void move() { _x += -1; };
protected:
	uint8_t _damage;
};

#endif