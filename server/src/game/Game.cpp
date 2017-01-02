//
// Game.cpp for Game in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 15:45:57 2016 Maxime Lecoq
// Last update Mon Jan  2 14:28:06 2017 Lecoq Maxime
//

#include	"Game.hh"

Game::Game(DataRoom *p) : _room(p), _timeline(0)
{
  _bossSet = false;
  _bossMod = false;
  _boss = NULL;
  _ptr[IPacket::PacketType::POSITION_PLAYER] = &IGame::updatePosPlayer;
  _ptr[IPacket::PacketType::SHOOTS_CLIENT] = &IGame::updatePlayerShoots;
  _ptr[IPacket::PacketType::PLAYERDATA] = &IGame::updatePlayer;

  _ennemyGenerator = new EnnemyGenerator;
  refreshEnnemy();

  DataBackground *d = new DataBackground;
  d->setX(0);
  d->setY(0);

  d->setSpeed(-2);
  _background.push_back(d);
  d = new DataBackground;
  d->setX(1920);
  d->setY(0);
  d->setSpeed(-2);
  _background.push_back(d); 
  _lvl = 1;
  _ptrM[1] = &Game::boss;
  _ptrM[2] = &Game::lvl1;
  _ptrM[3] = &Game::lvl2;
  _ptrM[4] = &Game::lvl2;
  _ptrM[5] = &Game::lvl3;
  _ptrM[6] = &Game::boss;
  _win = false;
}

Game::~Game()
{
  delete _ennemyGenerator;
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
  i = 0;
  while (i < _th.size())
    {
      if (_th[i]->joinable())
	_th[i]->join();
      i++;
    }
}

bool			Game::isWin() const { return (_win); }

bool			Game::isLoose() const
{
  uint64_t i = 0;

  while (i < _room->getPlayers().size())
    {
      if (_room->getPlayers()[i]->getHealth() > 0)
	return (false);
      i++;
    }
  return (true);
}

void			Game::refreshEnnemy()
{
  std::vector<DataEnnemy *>	en;
  uint64_t			i;
  uint64_t			x;
  bool				find;
  
  i = 0;
  en = _ennemyGenerator->loadAllEnnemy();
  while (i < en.size())
    {
      x = 0;
      find = false;
      while (x < _ennemyList.size())
	{
	  if (_ennemyList[x]->getSpriteName() == en[i]->getSpriteName() && en[i]->isBoss() == false)
	    find = true;
	  else
	    if (en[i]->isBoss() == true && _bossSet == false)
	      {
		_bossSet = true;
		_boss = en[i]->getNewEnnemy();
	      }
	  x++;
	}
      if (find == false && en[i]->isBoss() == false)
	_ennemyList.push_back(en[i]);
      i++;
    }
}

std::vector<std::string> Game::getAllName() const
{
  uint64_t	i;
  std::vector<std::string> ret;
  DataPlayer *pl;
  
  i = 0;
  while (i < _room->getPlayers().size() && (pl = _room->getPlayers()[i]) != NULL)
    {
      ret.push_back(pl->getName());
      i++;
    }
  i = 0;
  while (i < _room->getWatchers().size() && (pl = _room->getWatchers()[i]) != NULL)
    {
      ret.push_back(pl->getName());
      i++;
    }
  return (ret);
}

std::vector<std::string> Game::getViewersName() const
{
  uint64_t	i;
  std::vector<std::string> ret;
  DataPlayer		*pl;
  
  i = 0;
  while (i < _room->getWatchers().size() && (pl = _room->getWatchers()[i]) != NULL)
    {
      ret.push_back(pl->getName());
      i++;
    }
  return (ret);
}

std::vector<std::string> Game::getPlayersName() const
{
  uint64_t	i;
  std::vector<std::string> ret;
  DataPlayer	*pl;
  
  i = 0;
  while (i < _room->getPlayers().size() && (pl = _room->getPlayers()[i]) != NULL)
    {
      ret.push_back(pl->getName());
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

void		Game::checkShootCollisions()
{
  uint64_t	i;
  uint64_t	x;

  i = 0;
  while (i < _shoots.size())
    {
      x = 0;
      while (x < _shootsEn.size() && _shoots[i]->getHealth() > 0)
	{
	  if (_shoots[i]->collisionWith(_shootsEn[x]) == true)
	    {
	      _shoots[i]->setHealth(_shoots[i]->getHealth() - _shootsEn[x]->getDamage());
	      _shootsEn[x]->setHealth(_shootsEn[x]->getHealth() - _shoots[i]->getDamage());
	    }
	  if (_shootsEn[x]->getHealth() <= 0)
	    _shootsEn.erase(_shootsEn.begin() + x);
	  else
	    x++;
	}
      x = 0;
      while (x < _ennemy.size() && _shoots[i]->getHealth() > 0)
	{
	  if (_shoots[i]->collisionWith(_ennemy[x]) == true)
	    {
	      _shoots[i]->setHealth(_shoots[i]->getHealth() - 100);
	      _ennemy[x]->setHealth(_ennemy[x]->getHealth() - _shoots[i]->getDamage());
	    }
	  if (_ennemy[x]->getHealth() <= 0)
	    {
	      if (_ennemy[x]->isBoss() == true)
		_win = true;
	      _ennemy.erase(_ennemy.begin() + x);
	    }
	  else
	    x++;
	}
      x = 2;
      while (x < _background.size() && _shoots[i]->getHealth() > 0)
	{
	  if (_shoots[i]->collisionWith(_background[x]) == true)
	    _shoots[i]->setHealth(_shoots[i]->getHealth() - 100);
	  x++;
	}
      if (_shoots[i]->getHealth() <= 0)
	_shoots.erase(_shoots.begin() + i);
      else
	i++;
    }
  i = 0;
  while (i < _shootsEn.size())
    {
      x = 2;
      while (x < _background.size() && _shootsEn[i]->getHealth() > 0)
	{
	  if (_shootsEn[i]->collisionWith(_background[x]) == true)
	    _shootsEn[i]->setHealth(_shootsEn[i]->getHealth() - 100);
	  x++;
	}
      x = 0;
      while (x < _room->getPlayers().size() && _shootsEn[i]->getHealth() > 0)
	{
	  if (_shootsEn[i]->collisionWith(_room->getPlayers()[x]) == true)
	    {
	      _shootsEn[i]->setHealth(_shootsEn[i]->getHealth() - 100);
	      _room->getPlayers()[x]->setHealth(_room->getPlayers()[x]->getHealth() - _shootsEn[i]->getDamage());
	    }
	  if (_room->getPlayers()[x]->getHealth() <= 0)
	    _room->getPlayers()[x]->setHealth(0);
	  x++;
	}
      if (_shootsEn[i]->getHealth() <= 0)
	_shootsEn.erase(_shootsEn.begin() + i);
      else
	i++;
    }
}

void		Game::movements()
{
  Clock         clo;
  uint64_t	i;
  uint64_t	x;
  uint64_t	m;
  uint64_t	z;

  m = 0;
  x = 0;
  z = 0;
  while (_room->getStarted() == true && _room->getPlayers().size() != 0 && _win == false)
    {
      if (x != (uint64_t)clo.getTimeMilli() / 2)
	{
	  x = clo.getTimeMilli() / 2;
	  i = 0;
	  while (i < _shoots.size())
	    {
	      _shoots[i]->move();
	      if (_shoots[i]->getX() > 1920 || _shoots[i]->getX() < 0
		  || _shoots[i]->getY() < 0 || _shoots[i]->getY() > 1080)
		_shoots.erase(_shoots.begin() + i);
	      else
		i++;
	    }
	  i = 0;
	  while (i < _shootsEn.size())
	    {
	      _shootsEn[i]->move();
	      if (_shootsEn[i]->getX() > 1920 || _shootsEn[i]->getX() + _shootsEn[i]->getSizeX() < 0
		  || _shootsEn[i]->getY() + _shootsEn[i]->getSizeY() < 0 || _shootsEn[i]->getY() > 1080)
		_shootsEn.erase(_shootsEn.begin() + i);
	      else
		i++;
	    }
	  checkShootCollisions();
	}
      if (m != (uint64_t)clo.getTimeMilli() / 50)
	{
	  m = clo.getTimeMilli() / 50;
	  i = 0;
	  while (i < _ennemy.size())
	    {
	      _ennemy[i]->move();
	      if (_ennemy[i]->getX() > 1920 || _ennemy[i]->getX() + _ennemy[i]->getSizeX() < 0
		  || _ennemy[i]->getY()  + _ennemy[i]->getSizeY() < 100 || _ennemy[i]->getY() > 1080)
		_ennemy.erase(_ennemy.begin() + i);
	      else
		i++;
	    }
	}
      if (z != (uint64_t)clo.getTimeMilli() / 100)
	{
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
		  if (_background[i]->getX() > 1920 || _background[i]->getX() + _background[i]->getSizeX() < 0
		      || _background[i]->getY() + _background[i]->getSizeY() < 100 || _background[i]->getY() > 1080)
		    _background.erase(_background.begin() + i);
		  else
		    i++;
		}
	    }
	}
    }
}

void		Game::timeLine()
{
  Clock         clo;
  IPacket	*pa;
  uint64_t	ckLvl;
  
  _timeline = 0;
  ckLvl = 0;
  while (_room->getStarted() == true && _room->getPlayers().size() != 0 && _win == false)
    {
      if (ckLvl != (uint64_t)clo.getTimeMilli() / 50000)
	{
	  ckLvl = clo.getTimeMilli() / 50000;
	  _lvl++;
	  if (_lvl < 7)
	    _room->setLevel(_lvl);
	  refreshEnnemy();
	}
      if (_timeline != (uint64_t)clo.getTimeMilli() / 15)
	{
	  std::vector<std::string> list = getAllName();
	  _timeline = clo.getTimeMilli() / 15;
	  std::vector<DataShoot *> shoot;
	  for (uint64_t i = 0; i < _shoots.size(); i++)
	    shoot.push_back(_shoots[i]);
	  for (uint64_t i = 0; i < _shootsEn.size(); i++)
	    shoot.push_back(_shootsEn[i]);
	  pa = _factory->getPacket("gamedata", _room->getPlayers(), shoot, _ennemy, _background, _lvl);
	  pa->setTickId(_timeline);
	  _udp->pushTo(list, pa->getPacketUnknown());
	  delete pa;
	}
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void		Game::lvl1()
{
  uint64_t i = 0;
  if (_ennemyList.size() != 0)
    {
      DataEnnemy	*en;
      while (i < _room->getPlayers().size())
	{
	  en = _ennemyList[std::rand() % _ennemyList.size()]->getNewEnnemy();
	  en->setX(1920);
	  en->setY((std::rand() % 900) + 100);
	  _ennemy.push_back(en);
	  i++;
	}
    }
}

void		Game::lvl2()
{
  if (_ennemyList.size() != 0)
    {
      uint64_t i = 0;
      DataEnnemy	*en;
      bool		go = true;
      while (i < _room->getPlayers().size())
	{
	  en = _ennemyList[std::rand() % _ennemyList.size()]->getNewEnnemy();
	  en->setX(1920);
	  en->setY((std::rand() % 900) + 100);
	  _ennemy.push_back(en);
	  if (go == true)
	    {
	      go = false;
	      en = _ennemyList[std::rand() % _ennemyList.size()]->getNewEnnemy();
	      en->setX(1920);
	      en->setY((std::rand() % 900) + 100);
	      _ennemy.push_back(en);
	    }
	  else
	    go = true;
	  i++;
	}
    }
}

void		Game::lvl3()
{
  if (_ennemyList.size() != 0)
    {
      uint64_t i = 0;
      DataEnnemy	*en;

      while (i < _room->getPlayers().size() * 2)
	{
	  en = _ennemyList[std::rand() % _ennemyList.size()]->getNewEnnemy();
	  en->setX(1920);
	  en->setY((std::rand() % 900) + 100);
	  _ennemy.push_back(en);
	  i++;
	}

    }
}

void		Game::boss()
{
  lvl1();
  if (_bossSet == true && _bossMod == false && _boss)
    {
      _boss->setX(1920);
      _boss->setY(200);
      _ennemy.push_back(_boss);
      _bossMod = true;	
    }
}

void		Game::monster()
{
  Clock         clo;
  IPacket	*pa;
  uint64_t	i;
  uint64_t	shoot;
  
  (void)pa;
  i = 0;
  shoot = 0;
  while (_room->getStarted() == true && _room->getPlayers().size() != 0 && _win == false)
    {
      if (i != (uint64_t)clo.getTimeMilli() / 7000)
	{
	  std::srand(std::time(NULL));
	  i = clo.getTimeMilli() / 7000;
	  if (_ptrM.find(_lvl) != _ptrM.end())
	    (this->*_ptrM[_lvl])();
	}
      if (shoot != (uint64_t)clo.getTimeMilli() / 1000)
	{
	  uint64_t x;
	  shoot = clo.getTimeMilli() / 1000;
	  x = 0;
	  while (x < _ennemy.size())
	    {
	      std::vector<DataShoot *>d = _ennemy[x]->getShoot();
	      uint64_t z = 0;
	      while (z < d.size())
		{
		  _shootsEn.push_back(d[z]);
		  z++;
		}
	      //d->setX(_ennemy[x]->getX());
	      //d->setY(_ennemy[x]->getY() + (d->getSizeY() / 2));
	      //	      _shootsEn.push_back(d);
	      x++;
	    }
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void		Game::background()
{
  Clock         clo;
  IPacket	*pa;
  uint64_t	i;

  i = 0;
  (void)pa;
  while (_room->getStarted() == true && _room->getPlayers().size() != 0 && _lvl < 7 && _win == false)
    {
      if (i != (uint64_t)clo.getTimeMilli() / 30000)
	{
	  i = clo.getTimeMilli() / 30000;
	  DataBackground *d = new DataBackground;
	  d->setX(1920);
	  uint16_t y = (std::rand() % 800) + 100;
	  d->setY(y);
	  d->setSpeed(-2);
	  if (y % 2== 0)
	    d->setSpriteName("Env-1");
	  else
	    d->setSpriteName("Env-2");
	  _background.push_back(d);
	}
      std::this_thread::sleep_for(std::chrono::milliseconds(10000));
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
  DataPlayer	*packetFrom = _room->getPlayer(m);
  
  if (_ptr.find(pa->getType()) != _ptr.end()
      && packetFrom != NULL && packetFrom->getTick() < pa->getTickId())
    {
      packetFrom->setTick(pa->getTickId());
      (this->*_ptr[pa->getType()])(pa, m);
    }
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
		  DataShoot *d = new ShootPlayer;
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

void		Game::updatePlayer(const IPacket *pa, const std::string &m)
{
  PacketPlayerData *p = (PacketPlayerData *)pa;
  IPacket	*pa1 = new PacketPositionPlayer(p->getX(), p->getY());
  IPacket	*pa2 = new PacketShootsClient(p->getShoots());

  updatePosPlayer(pa1, m);
  updatePlayerShoots(pa2, m);
  delete pa1;
  delete pa2;
}

void		Game::addThread(mythrd::Thread *t)
{
  _th.push_back(t);
}
