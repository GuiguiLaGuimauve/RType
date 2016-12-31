//
// Game.cpp for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:45:57 2016 Maxime Lecoq
// Last update Sat Dec 31 08:35:08 2016 Lecoq Maxime
//

#include	"Game.hh"

Game::Game(DataRoom *p) : _room(p), _timeline(0)
{
  _ptr[IPacket::PacketType::POSITION_PLAYER] = &IGame::updatePosPlayer;
  _ptr[IPacket::PacketType::SHOOTS] = &IGame::updatePlayerShoots;
}

Game::~Game()
{
}

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

std::vector<std::string> Game::getViewersName() const
{
  uint64_t	i;
  std::vector<std::string> ret;

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

void		Game::movements()
{
  Clock         clo;
  uint64_t	i;
  uint64_t	x;

  x = 0;
  while (_room->getPlayers().size() != 0)
    {
      if (x != (uint64_t)clo.getTimeMilli() / 2)
	{
	  x = clo.getTimeMilli() / 2;
	  i = 0;
	  while (i < _shoots.size())
	    {
	      _shoots[i]->setX(_shoots[i]->getX() + 1);
	      if (_shoots[i]->getX() > 1920)
		_shoots.erase(_shoots.begin() + i);
	      else
		i++;
	    }
	}
    }
}

void		Game::timeLine()
{
  Clock         clo;
  std::vector<std::string> list = getAllName();
  IPacket	*pa;
  _timeline = 0;

  while (_room->getPlayers().size() != 0)
    {
      if (_timeline != (uint64_t)clo.getTimeMilli() / 50)
	{
	  _timeline = clo.getTimeMilli() / 50;
	  pa = _factory->getPacket("players", _room->getPlayers());
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	  pa = _factory->getPacket("shoots", _shoots);
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	}
    }
}

bool		Game::playerPresent(const std::string &pl)
{
  uint64_t	i = 0;

  while (i < _room->getPlayers().size())
    {
      if (_room->getPlayers()[i]->getName() == pl && _room->getPlayers()[i]->getHealth() > 0)
	return (true);
      i++;
    }
  return (false);
}

void		Game::execPacket(const IPacket *pa, const std::string &m)
{
  if (_ptr.find(pa->getType()) != _ptr.end()
      /*&& ((int64_t)(pa->getTickId() - _timeline) == -1 || (uint64_t)pa->getTickId() - _timeline == 0)*/)
    (this->*_ptr[pa->getType()])(pa, m);
}

void		Game::updatePosPlayer(const IPacket *pa, const std::string &m)
{
  uint64_t	i;
  PacketPositionPlayer *p = (PacketPositionPlayer *)pa;

  i = 0;
  while (i < _room->getPlayers().size())
    {
      if (_room->getPlayers()[i]->getName() == m)
	{
	  _room->getPlayers()[i]->setX(p->getX());
	  _room->getPlayers()[i]->setY(p->getY());
	}
      i++;
    }
}

void		Game::updatePlayerShoots(const IPacket *pa, const std::string &m)
{
  uint64_t	i;
  PacketShoots *p = (PacketShoots *)pa;
  std::vector<DataShoot *>	tmp;
  DataPlayer			*pl;
  i = 0;

  while (i < _room->getPlayers().size())
    {
      pl = _room->getPlayers()[i];
      if (pl->getName() == m && pl->getShoots().size() < p->getShoots().size() && p->getShoots().size() != 0)
	{
	  uint64_t	pos = pl->getShoots().size();
	  uint64_t	x = 0;
	  while (x < p->getShoots().size())
	    {
	      if (x < pos)
		{
		  delete p->getShoots()[x];
		  tmp.push_back(pl->getShoots()[x]);
		}
	      else
		{
		  tmp.push_back(p->getShoots()[x]);
		  _shoots.push_back(p->getShoots()[x]);
		}
	      x++;
	    }
	  pl->setShoots(tmp);
	}
      i++;
    }
}
