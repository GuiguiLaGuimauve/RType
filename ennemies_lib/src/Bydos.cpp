//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Sat Dec 31 23:26:23 2016 La Guimauve
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
	this->setSizeX(155);
	this->setSizeY(210);
	this->setHitBoxSizeX(155);
	this->setHitBoxSizeY(210);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Bydos");
}

void Bydos::move()
{
	_x += -1;
}

DataShoot *Bydos::getShoot()
{
	return (new ShootBydos);
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
