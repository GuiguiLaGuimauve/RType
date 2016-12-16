#include	"AManageNetwork.hh"

using namespace Network;

AManageNetwork::AManageNetwork() {
  _port = 4242;
  _init = false;
}

uint32_t			AManageNetwork::getMaxFd() const
{
  if (_user.size() != 0)
    {
      uint32_t			i;
      int32_t			res;

      i = 0;
      while (i < _user.size() && _user[i]->getStatus() == false)
	i++;
      res = _user[i]->getFd();
      while (i < _user.size())
	{
	  if (_user[i]->getStatus() == true)
	    if (res < _user[i]->getFd())
	      res = _user[i]->getFd();
	  i++;
	}
      return (res + 1);
    }
  else
    return (0);
}

ISocket		*AManageNetwork::getSocket() const
{
  return (_net);
}

void			AManageNetwork::updateUsers(std::vector<IUserNetwork *> user)
{
  uint32_t	i = 0;
  while (i < _user.size())
    {
      if (_user[i]->getStatus() == false)
	{
	  std::cout << "Erase client from list: " << _user[i]->getFd() << std::endl;
	  delete (_user[i]);
	  _user.erase(_user.begin() + i);
	}
      else
	i++;
    }
  i = 0;
  while (i < user.size())
    {
      if (user[i]->getStatus() == true)
	{
	  std::cout << "New user in list: " << user[i]->getFd() << std::endl;
	  _user.push_back(user[i]);
	}
      i++;
    }
}

