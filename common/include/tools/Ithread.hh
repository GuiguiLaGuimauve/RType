//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Ithread.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 13:32:58 2016 La Guimauve
// Last update Wed Dec  7 13:41:41 2016 La Guimauve
//

#ifndef _ITHREAD_HH_
# define _ITHREAD_HH_

#include <thread>

namespace mythrd
{
  class Ithread
  {
  public:
    virtual ~Ithread() {};

    virtual bool joinable() const = 0;
    virtual void join() = 0;
    virtual void detach() = 0;
  };
}

#endif // _ITHREAD_HH_
