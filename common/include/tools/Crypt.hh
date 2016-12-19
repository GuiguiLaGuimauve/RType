//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Crypt.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Mon Dec 19 23:31:10 2016 La Guimauve
// Last update Mon Dec 19 23:50:33 2016 La Guimauve
//

#ifndef _CRYPT_HH_
# define _CRYPT_HH_

#include <iostream>

class Crypt
{
private:
  char _key;
public:
  Crypt() : _key('R') {};

  std::string sha1(const std::string &);
  std::string xor(std::string);
};

#endif _CRYPT_HH_
