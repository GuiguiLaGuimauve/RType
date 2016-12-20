//
// Vector.cpp for  in /home/lecoq_m/basics_cpp
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sun Apr 24 21:26:17 2016 Maxime LECOQ
// Last update Tue Dec 20 03:27:35 2016 lecoq
//

#include	"Vector.hh"

Vector::Vector() {}

Vector::~Vector() {}

Vector::Vector(const Vector &c) : _v(c._v), _d(c._d) {}

Vector		&Vector::operator=(const Vector &c)
{
  if (this != &c)
    {
      _v = c._v;
      _d = c._d;
    }
  return (*this);
}

std::vector<std::string>	Vector::getVector(const std::string &s, const char &c)
{
  return (_v.getVector(s, c));
}

std::vector<std::string>	Vector::getVector(const std::string &s, const char *c)
{
  return (_v.getVector(s, c));
}

std::vector<std::string>	Vector::getVector(const char *s, const char &c)
{
  return (_v.getVector(s, c));
}

std::vector<std::string>	Vector::getVector(const char *s, const char *c)
{
  return (_v.getVector(s, c));
}

std::string			Vector::getString(std::vector<std::string> &v, const char &c)
{
  return (_d.getString(v, c));
}

Vector::Vectorize::Vectorize() {}

Vector::Vectorize::Vectorize(const std::string &s, const char &c)
{
  std::string   tmp;
  size_t        found;

  tmp = s;
  while ((found = tmp.find(c)) < tmp.size())
    {
      _vec.push_back(tmp.substr(0, found));
      tmp = tmp.substr(found + 1, tmp.size());
    }
  if (tmp.empty() == false)
    _vec.push_back(tmp);
}

Vector::Vectorize::~Vectorize() {}

Vector::Vectorize::Vectorize(const Vector::Vectorize &cop) : _vec(cop._vec) {}

Vector::Vectorize &Vector::Vectorize::operator=(const Vector::Vectorize &cop)
{
  if (this != &cop)
    _vec = cop._vec;
  return (*this);
}

std::vector<std::string>        Vector::Vectorize::getVector() const
{
  return (_vec);
}

std::vector<std::string>        Vector::Vectorize::getVector(const std::string &s, const char &c)
{
  std::string                   tmp;
  size_t                        found;
  std::vector<std::string>      ret;

  tmp = s;
  while ((found = tmp.find(c)) < tmp.size())
    {
      if (tmp.substr(0, found).empty() == false) 
	ret.push_back(tmp.substr(0, found));
      tmp = tmp.substr(found + 1, tmp.size());
    }
  if (tmp.empty() == false)
    ret.push_back(tmp);
  return (ret);
}

std::vector<std::string>        Vector::Vectorize::getVector(const std::string &s, const char *c)
{
  std::string                   tmp;
  size_t                        found;
  std::vector<std::string>      ret;
  std::string			si(c);
  
  tmp = s;
  while ((found = tmp.find(c)) < tmp.size())
    {
      if (tmp.substr(0, found).empty() == false) 
	ret.push_back(tmp.substr(0, found));
      tmp = tmp.substr(found + si.size(), tmp.size());
    }
  if (tmp.empty() == false)
    ret.push_back(tmp);
  return (ret);
}

std::vector<std::string>        Vector::Vectorize::getVector(const char *s, const char &c)
{
  std::string                   tmp(s);
  size_t                        found;
  std::vector<std::string>      ret;

  while ((found = tmp.find(c)) < tmp.size())
    {
      if (tmp.substr(0, found).empty() == false) 
	ret.push_back(tmp.substr(0, found));
      tmp = tmp.substr(found + 1, tmp.size());
    }
  if (tmp.empty() == false)
    ret.push_back(tmp);
  return (ret);
}

std::vector<std::string>        Vector::Vectorize::getVector(const char *s, const char *c)
{
  std::string                   tmp(s);
  size_t                        found;
  std::vector<std::string>      ret;
  std::string			si(c);

  while ((found = tmp.find(c)) < tmp.size())
    {
      if (tmp.substr(0, found).empty() == false) 
	ret.push_back(tmp.substr(0, found));
      tmp = tmp.substr(found + si.size(), tmp.size());
    }
  if (tmp.empty() == false)
    ret.push_back(tmp);
  return (ret);
}

Vector::Devectorize::Devectorize() {}

Vector::Devectorize::Devectorize(const std::vector<std::string> &vec, const char &c)
{
  size_t        i;
  size_t        size;

  size = vec.size();
  i = 0;
  while (i < size)
    _str += vec[i++] + c;
  if (_str.empty() == true)
    _str += c;
}

Vector::Devectorize::~Devectorize() {}

Vector::Devectorize::Devectorize(const Vector::Devectorize &cop) : _str(cop._str) {}

Vector::Devectorize &Vector::Devectorize::operator=(const Vector::Devectorize &cop)
{
  if (this != &cop)
    _str = cop._str;
  return (*this);
}

const std::string       &Vector::Devectorize::getString() const
{
  return (_str);
}

std::string             Vector::Devectorize::getString(std::vector<std::string> &vec, const char &c)
{
  size_t        i;
  size_t        size;
  std::string   ret;

  size = vec.size();
  i = 0;
  while (i < size)
    {
      ret += vec[i++];
      if (i < size)
	ret += c;
    }
  return (ret);
}
