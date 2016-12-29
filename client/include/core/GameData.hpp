//
// GameData.hpp for GameData in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Tue Dec 27 12:50:43 2016 Maxime Lecoq
// Last update Thu Dec 29 17:15:48 2016 lecoq
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
    _marge = 0;
  }
  void endGame() { _ended = true; }
  bool gameIsEnded() const { return (_ended); }
  void setTick(const uint32_t &i) { _tick = i; }
  uint32_t getTick() const { return (_tick + _marge); }
  void	setMarge(const uint32_t &m) { if (_marge == 0) _marge = m; }
  void	addShoot(const uint16_t &x, const uint16_t &y) { DataShoot *s = new DataShoot(x, y); _shoots.push_back(s); }
  std::vector<DataShoot *> getShoots() const { return (_shoots); }
  void reset()
  {
    _ended = true;
    _tick = 0;
    uint64_t i;
    i = 0;
    while (i < _shoots.size())
      {
	delete _shoots[i];
	i++;
      }
    _shoots.clear();
  }
private:
  bool	_ended;
  uint32_t	_tick;
  std::vector<DataShoot *>	_shoots;
  uint32_t	_marge;
};

#endif /* !GAMEDATA_HPP_ */
