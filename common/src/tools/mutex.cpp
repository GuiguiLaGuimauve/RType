//
// C:\Users\Guimauve\Documents\RType\common\src\tools\mutex.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 10:30:19 2016 La Guimauve
// Last update Fri Dec  2 11:10:11 2016 La Guimauve
//

#include "mutex.hh"

mutex::mutex()
{
}

mutex::~mutex()
{
}

void      mutex::lock()
{
  this->mtx.lock();
}

void      mutex::unlock()
{
  this->mtx.unlock();
}

void      mutex::try_lock()
{
  this->mtx.try_lock();
}
