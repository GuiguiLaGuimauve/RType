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
	this->setSizeX(155 * 3);
	this->setSizeY(204 * 3);
	this->setHitBoxSizeX(155 * 3);
	this->setHitBoxSizeY(204 * 3);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Bydos");
	this->setHealth(5000);
}

void Bydos::move()
{
	static int state = -1;
	static int wait = 0;
	
	if (_x > 1200)
		_x += -3;
	_y += state * 2;
	wait++;
	if (wait == 10)
	{
		wait = 0;
		state *= -1;
	}
}

std::vector<DataShoot *> Bydos::getShoot()
{
	std::vector<DataShoot *> tmp;
  DataShoot *d = new BydosShoot;
  d->setX(_x);
  d->setY(_y + 306);
  tmp.push_back(d);
  return (tmp);
}

bool	Bydos::isBoss() const
{
  return (true);
}

DataEnnemy *Bydos::getNewEnnemy()
{
  return (new Bydos);
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
