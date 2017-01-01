//
// C:\Users\Guimauve\Documents\RType\common\src\tools\EnnemyGenerator.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sat Dec 31 11:54:26 2016 La Guimauve
// Last update Sun Jan  1 19:33:25 2017 La Guimauve
//

#include <vector>
#include "DataEnnemy.hpp"
#include "EnnemyGenerator.hh"

std::vector<DataEnnemy *> EnnemyGenerator::loadAllEnnemy()
{
	EnnemyLoader el;
	std::vector<DataEnnemy *> tmp;
	std::vector<std::string> listlib;
#ifdef _WIN32
listlib.push_back("Bydos.dll");
listlib.push_back("Alf.dll");
listlib.push_back("Pirate.dll");
#else
listlib.push_back("libAlf.so");
listlib.push_back("libBydos.so");
listlib.push_back("libPirate.so");
#endif // _WIN32

for (uint64_t i = 0; i < listlib.size(); i++)
{
	try {
		tmp.push_back(el.LoadEnnemy(listlib[i]));
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
	return (tmp);
}
