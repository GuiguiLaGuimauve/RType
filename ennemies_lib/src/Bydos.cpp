//
// Bydos
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Bydos.hh"

Bydos::Bydos()
{
	this->setX(0);
	this->setY(0);
	this->setSizeX(160);
	this->setSizeY(210);
	this->setHitBoxSizeX(140);
	this->setHitBoxSizeY(190);
	this->setDeltaHitBoxX(10);
	this->setDeltaHitBoxY(10);
	this->setSpriteName("Bydos");
	this->setHealth(400);
}

void Bydos::move()
{
	static int state = -1;
	
	if (_x > 1200)
		_x += -5;
	if (state == 0)
	{
		_y += state * 10;
		state *= -1;
	}
}

DataShoot *Bydos::getShoot()
{
	return (new BydosShoot);
}

bool	Bydos::isBoss() const
{
  return (true);
}

extern "C"

#ifdef _WIN32
	BYDOS_API
#endif //_WIN32

 DataEnnemy *entrypoint()
{
	DataEnnemy *tmp = new Bydos();
	return (tmp);
}
