//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Mon Jan  2 04:52:20 2017 Lecoq Maxime
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
	this->setSizeX(21 * 3);
	this->setSizeY(24 * 3);
	this->setHitBoxSizeX(21 * 3);
	this->setHitBoxSizeY(24 * 3);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Enemy1");
	this->setHealth(10);
	uint32_t i;
	std::pair<int8_t, int8_t> a(-2, -2);
	std::pair<int8_t, int8_t> b(-2, 0);
	std::pair<int8_t, int8_t> c(-2, 2);

	std::srand(std::time(0));
	if ((i = std::rand() % 3) == 0)
	  {
	    _pattern.push_back(a);
	    _pattern.push_back(b);
	    _pattern.push_back(b);
	    _pattern.push_back(a);
	    _pattern.push_back(b);
	    _pattern.push_back(b);
	    _pattern.push_back(b);
	  }
	else
	  if (i == 1)
	    {
	      _pattern.push_back(c);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(c);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	    }
	  else
	    {
	      _pattern.push_back(a);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(a);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(c);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(c);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	      _pattern.push_back(b);
	    }
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
