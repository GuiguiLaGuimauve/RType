//
// Epur.hh for  in /home/lecoq_m/cpp_plazza
//
// Made by Maxime Lecoq
// Login   <lecoq_m@epitech.net>
//
// Started on  Sat Apr 23 19:13:31 2016 Maxime Lecoq
// Last update Mon Dec 26 14:51:24 2016 La Guimauve
//

#ifndef		__EPUR_HH__
# define	__EPUR_HH__

# include	<iostream>
# include	<string>

/*!
  \class Epur Epur.hh
  \brief classe epurer une chaine de caractères
*/
class		Epur
{
private:
  std::string	_str; /* \brief _str : chaine de caractères à epurer */
public:
  /**
  * \fn Epur()
  * \brief Constructeur de la classe Epur
  */
  Epur() {};
  /**
  * \fn Epur(const std::string &)
  * \brief Constructeur de la classe Epur avec spécification de la chaine de caractères
  *
  * \param str chaine de caractère à épurer
  */
  Epur(const std::string &);
  /**
  * \fn Epur(const std::string &, const char &)
  * \brief Constructeur de la classe Epur avec spécification de la chaine de caractères, et du caractère à epurer
  *
  * \param str chaine de caractère à épurer
  * \param c caractère à épurer
  */
  Epur(const std::string &, const char &);
  /**
  * \fn ~Epur()
  * \brief Destructeur de la classe Epur
  */
  ~Epur();
  /**
  * \fn Epur(const std::string &, const char &)
  * \brief Constructeur par copier de la classe Epur
  *
  * \param e Objet à copier
  */
  Epur(const Epur &);
  /**
  * \fn Epur &operator=(const Epur &)
  * \brief Surcharge de l'opérateur = pour la copie d'objet
  *
  * \param e Objet à copier
  * \return Une instance de l'objet copié
  */
  Epur &operator=(const Epur &);
public:
  /**
  * \fn const std::string &getString() const
  * \brief Récupère la chaine de caractères à épurer
  *
  * \return Une instance de la chaine de caractères à épurer
  */
  const std::string	&getString() const;
  /**
  * \fn std::string		epur(const std::string &, const char &);
  * \brief Epure la chaine de caractères passé en paramètre au caractère passé en paramètre
  *
  * \param str : Chaine de caractères à épurer
  * \param c : Caractère qui sera épuré
  * \return Une instance de la chaine de caractères épurée
  */
  std::string		epur(const std::string &, const char &);
  /**
  * \fn std::string		epur(const std::string &, const char &);
  * \brief Remplace dans la chaine de caractères passé en paramètre un caractère par un autre passé en paramètre
  *
  * \param str : Chaine de caractères où remplacer les caractères
  * \param c : Caractère qui sera remplacé
  * \param c2 : Caractère  remplacera l'autre caractère
  * \return Une instance de la chaine de caractères remplacé
  */
  std::string		replace(const std::string &, const char &, const char &);
};

#endif
