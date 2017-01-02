//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Mon Jan  2 09:31:33 2017 Lecoq Maxime
//

#ifndef _MONSTERSHOOT_HPP_
# define _MONSTERSHOOT_HPP_

#include "DataShoot.hpp"

class MonsterShoot : public DataShoot
{
public:
	MonsterShoot() : DataShoot() { 
		this->_spriteFileName = "Shot-Enemy7";
		this->setSizeX(8 * 2);
		this->setSizeY(8 * 2);
		this->setHitBoxSizeX(8 * 2);
		this->setHitBoxSizeY(8 * 2);
		this->_damage = 3;
		};
  ~MonsterShoot() {};

  void move() { this->_x += -1; };
};

#endif //_MONSTERSHOOT_HPP_
