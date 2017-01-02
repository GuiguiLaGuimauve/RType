//
// CatchString.hh for  in /home/lecoq_m/cpp_plazza
//
// Made by Maxime LECOQ
// Login   <lecoq_m@epitech.net>
//
// Started on  Mon Apr 18 13:38:30 2016 Maxime LECOQ
// Last update Mon Dec 26 14:37:28 2016 La Guimauve
//

#ifndef		__CATCHIT_HH__
# define	__CATCHIT_HH__

//Permet de throw des catchit (objet)
/*!
  \class CatchIt CatchIt.hh
  \brief classe permettant d'envoyer des objets en erreurs
*/
template<typename X>
class		CatchIt
{
private:
  X	_obj; /** \brief _obj : objet qui va etre envoyé en erreur */
public:
  /**
  * \fn CatchIt(const X &)
  * \brief Constructeur de CatchIt avec spécification de l'objet à envoyé
  *
  * \param obj objet a envoyé
  */
  CatchIt(const X &obj) : _obj(obj) {};
  /**
  * \fn ~CatchIt()
  * \brief Destructeur de la classe CatchIt
  */
  ~CatchIt() {};
  /**
  * \fn CatchIt(const CatchIt &cop)
  * \brief Constructeur par copie de CatchIt
  *
  * \param cop objet à copier
  */
  CatchIt(const CatchIt &cop) : _obj(cop._obj) {};
  /**
  * \fn CatchIt	&operator=(const CatchIt &)
  * \brief Surcharge de l'operateur = pour la copie d'objet
  *
  * \param cop objet à copier
  * \return une instance de l'objet à copier
  */
  CatchIt	&operator=(const CatchIt &cop)
  {
    if (this != &cop)
      {
	_obj = cop._obj;
      }
    return (*this);
  };


  /**
  * \fn getIt()
  * \brief Récupère l'objet à envoyer
  *
  * \return une instance de l'objet à envoyer
  */
  X		getIt() const
  {
    return (_obj);
  };

};

#endif
