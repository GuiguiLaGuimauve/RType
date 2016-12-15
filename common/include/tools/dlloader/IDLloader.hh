//
// C:\Users\Guimauve\Documents\RType\common\include\tools\dlloader\IDLloader.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 14:39:03 2016 La Guimauve
// Last update Thu Dec 15 15:16:51 2016 La Guimauve
//

#ifndef _IDLLOADER_HH_
# define _IDLLOADER_HH_

class IDLloader
{
public:
  virtual ~IDLloader() {};
  virtual bool loadLib(const std::string &path) = 0;
  virtual bool extractLib(const std::string &func) = 0;
  virtual bool loadandextract(const std::string &path, const std::string &func) = 0;
  virtual bool dropLib() = 0;
};

#endif // _IDLLOADER_HH_
