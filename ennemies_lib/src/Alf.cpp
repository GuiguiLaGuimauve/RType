//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Mon Jan  2 09:32:29 2017 Lecoq Maxime
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Alf.hh"
#include "AlfShoot.hpp"

Alf::Alf()
{
  this->setX(0);
  this->setY(0);
  this->setSizeX(24 * 3);
	this->setSizeY(21 * 3);
	this->setHitBoxSizeX(24 * 3);
	this->setHitBoxSizeY(21 * 3);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Enemy8");
	this->setHealth(50);
}

void Alf::move()
{
	static uint8_t mo = 0;

	if (_x > 500)
		_y -= 1;
	else
		_y += 1;
	_x -= 1;
}

std::vector<DataShoot *> Alf::getShoot()
{
	std::vector<DataShoot*> tmp;
	DataShoot *d = new AlfShoot;
	d->setX(_x);
	d->setY(_y + 31);
	tmp.push_back(d);
	return (tmp);
}

DataEnnemy *Alf::getNewEnnemy()
{
  return (new Alf);
}

extern "C"
#ifdef _WIN32
ALF_API
#endif //_WIN32
 DataEnnemy *entrypoint()
{
	DataEnnemy *tmp = new Alf();
	return (tmp);
}
