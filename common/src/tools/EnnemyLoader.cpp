//
// C:\Users\Guimauve\Documents\RType\common\src\tools\EnnemyLoader.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec 28 09:24:15 2016 La Guimauve
// Last update Thu Dec 29 20:13:59 2016 La Guimauve
//

#include "EnnemyLoader.hh"

IElement &EnnemyLoader::LoadEnnemy(const std::string &lib)
{
	IElement *dflt = new Ennemy(0, 0);

	try {
		//IElement *tmp = new Ennemy(0, 0);
		#ifndef _WIN32
		DLloaderUnix<Ennemy *()> dl_ui16;
			// DLloaderUnix<uint16_t()> dl_ui16;
			// DLloaderUnix<int32_t()> dl_i32;
			// DLloaderUnix<uint32_t()> dl_ui32;
			// DLloaderUnix<char *()> dl_s;
			// DLloaderUnix<std::vector<std::pair<int16_t, int16_t>>()> dl_v;
		#else
		DLloaderWin<Ennemy *()> dl_ui16;
			/*DLloaderWin<int32_t()> dl_i32;
			DLloaderWin<uint32_t()> dl_ui32;
			DLloaderWin<char *()> dl_s;
			DLloaderWin<std::vector<std::pair<int16_t, int16_t>>()> dl_v;*/
		#endif //_WIN32

		std::cout << "We looking for " << ENNEMY_LIB_PATH + lib << std::endl;
		dl_ui16.loadLib(ENNEMY_LIB_PATH + lib);
		/*dl_i32.loadLib(ENNEMY_LIB_PATH + lib);
		dl_ui32.loadLib(ENNEMY_LIB_PATH + lib);
		dl_v.loadLib(ENNEMY_LIB_PATH + lib);
*/
		dl_ui16.extractLib("entrypoint");
		Ennemy *tmp = dl_ui16._func();
		std::cout << tmp->getSizeX() << std::endl;
		std::cout << tmp->getSizeY() << std::endl;
		std::cout << tmp->getSpriteName() << std::endl;
		/*dl_ui16.extractLib("getSizeY");
		tmp->setSizeY(dl_ui16._func());
		dl_i32.extractLib("getHitboxDeltaX");
		tmp->setDeltaHitBoxX(dl_i32._func());
		dl_i32.extractLib("getHitboxDeltaY");
		tmp->setDeltaHitBoxY(dl_i32._func());
		dl_ui32.extractLib("getHitboxSizeX");
		tmp->setHitBoxSizeX(dl_ui32._func());
		dl_ui32.extractLib("getHitboxSizeY");
		tmp->setHitBoxSizeY(dl_ui32._func());*/
		/*dl_s.extractLib("getSpriteName");
		tmp->setSpriteName(dl_s._func());
		dl_v.extractLib("getPositions");
		tmp->setPositions(dl_v._func());*/
		return (*tmp);
	} catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	return (*dflt);
}
