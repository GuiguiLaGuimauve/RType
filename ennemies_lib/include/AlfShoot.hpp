//
// C:\Users\Guimauve\Documents\RType\ennemies_lib\include\AlfShoot.hpp for Rtype in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Sun Jan  1 18:57:24 2017 La Guimauve
// Last update Mon Jan  2 09:31:47 2017 Lecoq Maxime
//

#ifndef _ALFSHOOT_HPP_
# define _ALFSHOOT_HPP_

#include "DataShoot.hpp"

class AlfShoot : public DataShoot
{
public:
	AlfShoot() : DataShoot()
	{
		this->_spriteFileName = "Shot-Enemy8";
		this->setSizeX(8 * 2);
		this->setSizeY(8 * 2);
		this->setHitBoxSizeX(8 * 2);
		this->setHitBoxSizeY(8 * 2);
		
		this->_damage = 5;
		
		_pattern.clear();
		std::pair<int8_t, int8_t> a(-2, 0);
		_pattern.push_back(a);
  };
  ~AlfShoot() {};
};

#endif //_ALFSHOOT_HPP_
