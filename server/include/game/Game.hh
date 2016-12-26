//
// Game.hh for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:54:48 2016 Maxime Lecoq
// Last update Mon Dec 26 11:42:30 2016 lecoq
//

#ifndef GAME_HH_
# define GAME_HH_

# include	<iostream>
# include	<string>
# include	<vector>
# include	"IElement.hh"
# include	"IGame.hh"
# include	"DataRoom.hpp"

class Game : public IGame
{
public:
  Game(DataRoom *);
  ~Game();
private:
  std::string			_name;
  IGame::Stage			_stage;
  std::vector<IElement *>	_elementList;
};

#endif /* !GAME_HH_ */
