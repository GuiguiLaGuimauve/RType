//
// Convert.hh for  in /home/lecoq_m/basics_cpp
//
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
//
// Started on  Sun Apr 24 19:04:44 2016 Maxime LECOQ
// Last update Wed Dec 21 13:44:28 2016 La Guimauve
//

#ifndef		__CONVERT_HPP__
# define	__CONVERT_HPP__

# include	<fstream>
# include	<sstream>
# include	<stdint.h>

namespace Tools {
  /*!
    \class Convert Convert.hh
    \brief Permet de convertir n'importe qu'elle sorte de nombre en chaîne de caractère et inversement.
  */
  template<typename T>
  class		Convert
  {
  public:
    /**
    * \fn Convert()
    * \brief Constructeur par defaut
    */
    Convert() {}
    /**
    * \fn ~Convert()
    * \brief Destructeur par defaut
    */
    ~Convert() {}
  private:
    /**
    * \fn Convert(const Convert &)
    * \brief Constructeur copie
    *
    * \param[in] cop objet à copier
    */
    Convert(const Convert &cop) { (void)cop; }
    /**
    * \fn Convert &operator=(const Convert &)
    * \brief Surcharge de l'opérateur = pour copie
    *
    * \param[in] cop objet à copier
    *
    * \return instance de Convert
    */
    Convert &operator=(const Convert &cop) { (void)cop; return (*this); }
  public:
    /**
    * \fn std::string toString(const T &)
    * \brief Convertie la nombre en paramètre en std::string
    *
    * \param[in] nb
    *
    * \return instance du nombre convertie en std::string
    */
    std::string		toString(const T &nb)
    {
      std::ostringstream s;
      s << nb;
      return (s.str());
    }
    /**
    * \fn T toNumber(const std::string &)
    * \brief Convertie une std::string en paramètre en un nombre
    *
    * \param[in] s chaine de caractère à convertir
    *
    * \return instance de la std::string convertie en un nombre
    */
    T			toNumber(const std::string &s)
    {
      T			i;

      std::istringstream (s) >> i;
      return (i);
    }
    /* La méthode toNumber(const std::string &) permet de transformer une string en nombre. */
    /**
    * \fn std::string toString(const char *)
    * \brief Convertie un char * en paramètre en un nombre
    *
    * \param[in] s chaine de caractère à convertir
    *
    * \return instance de la chaine de caractère convertie en un nombre
    */
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
