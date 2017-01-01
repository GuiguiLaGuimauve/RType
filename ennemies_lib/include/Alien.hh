//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\Alien.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 27 13:13:44 2016 La Guimauve
// Last update Thu Dec 29 20:27:17 2016 La Guimauve
//

#ifndef _ALIEN_HH_
# define _ALIEN_HH_

#include <utility>
#include <vector>
#include "DataEnnemy.hpp"

#ifdef _WIN32
# define ALIEN_API __declspec(dllexport)
#endif //_WIN32

class Alien : public DataEnnemy
{
public:
	Alien();
};

extern "C"
#ifdef _WIN32
ALIEN_API
#endif //_WIN32
DataEnnemy	*entrypoint();

#endif //_ALIEN_HH_
