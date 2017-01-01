//
// C:\Users\Guimauve\Documents\RType\common\src\tools\EnnemyGenerator.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sat Dec 31 11:54:26 2016 La Guimauve
// Last update Sat Dec 31 23:21:38 2016 La Guimauve
//

#include <vector>
#include "DataEnnemy.hpp"
#include "EnnemyGenerator.hh"

std::vector<DataEnnemy *> EnnemyGenerator::loadAllEnnemy()
{
	EnnemyLoader el;
	std::vector<DataEnnemy *> tmp;
#ifdef _WIN32
	tmp.push_back(el.LoadEnnemy("Alien.dll"));
	tmp.push_back(el.LoadEnnemy("Alf.dll"));
#else
	tmp.push_back(el.LoadEnnemy("libAlien.so"));
	tmp.push_back(el.LoadEnnemy("libAlf.so"));
#endif // _WIN32
	return (tmp);
}
