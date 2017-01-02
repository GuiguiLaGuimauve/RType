//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Mon Jan  2 02:01:50 2017 Lecoq Maxime
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Alf.hh"
#include "AlfShoot.hpp"

Alf::Alf()
{
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
	this->_x -= 1;
}

DataShoot *Alf::getShoot()
{
	return (new AlfShoot());
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
