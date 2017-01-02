//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Mon Jan  2 09:31:24 2017 Lecoq Maxime
//

#ifndef _PIRATESHOOT_HPP_
# define _PIRATESHOOT_HPP_

#include "DataShoot.hpp"

class PirateShoot : public DataShoot
{
public:
	PirateShoot() : DataShoot() { 
	
		this->_spriteFileName = "Shot-Enemy1";
		this->setSizeX(8 * 3);
		this->setSizeY(8 * 3);
		this->setHitBoxSizeX(8 * 3);
		this->setHitBoxSizeY(8 * 3);
	
		this->_damage = 2;
		
	};
  ~PirateShoot() {};

  void move() { this->_x += -1; };
};

#endif //_PIRATESHOOT_HPP_

