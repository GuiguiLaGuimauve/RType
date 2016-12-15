//
// AError.cpp for  in /home/lecoq_m/cpp_plazza
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Mon Apr 18 13:17:17 2016 Maxime LECOQ
// Last update Fri Apr 22 17:07:52 2016 Maxime LECOQ
//

#include	"AError.hh"

AError::AError(const std::string &err, const std::string &cl) : _err(err), _class(cl) {}

AError::AError(const std::string &err) : _err(err) {}

AError::AError(const AError &cop) : _err(cop._err), _class(cop._class) {}

AError			&AError::operator=(const AError &cop)
{
  if (this != &cop)
    {
      _err = cop._err;
      _class = cop._class;
    }
  return (*this);
}

const char              *AError::what() const throw()
{
  return (this->_err.c_str());
}

void                    AError::quit() const
{
  if (_class.empty() == false)
    std::cerr << _class << " : " << this->what() << std::endl;
  else
    std::cerr << this->what() << std::endl;
  exit(0);
}

void			AError::error() const
{
  if (_class.empty() == false)
    std::cerr << _class << " : " << this->what() << std::endl;
  else
    std::cerr << this->what() << std::endl;
}
