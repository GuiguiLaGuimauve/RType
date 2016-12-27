//
// C:\Users\Guimauve\Documents\RType\common\include\tools\RunTimeError.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 20 10:49:41 2016 La Guimauve
// Last update Tue Dec 27 10:06:26 2016 La Guimauve
//

#ifndef _RUNTIMERROR_HH_
# define _RUNTIMERROR_HH_

#include "AError.hh"

namespace Error
{
  /*!
    \class RunTimeError RunTimeError.hh
    \brief Classe d'erreurs lorsqu'une erreur d'execution arrive dans le programme
  */
  class RunTimeError : public AError
  {
  public:
    /**
    * \fn RunTimeError(std::string const &, std::string const &)
    * \brief Constructeur de la classe RunTimeError avec spécification du message d'erreur et de la fonction
    *
    * \param err : Message d'erreur
    * \param fct : Nom de la fonction
    */
    RunTimeError(const std::string &, const std::string &);
    /**
    * \fn RunTimeError(std::string const &)
    * \brief Constructeur de la classe RunTimeError avec spécification du message d'erreur
    *
    * \param err : Message d'erreur
    */
    RunTimeError(const std::string &);
    /**
    * \fn RunTimeError(std::string const &, std::string const &)
    * \brief Constructeur par copie
    *
    * \param err : erreur à copier
    */
    RunTimeError(const AError &);
    /**
    * \fn ~RunTimeError()
    * \brief Destructeur de la classe RunTimeError
    */
    ~RunTimeError() throw() {};
  };
};
#endif //_RUNTIMERROR_HH_
