//
// Convert.hh for  in /home/lecoq_m/basics_cpp
// 
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
// 
// Started on  Sun Apr 24 19:04:44 2016 Maxime LECOQ
// Last update Fri Oct 28 16:43:27 2016 lecoq
//

#ifndef		__CONVERT_HPP__
# define	__CONVERT_HPP__

# include	<fstream>
# include	<sstream>
# include	<stdint.h>

namespace Tools {
  template<typename T>
  /* La classe Convert permet de convertir n'importe qu'elle sorte de nombre en chaîne de caractère et inversement. */
  class		Convert
  {
  public:
    Convert() {}
    ~Convert() {}
  private:
    Convert(const Convert &cop) { (void)cop; }
    Convert &operator=(const Convert &cop) { (void)cop; return (*this); }
  public:
    /* La méthode toString(const T &) permet de transformer un nombre en string. */
    std::string		toString(const T &nb)
    {
      std::ostringstream s;
      s << nb;
      return (s.str());
    }
    /* La méthode toNumber(const std::string &) permet de transformer une string en nombre. */
    T			toNumber(const std::string &s)
    {
      T			i;
      
      std::istringstream (s) >> i;
      return (i);
    }
    /* La méthode toNumber(const std::string &) permet de transformer une string en nombre. */
    T			toNumber(const char *s)
    {
      std::string		tmp(s);
      T			i;
      
      std::istringstream (tmp) >> i;
      return (i);
    }
  };
};

using namespace Tools;

#endif
