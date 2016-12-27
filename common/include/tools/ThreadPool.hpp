//
// C:\Users\Guimauve\Documents\RType\common\include\tools\ThreadPool.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 13:53:17 2016 La Guimauve
// Last update Tue Dec 27 12:35:51 2016 lecoq
//

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

#include <vector>
#include "Thread.hpp"
#include "mutex.hh"

class ThreadPool
{
public:
  std::vector<Thread *> _th;
  mymtx::mutex		_mutex;
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
    _mutex.lock();
    while (i < _th.size())
      {
	if (_th[i] && _th[i]->isRunning() == false)
	  {
	    _th[i]->launch(func, args...);
	    i = 0;
	    while (i < _th.size())
	      {
		if (_th[i] == NULL)
		  _th.erase(_th.begin() + i);
		else
		  i++;
	      }
	    _mutex.unlock();
	    return;
	  }
	i++;
      }
    Thread *th = new Thread;

    _th.push_back(th);
    th->launch(func, args...);
    i = 0;
    while (i < _th.size())
      {
	if (_th[i] == NULL)
	  _th.erase(_th.begin() + i);
	else
	  i++;
      }
    _mutex.unlock();
  };
  /*  template <typename C>
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
    };*/
};

#endif //THREADPOOL_HH_
