//
// AManageNetwork.cpp for AManageNetwork.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Wed Dec 21 01:24:37 2016 julien dufrene
// Last update Fri Dec 30 13:12:00 2016 lecoq
//

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
      if (i < _user.size() && _user[i]->getStatus() != false)
	res = _user[i]->getFd();
      else
	return (0);
      while (i < _user.size())
	{
	  if (_user[i]->getStatus() == true)
	    if (res < _user[i]->getFd())
	      res = _user[i]->getFd();
	  i++;
	}
      return (res + 1);
    }
  return (0);
}

ISocket		*AManageNetwork::getSocket() const
{
  return (_net);
}

bool		AManageNetwork::inList(const std::string &n, const std::vector<std::string> &li)
{
  uint64_t		i;
  StringCk		st;
  
  i = 0;
  if (n.empty() == true)
    return (false);
  while (i < li.size())
    {
      if (st.lower(n) == st.lower(li[i]))
	return (true);
      i++;
    }
  return (false);
}
