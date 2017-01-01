//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Sun Jan  1 23:01:40 2017 La Guimauve
//

#ifndef _MONSTERSHOOT_HPP_
# define _MONSTERSHOOT_HPP_

#include "DataShoot.hpp"

class MonsterShoot : public DataShoot
{
public:
	MonsterShoot() { this->_spriteFileName = "Shot-1"; this->_damage = 3; };
  ~MonsterShoot() {};

  void move() { this->_x -= 2; };
};

#endif //_MONSTERSHOOT_HPP_
