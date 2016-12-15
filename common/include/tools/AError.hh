//
// AError.hh for  in /home/lecoq_m/cpp_plazza
//
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
//
// Started on  Mon Apr 18 13:13:17 2016 Maxime LECOQ
// Last update Sun Nov 13 21:21:12 2016 La Guimauve
//

#ifndef		__AERROR_HH__
# define	__AERROR_HH__

# include       <iostream>
# include       <cstdlib>
# include		"IError.hh"
# include		<string>

namespace Error {
  /*
  en :AError abstract class implement IError class methods
  fr :L'abstraction AError implémente les méthodes de IError. */
  class		AError : public IError, public std::exception
  {
  private:
    /*
    en :_err contains the error message
    fr :_err est un attribut contenant le message d'érreur. */
    std::string	_err;
    /*
    en :_class contains the name of the class
    fr :_class est un attribut contenant le nom de la classe. */
    std::string	_class;
public:
    AError(const std::string &, const std::string &);
    AError(const std::string &);
    AError(const AError &);
    AError			&operator=(const AError &);
    const char			*what() const throw();
    void				quit() const;
    void				error() const;
    virtual ~AError() throw() {};
  };
};

#endif
