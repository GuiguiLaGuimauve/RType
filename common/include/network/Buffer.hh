//
// Buffer.hpp for zappy in /home/bertho_i/rendu/PSU_2015_zappy/include/client
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Tue Jun 14 16:46:40 2016 Simon BERTHO
// Last update Sun Dec 18 19:37:40 2016 lecoq
//

#ifndef BUFFER_HH
#define BUFFER_HH

#include <string>
#include <queue>

#include <stdint.h>
#include <stdio.h>

# include	"PacketUnknown.hpp"

class Buffer
{
public:
  Buffer();
  ~Buffer();
  void			push(const PacketUnknown &);
  PacketUnknown		pop();
  PacketUnknown		front();
  bool			isEmpty() const;
  size_t		len() const;
  void			clear();
protected:
  std::queue<PacketUnknown>		listS;
};

#endif