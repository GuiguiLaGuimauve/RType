//
// C:\Users\Guimauve\Documents\RType\common\src\tools\mutex.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 10:30:19 2016 La Guimauve
// Last update Tue Dec  6 15:50:45 2016 La Guimauve
//

#include "mutex.hh"

mymtx::mutex::mutex()
{
}

mymtx::mutex::~mutex()
{
}

void      mymtx::mutex::lock()
{
  this->mtx.lock();
}

void      mymtx::mutex::unlock()
{
  this->mtx.unlock();
}

void      mymtx::mutex::try_lock()
{
  this->mtx.try_lock();
}
