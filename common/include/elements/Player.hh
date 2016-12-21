//
// Player.hh // Maxime BACONNAIS
//

#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include <stdint.h>
#include <vector>
#include "AElement.hh"

namespace Element {

	/*! Class Player represent a player on the map */
	class Player : public AElement {

	public:
		/*! Create a new player instance */
		Player(uint8_t id, int16_t x, int16_t y);
		
		/*! Player destructor */
		~Player();

	private:
		/*! ID of the user */
		uint8_t _id;
	};
};

#endif