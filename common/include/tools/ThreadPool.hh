//
// C:\Users\Guimauve\Documents\RType\common\include\tools\ThreadPool.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 13:53:17 2016 La Guimauve
// Last update Tue Dec 20 22:15:54 2016 julien dufrene
//

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

#include <vector>
#include <deque>
#include <condition_variable>
#include "mutex.hh"
#include "Thread.hpp"
#include "Workers.hh"

class Workers;

class ThreadPool
{
private:
  friend class Workers;

  std::vector<std::thread> workers;
  std::deque<std::function<void()>> tasks;

  mymtx::mutex mtx;
  std::condition_variable condition;
  bool stop;

public:
    ThreadPool(size_t);
    ~ThreadPool();
    template<class F>
    void addToQueue(F f);
  };

#endif //THREADPOOL_HH_
