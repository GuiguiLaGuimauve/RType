//
// Bydos
//

#ifndef _BYDOS_HH_
# define _BYDOS_HH_

#include <utility>
#include <vector>
#include "DataEnnemy.hpp"
#include "BydosShoot.hpp"

#ifdef _WIN32
# define BYDOS_API __declspec(dllexport)
#endif //_WIN32

class Bydos : public DataEnnemy
{
public:
	Bydos();
	void move();
	DataShoot *getShoot();
};

extern "C"
#ifdef _WIN32
BYDOS_API
#endif //_WIN32
DataEnnemy	*entrypoint();

#endif //_ALIEN_HH_
