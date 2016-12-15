//
// C:\Users\Guimauve\Documents\RType\common\src\tools\ThreadPool.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 16:19:21 2016 La Guimauve
// Last update Sat Dec 10 16:07:45 2016 La Guimauve
//

#include <iostream>
#include "ThreadPool.hh"

ThreadPool::ThreadPool(size_t nb_threads) : stop(false)
{
    for(size_t i = 0; i < nb_threads ; i++)
    {
      this->workers.push_back(std::thread(Workers(*this)));
    }
}

ThreadPool::~ThreadPool()
{
    this->stop = true;
    this->condition.notify_all();
    for(size_t i = 0; i < this->workers.size() ; i++)
      this->workers[i].join();
}

template<class F>
void ThreadPool::addToQueue(F f)
{
    {
      std::unique_lock<std::mutex> lock(mtx);
      this->tasks.push_back(std::function<void()>(f));
    }
    condition.notify_one();
}
