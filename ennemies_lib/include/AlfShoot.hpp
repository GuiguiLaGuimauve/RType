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
public:
  AlfShoot() {};
  ~AlfShoot() {};

  void move() { this->_x -= 1; };
  void setDamage(const uint8_t & damage) { this->_damage = damage; };
};

#endif //_ALFSHOOT_HPP_
