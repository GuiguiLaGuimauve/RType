//
// C:\Users\Guimauve\Documents\RType\common\include\tools\thread.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 13:38:28 2016 La Guimauve
// Last update Fri Dec  9 11:21:48 2016 La Guimauve
//

#ifndef _THREAD_HH_
# define _THREAD_HH_

#include "Ithread.hh"

namespace mythrd
{
  class thread : public Ithread
  {
  public:
    //typedef   void (T::*fct)(A... args);

  private:
    std::thread thr;
  public:
    template <typename T, typename ... A>
    thread(T&& func, A&&... args)
    {
      this->thr = std::thread(func, args...);
    };

    template <typename C>
    explicit thread(C f)
    {
      this->thr = std::thread(f);
    }
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
