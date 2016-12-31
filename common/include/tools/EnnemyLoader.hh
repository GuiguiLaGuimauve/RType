//
// C:\Users\Guimauve\Documents\RType\common\include\tools\EnnemyLoader.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec 28 08:56:14 2016 La Guimauve
// Last update Wed Dec 28 16:47:58 2016 La Guimauve
//

#ifndef _ENNEMYLOADER_HH_
# define _ENNEMYLOADER_HH_

#include <utility>
#include <vector>
#include "DLloaderUnix.hh"
#include "DLloaderWin.hh"
#include "IDLloader.hh"
#include "IElement.hh"
#include "Ennemy.hh"

#define ENNEMY_LIB_PATH "ennemies_lib/"

/**
* \class EnnemyLoader EnnemyLoader.hh
* \brief classe qui va permettre de charger dynamiquement les ennemis.
*/
class EnnemyLoader
{
public:
    Ennemy *LoadEnnemy(const std::string &);
    void     ReloadEnnemy(IElement &) {};
};

#endif //_ENNEMYLOADER_HH_
