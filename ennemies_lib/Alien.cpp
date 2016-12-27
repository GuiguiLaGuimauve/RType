//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Tue Dec 27 17:52:34 2016 La Guimauve
//

#include <cmath>
#include "Alien.hh"

Alien::Alien()
{
	_sizeX = 1;
	_sizeY = 1;
	_hitboxDeltaX = 1;
	_hitboxDeltaX = 1;
	_hitboxSizeX = 1;
	_hitboxSizeY = 1;
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

std::vector<std::pair<uint16_t, uint16_t>> Alien::getPositions()
{
	std::vector<std::pair<uint16_t, uint16_t>> tmp;
	std::pair<uint16_t, uint16_t> ptmp;

	for (uint16_t f = 8; f > 0; f--)
	{
		ptmp.first = f;
		ptmp.second = 0;
		tmp.push_back(ptmp);
	}
	return (tmp);
}
