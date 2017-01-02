//
// ShootPlayer.hh for ShootPlayer in /home/lecoq/RType
// 
// Made by Lecoq Maxime
// Login   <lecoq@lecoq-epitechHP>
// 
// Started on  Sun Jan  1 16:57:17 2017 Lecoq Maxime
// Last update Sun Jan  1 17:11:28 2017 Lecoq Maxime
//

#ifndef SHOOTPLAYER_HPP_
# define SHOOTPLAYER_HPP_

# include "DataShoot.hpp"

class ShootPlayer : public DataShoot
{
public:
  ShootPlayer() : DataShoot() {}
  ShootPlayer(const uint16_t &x, const uint16_t &y) : DataShoot(x, y) { _damage = 10; } 
  ShootPlayer(const ShootPlayer *c) : DataShoot(c->_x, c->_y) { _damage = c->_damage; };
  ShootPlayer(const ShootPlayer &c) : DataShoot(c._x, c._y) { _damage = c._damage;};
  void move() { _x = _x + 2; };
};

#endif /* !SHOOTPLAYER_HPP_ */
