//
// C:\Users\Guimauve\Documents\RType\common\src\tools\Crypt.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Mon Dec 19 23:41:37 2016 La Guimauve
// Last update Mon Dec 19 23:46:46 2016 La Guimauve
//

#include "Crypt.hh"

std::string Crypt::sha1(const std::string &to_hash)
{
	return ("Sha1");
}

std::string Crypt::xor(std::string to_encrypt)
{
	for (int temp = 0; temp < to_encrypt.size(); temp++)
		to_encrypt[temp] ^= this->_key;
	return (to_encrypt);
}
