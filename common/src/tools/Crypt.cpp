//
// C:\Users\Guimauve\Documents\RType\common\src\tools\Crypt.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Mon Dec 19 23:41:37 2016 La Guimauve
// Last update Tue Dec 20 23:18:20 2016 lecoq
//

#include "Crypt.hh"

std::string Crypt::_sha1(const std::string &to_hash)
{
  (void)to_hash;
  _sha.update(to_hash);
  return (_sha.final());
}

std::string Crypt::_xor(std::string to_encrypt)
{
	for (uint32_t temp = 0; temp < to_encrypt.size(); temp++)
		to_encrypt[temp] ^= this->_key;
	return (to_encrypt);
}