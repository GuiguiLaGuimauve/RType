//
// C:\Users\Guimauve\Documents\RType\common\include\tools\thread.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Fri Dec  2 13:38:28 2016 La Guimauve
// Last update Fri Dec 23 14:56:19 2016 lecoq
//

#ifndef _THREAD_HH_
# define _THREAD_HH_

#include "IThread.hh"

namespace mythrd
{
  class Thread : public IThread
  {
  private:
    std::thread thr;
  public:
    Thread() {};
    template <typename T, typename ... A>
    Thread(T&& func, A&&... args)
    {
      this->thr = std::thread(func, args...);
    };
    template <typename C>
    explicit Thread(C&& f)
    {
      this->thr = std::thread(f);
    };

    ~Thread(){};
    template <typename T, typename ... A>
    void launch(T&& func, A&&... args)
    {
      this->thr = std::thread(func, args...);
    };
    template <typename C>
    void launch(C&& f)
    {
      this->thr = std::thread(f);
    };
    void	pause(const uint32_t &a) const
    {
      std::this_thread::sleep_for(std::chrono::seconds(a));
    }
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
