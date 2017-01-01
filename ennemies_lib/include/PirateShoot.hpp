//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Sun Jan  1 19:23:30 2017 La Guimauve
//

#ifndef _ALFSHOOT_HPP_
# define _ALFSHOOT_HPP_

#include "DataShoot.hpp"

class PirateShoot : public DataShoot
{
protected:
	uint8_t _damage;
public:
	PirateShoot() { this->_spriteFileName = "Shot-1"; this->_damage = 2; };
  ~PirateShoot() {};

  void move() { this->_x -= 2; };
};

#endif //_ALFSHOOT_HPP_
