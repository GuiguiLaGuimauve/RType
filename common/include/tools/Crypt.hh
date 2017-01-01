//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Crypt.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Mon Dec 19 23:31:10 2016 La Guimauve
// Last update Wed Dec 21 15:46:19 2016 La Guimauve
//

#ifndef _CRYPT_HH_
# define _CRYPT_HH_

#include <iostream>
#include "sha1.hh"

/*!
  \class Crypt Crypt.hh
  \brief classe pour le chiffrer une string
*/
class Crypt
{
private:
  char _key; /** \brief _key : contient la clé pour le xor */
  SHA1	_sha; /** \brief _sha : instance de l'objet SHA1 qui permet le hash */
public:
  /**
  * \fn Crypt()
  * \brief Constructeur de la classe
  */
  Crypt() : _key('R') {};

  /**
  * \fn _sha1(const std::string &)
  * \brief Chiffre la chaine de caractère en paramètre avec un hash sha1
  *
  * \param to_hash chaine de caractère à hash en sha1
  *
  * \return Une instance de la chaine de caractère hashé
  */
  std::string _sha1(const std::string &);
  /**
  * \fn _xor(const std::string &)
  * \brief Chiffre la chaine de caractère en paramètre avec un xor
  *
  * \param to_hash chaine de caractère à chiffrer xor
  *
  * \return Une instance de la chaine de caractère chiffré
  */
  std::string _xor(std::string);
};

#endif //_CRYPT_HH_
