//
// Game.hh for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:48 2016 Maxime Lecoq
// Last update Thu Dec 15 11:57:49 2016 lecoq
//

#ifndef GAME_HH_
# define GAME_HH_

# include	"IELement.hh"
# include	"IGame.hh"

class Game : public IGame
{
public:
  Game();
  ~Game();
private:
  std::string			_name;
  IGame::Stage			_stage;
  std::vector<IElement *>	_elementList;
};

#endif /* !GAME_HH_ */
