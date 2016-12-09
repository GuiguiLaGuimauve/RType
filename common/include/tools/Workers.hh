//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Workers.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 16:03:14 2016 La Guimauve
// Last update Fri Dec  9 10:11:12 2016 La Guimauve
//

#ifndef WORKERS_HH_
# define WORKERS_HH_

#include "ThreadPool.hh"

class ThreadPool;

class Workers {
private:
  ThreadPool &pool;
public:
    Workers(ThreadPool &s) : pool(s) {}
    void operator()();
};

#endif //WORKERS_HH_
