//
// IGameManager.hh for IGameManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:46:33 2016 Maxime Lecoq
// Last update Mon Dec 26 12:37:46 2016 lecoq
//

#ifndef IGAMEMANAGER_HH_
# define IGAMEMANAGER_HH_

# include	"Game.hh"
# include	"PacketFactory.hh"

class		IGameManager
{
public:
  virtual ~IGameManager() {};
  virtual void createGame(DataRoom *, const uint8_t *) = 0;
  virtual void setFactory(PacketFactory *) = 0;
};

#endif /* !IGAMEMANAGER_HH_ */
