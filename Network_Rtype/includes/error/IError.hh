//
// IError.hh for  in /home/lecoq_m/cpp_plazza
//
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
//
// Started on  Mon Apr 18 13:12:05 2016 Maxime LECOQ
// Last update Sun Nov 13 21:25:04 2016 La Guimauve
//

#ifndef		__IERROR_HH__
# define	__IERROR_HH__

namespace Error
{
  /*
  en :IError interface class define the AError class's methods
  fr :L'interface IError définit les méthodes de la classe AError. */
  class		IError
  {
  public:
    /*
    en :what() allow the recuperation of error message
    fr :La méthode what() const throw() permet de récupérer le message d'érreur. */
    virtual const char		*what() const throw() = 0;
    /*
    en :quit() print the error message and exit the program
    fr :La méthode quit() const permet d'afficher le message d'érreur et de quitter le programme. */
    virtual void			quit() const = 0;
    /*
    en :error() print the message of the error
    fr :La méthode error() const permet d'afficher le message d'érreur. */
    virtual void			error() const = 0;
    virtual ~IError() throw() {}
  };
}

using namespace Error;

#endif
