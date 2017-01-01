//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:13:44 2016 La Guimauve
// Last update Sun Jan  1 23:27:27 2017 Lecoq Maxime
//

#ifndef _ALF_HH_
# define _ALF_HH_

#include <utility>
#include <vector>
#include "DataEnnemy.hpp"
#include "DataShoot.hpp"

#ifdef _WIN32
# define ALF_API __declspec(dllexport)
#endif //_WIN32

class Alf : public DataEnnemy
{
private:

public:
  Alf();
  void move();
  DataShoot *getShoot();
  DataEnnemy *getNewEnnemy();
};

extern "C"
#ifdef _WIN32
ALF_API
#endif //_WIN32
DataEnnemy	*entrypoint();

#endif //_ALF_HH_
