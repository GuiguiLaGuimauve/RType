//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:13:44 2016 La Guimauve
// Last update Sun Jan  1 23:29:38 2017 Lecoq Maxime
//

#ifndef _PIRATE_HH_
# define _PIRATE_HH_

#include <utility>
#include <vector>
#include "DataEnnemy.hpp"
#include "DataShoot.hpp"

#ifdef _WIN32
# define PIRATE_API __declspec(dllexport)
#endif //_WIN32

class Pirate : public DataEnnemy
{
private:

public:
  Pirate();
  void move();
  DataShoot *getShoot();
  DataEnnemy *getNewEnnemy();
};

extern "C"
#ifdef _WIN32
PIRATE_API
#endif //_WIN32
DataEnnemy	*entrypoint();

#endif //_PIRATE_HH_
