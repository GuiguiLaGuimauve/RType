//
// ServerConf.cpp for ServerConf in /home/lecoq_m/Rtype
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Tue Dec 20 02:35:23 2016 Maxime Lecoq
// Last update Tue Dec 20 03:29:47 2016 lecoq
//

#include	"ServerConf.hh"

ServerConf::ServerConf()
{
  File f(".conf");

  try
    {
      std::string		content = f.read();
      std::vector<std::string>	tab;
      Vector			vec;
      Convert<uint16_t>		conv;
      
      tab = vec.getVector(content, "\n");
      uint64_t			i = 0;
      while (i < tab.size())
	{
	  std::vector<std::string> tmp;
	  const char *delim = "[|||]";
	  
	  tmp = vec.getVector(tab[i], delim);
	  if (tmp.size() == 4 && notInList(tmp[0]) == true)
	    {
	      DataPlayer *d = new DataPlayer;
	      d->setName(tmp[0]);
	      d->setPassword(tmp[1]);
	      d->setStageSucceed(conv.toNumber(tmp[2]));
	      d->setGamePlayed(conv.toNumber(tmp[3]));
	      _player.push_back(d);
	    }
	  i++;
	}
    }
  catch (AError const &e)
    {
    }
}

ServerConf::~ServerConf()
{
  uint64_t      i;

  i = 0;
  while (i < _player.size())
    delete _player[i++];
}

bool		ServerConf::notInList(const std::string &name)
{
  uint64_t	i;

  i = 0;
  while (i < _player.size())
    {
      if (_player[i]->getName() == name)
	return (true);
      i++;
    }
  return (false);
}

bool		ServerConf::findSomething() const
{
  if (_player.size() != 0)
    return (true);
  else
    return (false);
}

void		ServerConf::reset()
{
  while (_player.empty() == false)
    _player.erase(_player.begin());
}

std::vector<DataPlayer *>	ServerConf::getPlayers() const
{
  return (_player);
}

void				ServerConf::write(const std::vector<DataPlayer *> &pl)
{
  std::string		header;
  std::string		msg;
  File			fi(".conf");
  uint64_t		i;
  Convert<uint16_t>	conv;
  
  header = "Configuration file of rembur_g group's\n";
  i = 0;
  while (i < pl.size())
    {
      msg += pl[i]->getName() + "[|||]" + pl[i]->getPassword() + "[|||]" + conv.toString(pl[i]->getStageSucceed()) + "[|||]" + conv.toString(pl[i]->getGamePlayed()) + "\n";
      i++;
    }
  try
    {
      fi.writeTronc(header + msg);
    }
  catch (AError const &e)
    {
    }
}
