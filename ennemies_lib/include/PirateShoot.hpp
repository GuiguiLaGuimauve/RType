//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Sun Jan  1 22:59:47 2017 La Guimauve
//

#ifndef _PIRATESHOOT_HPP_
# define _PIRATESHOOT_HPP_

#include "DataShoot.hpp"

class PirateShoot : public DataShoot
{
public:
	PirateShoot() { 
	
		this->_spriteFileName = "Shot-Enemy1";
		this->setSizeX(8 * 2);
		this->setSizeY(8 * 2);
		this->setHitBoxSizeX(8 * 2);
		this->setHitBoxSizeY(8 * 2);
	
		this->_damage = 2;
		
	};
  ~PirateShoot() {};

  void move() { this->_x -= 2; };
};

#endif //_PIRATESHOOT_HPP_
