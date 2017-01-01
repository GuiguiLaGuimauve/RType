//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Sat Dec 31 23:26:06 2016 La Guimauve
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Alf.hh"

Alf::Alf()
{
	this->setX(0);
	this->setY(0);
	this->setSizeX(33);
	this->setSizeY(17);
	this->setHitBoxSizeX(33);
	this->setHitBoxSizeY(17);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Vaisseau5");
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
