//
// C:\Users\Guimauve\Documents\RType\common\include\tools\RunTimeError.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Tue Dec 20 10:49:41 2016 La Guimauve
// Last update Tue Dec 20 11:21:53 2016 La Guimauve
//

#ifndef _RUNTIMERROR_HH_
# define _RUNTIMERROR_HH_

#include "AError.hh"

namespace Error
{
  class RunTimeError : public AError
  {
  public:
    RunTimeError(const std::string &, const std::string &);
    RunTimeError(const std::string &);
    RunTimeError(const AError &);
    ~RunTimeError() throw() {};
  };
};
#endif //_RUNTIMERROR_HH_
