//
// C:\Users\Guimauve\Documents\RType\common\include\tools\EnnemyGenerator.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sat Dec 31 11:54:04 2016 La Guimauve
// Last update Sat Dec 31 11:54:44 2016 La Guimauve
//

#ifndef __ENNEMYGENERATOR_HH_
# define __ENNEMYGENERATOR_HH_

#include "EnnemyLoader.hh"

class EnnemyGenerator
{
public: 
	std::vector<Ennemy *> loadAllEnnemy();
};

#endif //__ENNEMYGENERATOR_HH_