//
// C:\Users\Guimauve\Documents\RType\common\src\tools\EnnemyLoader.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec 28 09:24:15 2016 La Guimauve
// Last update Sat Dec 31 12:00:57 2016 La Guimauve
//

#include "EnnemyLoader.hh"

DataEnnemy *EnnemyLoader::LoadEnnemy(const std::string &lib)
{
	DataEnnemy *dflt = new Data::DataEnnemy();




	try {
		#ifndef _WIN32
			DLloaderUnix<Ennemy *()> dl_ui16;
		#else
			DLloaderWin<DataEnnemy *()> dl_ui16;
		#endif //_WIN32

		std::cout << "We looking for " << ENNEMY_LIB_PATH + lib << std::endl;
		dl_ui16.loadLib(ENNEMY_LIB_PATH + lib);

		dl_ui16.extractLib("entrypoint");
		DataEnnemy *tmp = dl_ui16._func();
		return (tmp);
	} catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	return (dflt);
}
