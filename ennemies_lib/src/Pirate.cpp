//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Sun Jan  1 23:33:35 2017 Lecoq Maxime
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Pirate.hh"
#include "PirateShoot.hpp"

Pirate::Pirate()
{
	this->setX(0);
	this->setY(0);
	this->setSizeX(34);
	this->setSizeY(36);
	this->setHitBoxSizeX(34);
	this->setHitBoxSizeY(36);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Enemy7");
	this->setHealth(10);
}

void Pirate::move()
{
	this->_x -= 1;
}

DataShoot *Pirate::getShoot()
{
	return (new PirateShoot());
}


DataEnnemy *Pirate::getNewEnnemy()
{
  return (new Pirate);
}

extern "C"
#ifdef _WIN32
PIRATE_API
#endif //_WIN32
 DataEnnemy *entrypoint()
{
	DataEnnemy *tmp = new Pirate();
	return (tmp);
}
