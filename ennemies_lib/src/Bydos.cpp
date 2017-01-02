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
	this->setHitBoxSizeX(130 * 3);
	this->setHitBoxSizeY(204 * 3);
	this->setDeltaHitBoxX(75);
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
	DataShoot *d1 = new BydosShoot;
	DataShoot *d2 = new BydosShoot;
	DataShoot *d3 = new BydosShoot;
	DataShoot *d4 = new BydosShoot;
	d->setX(_x);
	d->setY(_y + 306);
	d1->setX(_x);
	d1->setY(_y + 306);
	d2->setX(_x);
	d2->setY(_y + 306);
	d3->setX(_x);
	d3->setY(_y + 306);
	d4->setX(_x);
	d4->setY(_y + 306);
	tmp.push_back(d);
	tmp.push_back(d1);
	tmp.push_back(d2);
	tmp.push_back(d3);
	tmp.push_back(d4);
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
