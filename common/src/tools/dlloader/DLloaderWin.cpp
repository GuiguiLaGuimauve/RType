//
// C:\Users\Guimauve\Documents\RType\common\src\tools\dlloader\DLloaderWin.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 15:28:04 2016 La Guimauve
// Last update Wed Dec 28 17:13:03 2016 La Guimauve
//

#ifdef _WIN32
/*
#include "DLloaderWin.hh"

template <typename T>
DLloaderWin<T>::~DLloaderWin()
{
  this->dropLib();
}

template <typename T>
bool DLloaderWin<T>::loadLib(const std::string &path)
{
  this->_lib = LoadLibrary(path.c_str());

  if (this->_lib == NULL)
    {
      std::cerr << "Could not load DLL \"" << path << "\"" << std::endl;
      throw Error::RunTimeError("Library not found in the directory");
    }
  return (true);
}

template <typename T>
bool DLloaderWin<T>::extractLib(const std::string &func)
{
	if (this->_lib == NULL)
		throw Error::RunTimeError("No lib loaded");

  this->_extract = GetProcAddress(this->_lib, func.c_str());
  if (!this->_extract)
    {
      std::cerr << "Could not locate the function \"" << func << "\" in DLL\""
                << this->_lib << "\"" << std::endl;
      throw Error::RunTimeError("function not found in the lib");
    }

  this->_func = reinterpret_cast<__stdcall T*>(this->_extract);
  return (true);
}

template <typename T>
bool DLloaderWin<T>::loadandextract(const std::string &path, const std::string &func)
{
  this->_lib = LoadLibrary(path.c_str());

  if (this->_lib == NULL)
    {
      std::cerr << "Could not load DLL \"" << path << "\"" << std::endl;
      throw Error::RunTimeError("Library not found in the directory");
    }

    this->_extract = GetProcAddress(this->_lib, func.c_str());
    if (!this->_extract)
      {
        std::cerr << "Could not locate the function \"" << func << "\" in DLL\""
                  << this->_lib << "\"" << std::endl;
        throw Error::RunTimeError("function not found in the lib");
      }

    this->_func = reinterpret_cast<__stdcall T*>(this->_extract);
    return (true);
}

template <typename T>
bool DLloaderWin<T>::dropLib()
{
  FreeLibrary(this->_lib);
  return (true);
}
*/
#endif // _WIN32
