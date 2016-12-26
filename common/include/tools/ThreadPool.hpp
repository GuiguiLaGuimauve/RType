//
// C:\Users\Guimauve\Documents\RType\common\include\tools\ThreadPool.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 13:53:17 2016 La Guimauve
// Last update Mon Dec 26 11:30:50 2016 lecoq
//

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

#include <vector>
#include "Thread.hpp"

class ThreadPool
{
public:
  std::vector<Thread *> _th;
public:
  ThreadPool() {
    uint8_t i = 0;
    while (i < 10)
      {
	_th.push_back(new Thread);
	i++;
      }
  };
  ~ThreadPool() {
    while (_th.empty() == false)
      {
	delete _th[0];
	_th.erase(_th.begin());
      }
  }
  template <typename T, typename ... A>
  void launchTask(T&& func, A&&... args)
  {
    uint64_t i;

    i = 0;
    while (i < _th.size())
      {
	if (_th[i]->isRunning() == false)
	  {
	    _th[i]->launch(func, args...);
	    return;
	  }
	i++;
      }
    Thread *th = new Thread;

    th->launch(func, args...);
    _th.push_back(th);
  };
  template <typename C>
  void launchTask(C&& f)
  {
    uint64_t i;

    i = 0;
    while (i < _th.size())
      {
	if (_th[i]->isRunning() == false)
	  {
	    _th[i]->launch(f);
	    return;
	  }
	i++;
      }
    Thread *th = new Thread;

    th->launch(f);
    _th.push_back(th);
  };
};

#endif //THREADPOOL_HH_
