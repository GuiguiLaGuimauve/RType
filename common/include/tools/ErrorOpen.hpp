//
// ErrorRead.hh for  in /home/lecoq_m/cpp_arcade
//
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
//
// Started on  Fri Mar 18 09:35:48 2016 Maxime Lecoq
// Last update Mon Dec 26 14:55:59 2016 La Guimauve
//

#ifndef		__ERROROPEN_HH__
# define	__ERROROPEN_HH__

# include	"AError.hh"

/*!
  \class ErrorOpen ErrorOpen.hh
  \brief Classe d'erreurs lors d'une erreur sur l'ouvertur d'un fichier
*/
class ErrorOpen : public AError
{
public:
  /**
  * \fn ErrorOpen(std::string const &)
  * \brief Constructeur de la classe ErrorOpen
  *
  * \param err : Message d'erreur
  */
  ErrorOpen(std::string const & err) : AError(err, "ErrorOpen") {};
  /**
  * \fn ~ErrorOpen()
  * \brief Destructeur de la classe ErrorOpen
  */
  virtual ~ErrorOpen() throw() {}
};

#endif		/*__ERROR_HH__ */
