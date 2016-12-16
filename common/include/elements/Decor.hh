//
// Decor.hh // Maxime BACONNAIS
//

#ifndef __DECOR_HH__
#define __DECOR_HH__

#include <stdint.h>
#include <vector>
#include "AElement.hh"

namespace Element {

	/*! Class Decor represent a decor on the map */
	class Decor : public AElement {

	public:
		/*! Create a new decor instance */
		Decor(int16_t x, int16_t y);
		
		/*! Decor destructor */
		~Decor();

	protected:
	};
};

#endif