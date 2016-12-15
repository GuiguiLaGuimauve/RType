//
// C:\Users\Guimauve\Documents\RType\common\include\tools\dlloader\DLloaderWin.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 14:38:14 2016 La Guimauve
// Last update Thu Dec 15 15:57:09 2016 La Guimauve
//

#ifndef _DLLOADER_WIN_HH_
# define _DLLOADER_WIN_HH_

# ifdef _WIN32

#include <iostream>
#include <string>
#include <functional>
#include <windows.h>
#include "IDLloader.hh"

template <typename T>
class DLloaderWin : public IDLloader
{
private:
  HMODULE          _lib;
  FARPROC          _extract;
  std::function<T> _func;
public:
  DLloaderWin() {};
  ~DLloaderWin();

  bool loadLib(const std::string &path);
  bool extractLib(const std::string &func);
  bool loadandextract(const std::string &path, const std::string &func);
  bool dropLib();
};

# endif // _WIN32

#endif _DLLOADER_WIN_HH_
