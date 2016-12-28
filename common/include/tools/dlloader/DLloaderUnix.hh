//
// C:\Users\Guimauve\Documents\RType\common\include\tools\dlloader\DLloaderUnix.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 14:57:41 2016 La Guimauve
// Last update Wed Dec 28 17:12:17 2016 La Guimauve
//

#ifndef _DLLOADER_UNIX_HH_
# define _DLLOADER_UNIX_HH_

# ifndef _WIN32

#include <iostream>
#include <functional>
#include <dlfcn.h>
#include "IDLloader.hh"
#include "RunTimeError.hh"

template <typename T>
class DLloaderUnix : public IDLloader
{
private:
  void              *_lib;
  void              *_extract;
public:
  DLloaderUnix();
  ~DLloaderUnix();

  bool loadLib(const std::string &path);
  bool extractLib(const std::string &func);
  bool loadandextract(const std::string &path, const std::string &func);
  bool dropLib();

  std::function<T>  _func;
};

template <typename T>
DLloaderUnix<T>::DLloaderUnix()
{
}

template <typename T>
DLloaderUnix<T>::~DLloaderUnix()
{
  dropLib();
}

template <typename T>
bool DLloaderUnix<T>::loadLib(const std::string &path)
{
  this->_lib = dlopen(path.c_str(), RTLD_LAZY);

  if (this->_lib == NULL)
  {
    std::cerr << "Could not load DLL \"" << path << "\"" << std::endl;
    throw Error::RunTimeError("Library not found in the directory");
  }
  return (true);
}

template <typename T>
bool DLloaderUnix<T>::extractLib(const std::string &func)
{
  if (this->_lib == NULL)
    throw Error::RunTimeError("No lib loaded");

  this->_extract = dlsym(this->_lib, func.c_str());
  if (this->_extract == NULL)
  {
    std::cerr << "Could not locate the function \"" << func << "\" in DLL\""
              << this->_lib << "\"" << std::endl;
    throw Error::RunTimeError("function not found in the lib");
  }

  this->_func = reinterpret_cast<T*>(this->_extract);
  return (true);
}

template <typename T>
bool DLloaderUnix<T>::loadandextract(const std::string &path, const std::string &func)
{
  this->_lib = dlopen(path.c_str(), RTLD_LAZY);

  if (this->_lib == NULL)
  {
    std::cerr << "Could not load DLL \"" << path << "\"" << std::endl;
    throw Error::RunTimeError("Library not found in the directory");
  }
  this->_extract = dlsym(this->_lib, func.c_str());
  if (this->_extract == NULL)
  {
    std::cerr << "Could not locate the function \"" << func << "\" in DLL\""
              << this->_lib << "\"" << std::endl;
    throw Error::RunTimeError("function not found in the lib");
  }

  this->_func = reinterpret_cast<T*>(this->_extract);
  return (true);
}

template <typename T>
bool DLloaderUnix<T>::dropLib()
{
  dlclose(this->_lib);
  return (true);
}

# endif // _WIN32

#endif //_DLLOADER_UNIX_HH_
