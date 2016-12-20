//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Crypt.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Mon Dec 19 23:31:10 2016 La Guimauve
// Last update Tue Dec 20 09:50:34 2016 julien dufrene
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

  std::string _sha1(const std::string &);
  std::string _xor(std::string);
};

#endif //_CRYPT_HH_