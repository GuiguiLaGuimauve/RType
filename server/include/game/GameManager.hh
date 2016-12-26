//
// GameManager.hh for GameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:52:02 2016 Maxime Lecoq
// Last update Mon Dec 26 12:02:08 2016 lecoq
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include	<vector>
# include	"IGameManager.hh"
# include	"Game.hh"
# include	"DataRoom.hpp"
# include	"PacketFactory.hh"

class GameManager : public IGameManager
{
public:
  GameManager();
  ~GameManager();
  void		createGame(DataRoom *, const uint8_t *);
  void		setFactory(PacketFactory *);
private:
  std::vector<IGame *>	_gameList;
  PacketFactory	*_factory;
};

#endif /* !GAMEMANAGER_HH_ */
