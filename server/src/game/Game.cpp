//
// Game.cpp for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:45:57 2016 Maxime Lecoq
// Last update Sun Jan  1 14:56:31 2017 Lecoq Maxime
//

#include	"Game.hh"

Game::Game(DataRoom *p) : _room(p), _timeline(0)
{
  _ptr[IPacket::PacketType::POSITION_PLAYER] = &IGame::updatePosPlayer;
  _ptr[IPacket::PacketType::SHOOTS_CLIENT] = &IGame::updatePlayerShoots;

  //_ennemyGenerator = new EnnemyGenerator;
  //_ennemyList = _ennemyGenerator->loadAllEnnemy();

  DataBackground *d = new DataBackground;
  d->setX(0);
  d->setY(0);

  d->setSpeed(-1);
  _background.push_back(d);
  d = new DataBackground;
  d->setX(1920);
  d->setY(0);
  d->setSpeed(-1);
  _background.push_back(d); 
  /*  d = new DataBackground(195, 100);
  d->setSpeed(-1);
  _background.push_back(d);
  d = new DataBackground(56, 700);
  d->setSpeed(-1);
  _background.push_back(d);
*/
  /*  DataEnnemy *e = new DataEnnemy;
  e->setX(400);
  e->setY(200);
  e->setSpriteName(_ennemyList[0]->getSpriteName());
  _ennemy.push_back(e);
  
  e = new DataEnnemy;  
  e->setX(1000);
  e->setY(400);
   e->setName(_ennemyList[0]->getName());
  _ennemy.push_back(e);*/
}

Game::~Game()
{
  //  delete _ennemyGenerator;
  uint64_t i;

  i = 0;
  while (i < _background.size())
    {
      delete _background[i];
      i++;
    }
  i = 0;
  while (i < _ennemyList.size())
    {
      delete _ennemyList[i];
      i++;
    }
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
  uint64_t	z;
  IPacket	*pa;
  x = 0;
  z = 0;
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
      if (z != (uint64_t)clo.getTimeMilli() / 100)
	{
	  std::vector<std::string> list = getAllName();
	  z = clo.getTimeMilli() / 100;
	  i = 0;
	  while (i < _background.size())
	    {
	      _background[i]->setX(_background[i]->getX() + _background[i]->getSpeed());
	      if (i < 2)
		{
		  if (_background[i]->getX() <  -1920)
		    _background[i]->setX(_background[i]->getX() + (2 * 1920));
		  i++;
		}
	      else
		{
		  if (_background[i]->getX() > 1920 || _background[i]->getX() < 0)
		    {
		      delete _background[i];
		      _background.erase(_background.begin());
		    }
		  else
		    i++;
		}
	    }
	  pa = _factory->getPacket("background", _background);
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	}
    }
}

#include <thread>
void		Game::timeLine()
{
  Clock         clo;
  IPacket	*pa;
  _timeline = 0;
  while (_room->getPlayers().size() != 0)
    {
      if (_timeline != (uint64_t)clo.getTimeMilli() / 50)
	{	  
	  std::vector<std::string> list = getAllName();
	  _timeline = clo.getTimeMilli() / 50;
	  pa = _factory->getPacket("players", _room->getPlayers());
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	  pa = _factory->getPacket("shoots", _shoots);
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	  pa = _factory->getPacket("ennemies", _ennemy);
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	}
      std::this_thread::sleep_for(std::chrono::milliseconds(25));
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

void Game::updatePlayerShoots(const IPacket *pa, const std::string &m)
{
  uint64_t	i;
  PacketShoots *p = (PacketShoots *)pa;
  std::vector<DataShoot *>	tmp;
  DataPlayer			*pl;
  i = 0;

  std::vector<DataShoot *> tmpD;
  while (i < _room->getPlayers().size())
    {
      pl = _room->getPlayers()[i];
      tmpD = pl->getShoots();
      if (pl->getName() == m && pl->getShoots().size() < p->getShoots().size() && p->getShoots().size() != 0)
	{
	  
	  uint64_t	x = 0;
	  uint64_t	pos = pl->getShoots().size();
	  while (x < p->getShoots().size())
	    {
	      if (x >= pos)
		//		delete pl->getShoots()[x];
		//else
		{
		  DataShoot *d = new DataShoot;
		    d->setX(p->getShoots()[x]->getX());
		    d->setY(p->getShoots()[x]->getY());
		    d->setDamage(p->getShoots()[x]->getDamage());
		    _shoots.push_back(d);
		    tmpD.push_back(p->getShoots()[x]);
		}
	      x++;
	    }
	}
      pl->setShoots(tmpD);
      i++;
    }
}

