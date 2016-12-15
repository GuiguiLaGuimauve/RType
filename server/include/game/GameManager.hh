//
// GameManager.hh for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:52:02 2016 Maxime Lecoq
// Last update Thu Dec 15 11:53:27 2016 lecoq
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include	<vector>
# include	"IGameManager.hh"

class GameManager : public IGameManager
{
public:
  GameManager();
  ~GameManager();
  void		createGame();
private:
  std::vector<IGame *>	_gameList;
};

#endif /* !GAMEMANAGER_HH_ */
