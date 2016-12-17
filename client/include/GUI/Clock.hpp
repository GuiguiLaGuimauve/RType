//
// Clock.hpp for plazza in /home/bertho_i/rendu/cpp_plazza/include
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Tue Apr 12 17:21:52 2016 Simon BERTHO
// Last update Mon Dec 12 16:00:27 2016 Simon BERTHO
//

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <iostream>
#include <chrono>
#include <ctime>

class Clock
{
public:
  Clock();
  virtual ~Clock();

  void		reset();
  int		getTime();
  int		getTimeMilli();
  int		getTimeNano();
protected:
  std::chrono::system_clock::time_point	first;
};

#endif
