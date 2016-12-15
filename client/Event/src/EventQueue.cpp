//
// EventQueue.cpp for cpp_babel in /home/oger_a/rendu3/Babel/cpp_babel
// 
// Made by Antonin Oger
// Login   <oger_a@epitech.net>
// 
// Started on  Wed Oct 19 11:01:03 2016 Antonin Oger
// Last update Sat Oct 22 00:36:56 2016 Simon BERTHO
//

#include "EventQueue.hh"

using namespace EventPart;

EventQueue::EventQueue(const bool &mutex)
{
  this->_mutex = mutex;
}

EventQueue::~EventQueue()
{
}

void		EventQueue::push(const Event &event)
{
  this->_queue.push(event);
}

Event		EventQueue::pop()
{
  Event		e = this->_queue.front();

  this->_queue.pop();
  return (e);
}

bool		EventQueue::empty() const
{
  return(this->_queue.empty());
}

uint32_t	EventQueue::size() const
{
  return (this->_queue.size());
}

bool		EventQueue::getMutex() const
{
  return (this->_mutex);
}

void		EventQueue::setMutex(const bool &mutex)
{
  this->_mutex = mutex;
}
