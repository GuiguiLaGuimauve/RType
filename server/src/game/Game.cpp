//
// Game.cpp for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:45:57 2016 Maxime Lecoq
// Last update Mon Dec 26 17:05:49 2016 lecoq
//

#include	"Game.hh"

Game::Game(DataRoom *p) : _room(p), _timeline(0) {}
Game::~Game() {}

std::vector<std::string> Game::getAllName() const
{
  uint64_t	i;
  std::vector<std::string> ret;

  i = 0;
  while (i < _room->getPlayers().size())
    {
      ret.push_back(_room->getPlayers()[i]->getName());
      i++;
    }
  i = 0;
  while (i < _room->getWatchers().size())
    {
      ret.push_back(_room->getWatchers()[i]->getName());
      i++;
    }
  return (ret);
}

std::vector<std::string> Game::getPlayersName() const
{
  uint64_t	i;
  std::vector<std::string> ret;

  i = 0;
  while (i < _room->getPlayers().size())
    {
      ret.push_back(_room->getPlayers()[i]->getName());
      i++;
    }
  return (ret);
}

void		Game::setFactory(PacketFactory *p) { _factory = p; }
void		Game::setUdp(IManageNetwork *u) { _udp = u; }

void		Game::run()
{
}

void		Game::end()
{
  _room->setStarted(false);
}

void		Game::timeLine()
{
}
