//
// Background.hh // Maxime BACONNAIS
//

#ifndef __BACKGROUND_HH__
#define __BACKGROUND_HH__

#include <stdint.h>
#include <vector>
#include "AElement.hh"

namespace Element {

	/*! Class Background represent a background on the map */
	class Background : public AElement {

	public:
		/*! Create a new background instance */
		Background(int16_t x, int16_t y);
		
		/*! Background destructor */
		~Background();

	private:
	};
};

#endif