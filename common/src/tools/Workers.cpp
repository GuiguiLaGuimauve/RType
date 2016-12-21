//
// C:\Users\Guimauve\Documents\RType\common\src\tools\Workers.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 16:13:01 2016 La Guimauve
// Last update Wed Dec 21 19:13:29 2016 La Guimauve
//

#include <iostream>
#include "Workers.hh"

void Workers::operator()()
{
    std::function<void()> task;
    while(true)
    {
      {
        std::unique_lock<std::mutex>lck(pool.mtx.mtx);
        std::cerr << "Nb Thread => " << pool.workers.size() << " Nb tasks => " << pool.tasks.size() << std::endl;
        while(!pool.stop && pool.tasks.empty())
          pool.condition.wait(lck);
        if(pool.stop)
          return;
        task = pool.tasks.front();
        pool.tasks.pop_front();
        if (pool.tasks.size() > pool.workers.size())
          pool.workers.push_back(std::thread(Workers(pool)));
      }
      task();
    }
}
