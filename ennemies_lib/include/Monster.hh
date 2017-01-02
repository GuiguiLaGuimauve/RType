//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:13:44 2016 La Guimauve
// Last update Mon Jan  2 02:18:25 2017 Lecoq Maxime
//

#ifndef _MONSTER_HH_
# define _MONSTER_HH_

#include <utility>
#include <vector>
#include "DataEnnemy.hpp"
#include "DataShoot.hpp"

#ifdef _WIN32
# define MONSTER_API __declspec(dllexport)
#endif //_WIN32

class Monster : public DataEnnemy
{
private:

public:
  Monster();
  std::vector<DataShoot *> getShoot();
  DataEnnemy *getNewEnnemy();
};

extern "C"
#ifdef _WIN32
MONSTER_API
#endif //_WIN32
DataEnnemy	*entrypoint();

#endif //_MONSTER_HH_
