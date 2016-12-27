//
// GameData.hpp for GameData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Tue Dec 27 12:50:43 2016 Maxime Lecoq
// Last update Tue Dec 27 13:27:10 2016 lecoq
//

#ifndef GAMEDATA_HPP_
# define GAMEDATA_HPP_

class GameData
{
public:
  GameData() {}
  ~GameData() {}
  void init()
  {
    _ended = false;
    _tick = 0;
  }
  void endGame() { _ended = true; }
  bool gameIsEnded() const { return (_ended); }
  void setTick(const uint32_t &i) { _tick = i; }
  uint32_t getTick() const { return (_tick); }
private:
  bool	_ended;
  uint32_t	_tick;
};

#endif /* !GAMEDATA_HPP_ */
