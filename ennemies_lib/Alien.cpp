//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Thu Dec 29 20:27:53 2016 La Guimauve
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Alien.hh"

Alien::Alien() : Ennemy(0, 0)
{
	this->setSizeX(1);
	this->setSizeY(1);
	this->setDeltaHitBoxX(1);
	this->setDeltaHitBoxY(1);
	this->setSpriteName("Bydos");
	this->setType(IElement::ElementType::ENNEMY);
	this->setPositions(getPositions());
}

uint16_t Alien::getSizeX()
{
  return (1);
}

uint16_t Alien::getSizeY()
{
  return (1);
}

int32_t  Alien::getHitboxDeltaX()
{
  return (1);
}

int32_t  Alien::getHitboxDeltaY()
{
  return (1);
}

uint32_t Alien::getHitboxSizeX()
{
  return (1);
}

uint32_t Alien::getHitboxSizeY()
{
  return (1);
}

std::string Alien::getSpriteName()
{
	return ("Bydos");
}

 std::vector<std::pair<int16_t, int16_t>> Alien::getPositions()
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
ALIEN_API
#endif //_WIN32
 Ennemy *entrypoint()
{
	Ennemy *tmp = new Alien();
	return (tmp);
}
