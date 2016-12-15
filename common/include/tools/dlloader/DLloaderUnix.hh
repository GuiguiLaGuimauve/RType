//
// C:\Users\Guimauve\Documents\RType\common\include\tools\dlloader\DLloaderUnix.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 14:57:41 2016 La Guimauve
// Last update Thu Dec 15 15:57:14 2016 La Guimauve
//

#ifndef _DLLOADER_UNIX_HH_
# define _DLLOADER_UNIX_HH_

# ifdef unix

#include <iostream>
#include <dlfcn>

typename <template T>
class DLloaderUnix : public IDLloader
{
private:
  void              *_lib;
  void              *_extract;
  std::function<T>  _func;
public:
  DLloaderUnix() {};
  ~DLloaderUnix();

  bool loadLib(const std::string &path);
  bool extractLib(const std::string &func);
  bool loadandextract(const std::string &path, const std::string &func);
  bool dropLib();
};

# endif // unix

#endif //_DLLOADER_UNIX_HH_
