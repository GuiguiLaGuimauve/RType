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
#include "EnnemyGenerator.hh"

std::vector<Ennemy *> EnnemyGenerator::loadAllEnnemy()
{
	EnnemyLoader el;
	std::vector<Ennemy *> tmp;
#ifdef _WIN32
	tmp.push_back(el.LoadEnnemy("Alienlib.dll"));
	tmp.push_back(el.LoadEnnemy("Alflib.dll"));
#else
	tmp.push_back(el.LoadEnnemy("libAlien.so"));
	tmp.push_back(el.LoadEnnemy("libAlf.so"));
#endif // _WIN32
	return (tmp);
}
