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

Alf::Alf() : Ennemy(0, 0)
{
	this->setSizeX(33);
	this->setSizeY(17);
	this->setHitBoxSizeX(33);
	this->setHitBoxSizeY(17);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Vaisseau5");
	this->setType(IElement::ElementType::ENNEMY);
	this->setPositions(getPositions());
}

uint16_t Alf::getSizeX()
{
  return (1);
}

uint16_t Alf::getSizeY()
{
  return (1);
}

int32_t  Alf::getHitboxDeltaX()
{
  return (1);
}

int32_t  Alf::getHitboxDeltaY()
{
  return (1);
}

uint32_t Alf::getHitboxSizeX()
{
  return (1);
}

uint32_t Alf::getHitboxSizeY()
{
  return (1);
}

std::string Alf::getSpriteName()
{
	return ("Vaisseau5");
}

 std::vector<std::pair<int16_t, int16_t>> Alf::getPositions()
{
	std::vector<std::pair<int16_t, int16_t>> tmp;
	std::pair<int16_t, int16_t> ptmp;

	for (uint16_t f = 8; f > 0; f--)
	{
		ptmp.first = f;
		ptmp.second = 0;
		tmp.push_back(ptmp);
	}
	return (tmp);
}

extern "C"
#ifdef _WIN32
ALF_API
#endif //_WIN32
 Ennemy *entrypoint()
{
	Ennemy *tmp = new Alf();
	return (tmp);
}
