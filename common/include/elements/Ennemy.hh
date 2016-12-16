//
// Ennemy.hh // Maxime BACONNAIS
//

#ifndef __ENNEMY_HH__
#define __ENNEMY_HH__

#include <stdint.h>
#include <vector>
#include "AElement.hh"

namespace Element {

	/*! Class Ennemy represent a ennemy on the map */
	class Ennemy : public AElement {

	public:
		/*! Create a new ennemy instance */
		Ennemy(int16_t x, int16_t y);
		
		/*! Ennemy destructor */
		~Ennemy();

	protected:
	};
};

#endif