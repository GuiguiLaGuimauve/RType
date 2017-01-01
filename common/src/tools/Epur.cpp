//
// Epur.cpp for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sat Apr 23 19:15:58 2016 Maxime Lecoq
// Last update Thu Nov 17 18:26:57 2016 lecoq
//

#include	"Epur.hh"

Epur::Epur(const std::string &str, const char &k)
{
  std::string	ep;
  std::string	tmp;
  size_t	found;

  ep += k + k;
  _str = str;
  while ((found = _str.find(ep)) < _str.size())
    {
      tmp = _str.substr(found + 1, _str.size());
      _str = _str.substr(0, found) + tmp;
    }
  while (_str[_str.size() - 1] == k)
    _str = _str.substr(0, _str.size() - 1);
  while (_str[0] == k)
    _str = _str.substr(1, _str.size());
}

Epur::Epur(const std::string &str) : _str(str)
{
  unsigned int	found;
  std::string	tmp;

  while ((found = _str.find("  ")) < _str.size())
    {
      tmp = _str.substr(found + 1, _str.size());
      _str = _str.substr(0, found) + tmp;
    }
  while (_str[_str.size() - 1] == ' ')
    _str = _str.substr(0, _str.size() - 1);
  while (_str[0] == ' ')
    _str = _str.substr(1, _str.size());
}

Epur::~Epur() {}

Epur::Epur(const Epur &cop) : _str(cop._str) {}

Epur		&Epur::operator=(const Epur &cop)
{
  if (this != &cop)
    {
      _str = cop._str;
    }
  return (*this);
}

const std::string &Epur::getString() const
{
  return (_str);
}

std::string		Epur::epur(const std::string &s, const char &k)
{
  std::string	ep;
  std::string	tmp;
  size_t	found;

  ep += k;
  ep += k;
  _str = s;
  while ((found = _str.find(ep)) < _str.size())
    {
      tmp = _str.substr(found + 1, _str.size());
      _str = _str.substr(0, found) + tmp;
    }
  while (_str[_str.size() - 1] == k)
    _str = _str.substr(0, _str.size() - 1);
  while (_str[0] == k)
    _str = _str.substr(1, _str.size());
  return (_str);
}

std::string		Epur::replace(const std::string &s, const char &src, const char &dest)
{
  std::string		ret;
  size_t		i;

  i = 0;
  while (i < s.size())
    {
      if (s[i] == src)
	ret += dest;
      else
	ret += s[i];
      i++;
    }
  return (ret);
}
