//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Imutex.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Thu Dec  1 16:24:11 2016 La Guimauve
// Last update Fri Dec  2 11:38:59 2016 La Guimauve
//

#ifndef _IMUTEX_HH_
# define _IMUTEX_HH_

class Imutex
{
public:
  virtual ~Imutex() {};

  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual void try_lock() = 0;
};

#endif //_IMUTEX_HH_
