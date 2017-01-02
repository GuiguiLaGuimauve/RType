//
// C:\Users\Guimauve\Documents\RType\common\include\tools\ADLloader.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 10:57:22 2016 La Guimauve
// Last update Wed Dec 28 10:05:34 2016 La Guimauve
//

#ifndef _ADLLOADER_HH_
# define _ADLLOADER_HH_

class ADLloader : public IDLloader
{
public:
  virtual ~ADLloader() {};
  virtual bool loadLib(const std::string &path) = 0;
  virtual bool extractLib(const std::string &func) = 0;
  virtual bool dropLib() = 0;
};

#endif // _ADLLOADER_HH_
