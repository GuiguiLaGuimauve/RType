//
// Clock.cpp for plazza in /home/bertho_i/rendu/cpp_plazza/srcs
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Tue Apr 12 17:22:14 2016 Simon BERTHO
// Last update Mon Dec 12 16:04:07 2016 Simon BERTHO
//

#include "Clock.hpp"

Clock::Clock()
{
  reset();
}

Clock::~Clock()
{
}

void	Clock::reset()
{
  first = std::chrono::system_clock::now();
}

int					Clock::getTime()
{
  std::chrono::system_clock::time_point tmp;
  int					dest;

  tmp = std::chrono::system_clock::now();
  dest = (int) std::chrono::duration_cast<std::chrono::seconds>(tmp - first).count();
  return (dest);
}

int					Clock::getTimeMilli()
{
  std::chrono::system_clock::time_point tmp;
  int					dest;

  tmp = std::chrono::system_clock::now();
  dest = (int) std::chrono::duration_cast<std::chrono::milliseconds>(tmp - first).count();
  return (dest);
}

int					Clock::getTimeNano()
{
  std::chrono::system_clock::time_point tmp;
  int					dest;

  tmp = std::chrono::system_clock::now();
  dest = (int) std::chrono::duration_cast<std::chrono::nanoseconds>(tmp - first).count();
  return (dest);
}
