//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Sun Jan  1 19:03:33 2017 La Guimauve
//

#ifndef _ALFSHOOT_HPP_
# define _ALFSHOOT_HPP_

#include "DataShoot.hpp"

class AlfShoot : public DataShoot
{
protected:
	uint8_t _damage;
public:
	AlfShoot() { this->_spriteFileName = "Shot-1"; this->_damage = 5; };
  ~AlfShoot() {};

  void move() { this->_x -= 3; };
};

#endif //_ALFSHOOT_HPP_
