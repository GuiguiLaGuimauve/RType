//
// IError.hh for  in /home/lecoq_m/cpp_plazza
//
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
//
// Started on  Mon Apr 18 13:12:05 2016 Maxime LECOQ
// Last update Mon Dec 26 15:07:08 2016 La Guimauve
//

#ifndef		__IERROR_HH__
# define	__IERROR_HH__

namespace Error
{
  /*
  en :IError interface class define the AError class's methods
  fr :L'interface IError définit les méthodes de la classe AError. */
  /*!
    \class IError IError.hh
    \brief classe interface pour les erreurs
  */
  class		IError
  {
  public:
    /*
    en :what() allow the recuperation of error message
    fr :La méthode what() const throw() permet de récupérer le message d'érreur. */
    /**
    * \fn virtual const char what() const throw()
    * \brief Abstract pure pour retourner le message d'erreur
    *
    * \return une instance du message d'erreur
    */
    virtual const char		*what() const throw() = 0;
    /*
    en :quit() print the error message and exit the program
    fr :La méthode quit() const permet d'afficher le message d'érreur et de quitter le programme. */
    /**
    * \fn virtual void quit() const
    * \brief Abstract pure qui affiche le message d'erreur avant de quitter le programme
    */
    virtual void			quit() const = 0;
    /*
    en :error() print the message of the error
    fr :La méthode error() const permet d'afficher le message d'érreur. */
    /**
    * \fn virtual void error() const
    * \brief Abstract pure qui affiche le message d'erreur
    */
    virtual void			error() const = 0;
    /**
    * \fn virtual ~IError() throw()
    * \brief Destructeur virtuel de la classe
    */
    virtual ~IError() throw() {}
  };
}

using namespace Error;

#endif
