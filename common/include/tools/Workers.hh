//
// C:\Users\Guimauve\Documents\RType\common\include\tools\Workers.hh for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 16:03:14 2016 La Guimauve
// Last update Mon Dec 26 11:28:07 2016 lecoq
//

#ifndef WORKERS_HH_
# define WORKERS_HH_

#include "ThreadPool.hpp"

class ThreadPool;

class Workers {
private:
  ThreadPool &pool;
public:
    Workers(ThreadPool &s) : pool(s) {}
    void operator()();
};

#endif //WORKERS_HH_
