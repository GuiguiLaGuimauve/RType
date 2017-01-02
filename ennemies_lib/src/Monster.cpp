//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alf.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:34:43 2016 La Guimauve
// Last update Mon Jan  2 06:32:14 2017 Lecoq Maxime
//

#include <utility>
#include <vector>
#include <cmath>
#include <cstdint>
#include "Monster.hh"
#include "MonsterShoot.hpp"

Monster::Monster()
{
	this->setX(0);
	this->setY(0);
	this->setSizeX(31 * 3);
	this->setSizeY(28 * 3);
	this->setHitBoxSizeX(31 * 3);
	this->setHitBoxSizeY(28 * 3);
	this->setDeltaHitBoxX(0);
	this->setDeltaHitBoxY(0);
	this->setSpriteName("Enemy7");
	this->setHealth(15);
	std::pair<int8_t, int8_t> a(-3, -4);
	std::pair<int8_t, int8_t> b(-2, 0);
	std::pair<int8_t, int8_t> c(-3, 4);
	for (uint64_t i = 0; i < 20; i++)
	  _pattern.push_back(a);
	for (uint64_t i = 0; i < 10; i++)
	  _pattern.push_back(b);
	for (uint64_t i = 0; i < 20; i++)
	  _pattern.push_back(c);
	for (uint64_t i = 0; i < 10; i++)
	  _pattern.push_back(b);
	}

DataShoot *Monster::getShoot()
{
  DataShoot *d = new MonsterShoot;

  d->setX(_x);
  d->setY(_y + 42);
  return (d);
}

DataEnnemy *Monster::getNewEnnemy()
{
  return (new Monster);
}

extern "C"
#ifdef _WIN32
MONSTER_API
#endif //_WIN32
 DataEnnemy *entrypoint()
{
	DataEnnemy *tmp = new Monster();
	return (tmp);
}
