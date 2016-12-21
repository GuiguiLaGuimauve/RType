//
// C:\Users\Guimauve\Documents\RType\common\src\tools\ThreadPool.cpp for RType in
//
// Made by La Guimauve
// Login   <rembur_g@epitech.eu>
//
// Started on  Wed Dec  7 16:19:21 2016 La Guimauve
// Last update Wed Dec 21 15:03:10 2016 La Guimauve
//

#include <iostream>
#include "ThreadPool.hh"

ThreadPool::ThreadPool() : stop(false)
{
  this->workers.push_back(std::thread(Workers(*this)));
}

ThreadPool::~ThreadPool()
{
    this->stop = true;
    this->condition.notify_all();
    for(size_t i = 0; i < this->workers.size() ; i++)
      this->workers[i].join();
}
