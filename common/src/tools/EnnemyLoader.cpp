//
// C:\Users\Guimauve\Documents\RType\common\src\tools\EnnemyLoader.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec 28 09:24:15 2016 La Guimauve
// Last update Sun Jan  1 17:32:07 2017 La Guimauve
//

#include "EnnemyLoader.hh"

DataEnnemy *EnnemyLoader::LoadEnnemy(const std::string &lib)
{
		#ifndef _WIN32
			DLloaderUnix<DataEnnemy *()> dl_ui16;
		#else
			DLloaderWin<DataEnnemy *()> dl_ui16;
		#endif //_WIN32

		dl_ui16.loadLib(ENNEMY_LIB_PATH + lib);

		dl_ui16.extractLib("entrypoint");
		DataEnnemy *tmp = dl_ui16._func();
		return (tmp);
}
