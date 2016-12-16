//
// Shoot.hh // Maxime BACONNAIS
//

#ifndef __SHOOT_HH__
#define __SHOOT_HH__

#include <stdint.h>
#include <vector>
#include "AElement.hh"

namespace Element {

	/*! Class Shoot represent a shoot on the map */
	class Shoot : public AElement {

	public:
		/*! Create a new shoot instance */
		Shoot(int16_t x, int16_t y);
		
		/*! Shoot destructor */
		~Shoot();

	protected:
	};
};

#endif