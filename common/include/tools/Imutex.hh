//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Imutex.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec  1 16:24:11 2016 La Guimauve
// Last update Tue Dec  6 15:49:05 2016 La Guimauve
//

#ifndef _IMUTEX_HH_
# define _IMUTEX_HH_

namespace mymtx
{
  class Imutex
  {
  public:
    virtual ~Imutex() {};

    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void try_lock() = 0;
  };
}

#endif //_IMUTEX_HH_
