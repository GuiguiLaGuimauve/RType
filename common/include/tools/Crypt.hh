//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Crypt.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Mon Dec 19 23:31:10 2016 La Guimauve
// Last update Tue Dec 20 23:16:56 2016 lecoq
//

#ifndef _CRYPT_HH_
# define _CRYPT_HH_

#include <iostream>
#include "sha1.hh"

class Crypt
{
private:
  char _key;
  SHA1	_sha;
public:
  Crypt() : _key('R') {};

  std::string _sha1(const std::string &);
  std::string _xor(std::string);
};

#endif //_CRYPT_HH_
