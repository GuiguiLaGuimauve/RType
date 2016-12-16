//
// Player.cpp // Maxime BACONNAIS
//

#include <stdint.h>
#include <vector>
#include "Player.hh"

Player::Player(uint8_t id, int16_t x, int16_t y)
{
	_x = x;
	_y = y;
}

Player::~Player()
{	
}