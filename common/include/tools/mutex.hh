//
// C:\Users\Guimauve\Documents\RType\common\include\tools\mutex.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 10:05:27 2016 La Guimauve
// Last update Tue Dec  6 15:47:58 2016 La Guimauve
//

#ifndef _MUTEX_HH_
# define _MUTEX_HH_

#include <mutex>
#include "Imutex.hh"

namespace mymtx
{
  class mutex : public Imutex
  {
  private:
    std::mutex mtx;
  public:
    mutex();
    ~mutex();

    void lock();
    void unlock();
    void try_lock();
  };
}
#endif // _MUTEX_HH_
