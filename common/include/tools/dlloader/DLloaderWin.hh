//
// C:\Users\Guimauve\Documents\RType\common\include\tools\dlloader\DLloaderWin.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 14:38:14 2016 La Guimauve
// Last update Wed Dec 28 17:13:06 2016 La Guimauve
//

#ifndef _DLLOADER_WIN_HH_
# define _DLLOADER_WIN_HH_

# ifdef _WIN32

#include <iostream>
#include <string>
#include <functional>
#include <windows.h>
#include "IDLloader.hh"
#include "RunTimeError.hh"

template <typename T>
class DLloaderWin : public IDLloader
{
private:
  HMODULE          _lib;
  FARPROC          _extract;
public:
  DLloaderWin() {};
  ~DLloaderWin();

  bool loadLib(const std::string &path);
  bool extractLib(const std::string &func);
  bool loadandextract(const std::string &path, const std::string &func);
  bool dropLib();
  std::function<T> _func;
};

template <typename T>
DLloaderWin<T>::~DLloaderWin()
{
}

template <typename T>
bool DLloaderWin<T>::loadLib(const std::string &path)
{
  this->_lib = LoadLibrary(path.c_str());

  if (this->_lib == NULL)
    {
      std::cerr << "Could not load DLL \"" << path << "\"" << std::endl;
	  throw std::runtime_error("Library not found in the directory");
    }
  return (true);
}

template <typename T>
bool DLloaderWin<T>::extractLib(const std::string &func)
{
	if (this->_lib == NULL)
		throw std::runtime_error("No lib loaded");

  this->_extract = GetProcAddress(this->_lib, func.c_str());
  if (this->_extract == NULL)
    {
      std::cerr << "Could not locate the function \"" << func << "\" in DLL \""
                << this->_lib << "\"" << std::endl;
	  throw std::runtime_error("function not found in the lib");
    }
  //TODO : __stdcall
  this->_func = reinterpret_cast<T*>(this->_extract);
  return (true);
}

template <typename T>
bool DLloaderWin<T>::loadandextract(const std::string &path, const std::string &func)
{
  this->_lib = LoadLibrary(path.c_str());

  if (this->_lib == NULL)
    {
      std::cerr << "Could not load DLL \"" << path << "\"" << std::endl;
      throw std::runtime_error("Library not found in the directory");
    }

    this->_extract = GetProcAddress(this->_lib, func.c_str());
    if (!this->_extract)
      {
        std::cerr << "Could not locate the function \"" << func << "\" in DLL\""
                  << this->_lib << "\"" << std::endl;
		throw std::runtime_error("function not found in the lib");
      }

	//TODO : __stdcall
	this->_func = reinterpret_cast<T*>(this->_extract);
    return (true);
}

template <typename T>
bool DLloaderWin<T>::dropLib()
{
  FreeLibrary(this->_lib);
  return (true);
}

# endif // _WIN32

#endif //_DLLOADER_WIN_HH_
