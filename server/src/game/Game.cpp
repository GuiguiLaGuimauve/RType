//
// Game.cpp for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:45:57 2016 Maxime Lecoq
// Last update Sat Dec 31 13:14:03 2016 Lecoq Maxime
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
  /*  Clock         clo;
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
	      _shoots[i]->setX(_shoots[i]->getX() + 2);
	      if (_shoots[i]->getX() > 1920)
		{
		  delete _shoots[i];
		  _shoots.erase(_shoots.begin() + i);
		}
	      else
		i++;
	    }
	}
    }*/
}

void		Game::timeLine()
{
  Clock         clo;
  std::vector<std::string> list = getAllName();
  IPacket	*pa;
  _timeline = 0;

  while (_room->getPlayers().size() != 0)
    {
      if (_timeline != (uint64_t)clo.getTimeMilli() / 1000)
	{
	  _timeline = clo.getTimeMilli() / 1000;
	  pa = _factory->getPacket("players", _room->getPlayers());
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	  while (_shoots.empty() == false)
	    _shoots.erase(_shoots.begin());
	  uint64_t i;
	  uint64_t x;

	  i = 0;
	  while (i < _room->getPlayers().size())
	    {
	      x = 0;
	      while (x < _room->getPlayers()[i]->getShoots().size())
		{
		  _shoots.push_back(new DataShoot(_room->getPlayers()[i]->getShoots()[x]));
		  x++;
		}
	      i++;
	    }
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

uint64_t pppp = 0;

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
      if (pl->getName() == m && p->getShoots().size() != 0)
	{
	  uint64_t	pos = pl->getShoots().size();
	  uint64_t	x = 0;
	  std::cout << "lui qui envoie " << pl->getName() << " nb shoot packet " << p->getShoots().size() << " nb shoot stock : " << pl->getShoots().size() << " my id " << _timeline << " packet id " << pa->getTickId() << std::endl;
	  while (x < pl->getShoots().size())
	    {
	      delete pl->getShoots()[x];
	      x++;
	    }
	  pl->setShoots(p->getShoots());
	}
      /*if (pl->getName() == m && pl->getShoots().size() < p->getShoots().size() && p->getShoots().size() != 0)
	{
	
	  std::cout << "ppp" << std::endl;
	  while (x < p->getShoots().size())
	    {
	      pppp++;
	      std::cout << "ppp2 " << pppp << " " << pl->getName() << " " << m << " " << pl->getShoots().size() << std::endl;
	      if (x < pos)
		delete pl->getShoots()[x];
	      else
		{
		  DataShoot *d = new DataShoot;
		  d->setX(p->getShoots()[x]->getX());
		  d->setY(p->getShoots()[x]->getY());
		  d->setDamage(p->getShoots()[x]->getDamage());
		  std::cout << d->getX() << " " << d->getY() << " " << d->getDamage() << std::endl;
	
	  _shoots.push_back(d);
		}
	      x++;
	    }
	  pl->setShoots(p->getShoots());
	  }*/
      i++;
    }
}
