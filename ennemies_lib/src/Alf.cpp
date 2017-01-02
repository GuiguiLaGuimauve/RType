//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Mon Jan  2 06:42:30 2017 Lecoq Maxime
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Alf.hh"
#include "AlfShoot.hpp"

Alf::Alf()
{
  _x = 0;
  _y = 0;
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
	this->_x -= 4;
}

DataShoot *Alf::getShoot()
{
  DataShoot *d = new AlfShoot;
  d->setX(_x);
  d->setX(_y + 31);
  return (d);
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
