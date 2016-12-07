//
// C:\Users\Guimauve\Documents\RType\common\include\tools\thread.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 13:38:28 2016 La Guimauve
// Last update Wed Dec  7 13:45:31 2016 La Guimauve
//

#ifndef _THREAD_HH_
# define _THREAD_HH_

#include "Ithread.hh"

namespace mythrd
{
  template <typename T>
  class thread : public Ithread
  {
  public:
    typedef   void (T::*fct)(void);

  private:
    std::thread thr;
  public:
    thread(fct func, T *arg)
    {
      this->thr = std::thread(func, arg);
    };
    ~thread(){};

    bool joinable() const
    {
      return (this->thr.joinable());
    };

    void join()
    {
      this->thr.join();
    };

    void detach()
    {
      this->thr.detach();
    };
  };
}

#endif // _THREAD_HH_
