//
// C:\Users\Guimauve\Documents\RType\common\src\tools\dlloader\DLloaderUnix.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec 15 16:07:43 2016 La Guimauve
// Last update Tue Dec 20 11:10:50 2016 La Guimauve
//

#ifdef unix

DLloaderUnix<T>::~DLloaderUnix()
{
  dropLib();
}

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

bool DLloaderUnix<T>::droplib()
{
  dlclose(this->_lib);
  return (true);
}

#endif //unix
