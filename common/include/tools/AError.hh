//
// AError.hh for  in /home/lecoq_m/cpp_plazza
//
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
//
// Started on  Mon Apr 18 13:13:17 2016 Maxime LECOQ
// Last update Wed Dec 21 13:27:19 2016 La Guimauve
//

#ifndef		__AERROR_HH__
# define	__AERROR_HH__

# include       <iostream>
# include       <cstdlib>
# include		"IError.hh"
# include		<string>

namespace Error {
  /*!
		\class AError AError.hh
		\brief classe abstraite qui implémente les methodes de IError
	*/
  class		AError : public IError, public std::exception
  {
  private:
    std::string	_err; /** \brief _err : contient le message d'erreur */
    std::string	_class;  /** \brief _class : contient le nom de la classe */
public:
  /**
  * \fn AError(const std::string &, const std::string &)
  * \brief Constructeur du de AError avec spécification du message et de la classe
  *
  * \param err message d'erreur
  * \param class nom de la classe
  */
    AError(const std::string &, const std::string &);
    /**
    * \fn AError(const std::string &)
    * \brief Constructeur du de AError avec spécification du message
    *
    * \param err message d'erreur
    */
    AError(const std::string &);
    /**
    * \fn AError(const AError &)
    * \brief Constructeur par copie
    *
    * \param err : classe AError à copier
    */
    AError(const AError &);
    /**
    * \fn AError &operator=(const AError &)
    * \brief Surcharge de l'opérateur = pour la copie d'erreur
    *
    * \param err : classe AError à copier
    *
    * \return : Instance de AError
    */
    AError			&operator=(const AError &);
    /**
    * \fn const char *what() const throw()
    * \brief Récupère le message d'erreur
    *
    * \return : Instance du message d'erreur
    */
    const char			*what() const throw();
    /**
    * \fn void what() const
    * \brief Affiche l'erreur et quitte le programme
    */
    void				quit() const;
    /**
    * \fn void error() const
    * \brief Affiche l'erreur
    */
    void				error() const;
    /**
    * \fn ~AError() throw()
    * \brief Destructeur de AError
    */
    virtual ~AError() throw() {};
  };
};

#endif
