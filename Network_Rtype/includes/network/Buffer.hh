//
// Buffer.hpp for zappy in /home/bertho_i/rendu/PSU_2015_zappy/include/client
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Tue Jun 14 16:46:40 2016 Simon BERTHO
// Last update Sat Nov 12 14:06:10 2016 lecoq
//

#ifndef BUFFER_HH
#define BUFFER_HH

#include <string>
#include <queue>

#include <stdint.h>
#include <stdio.h>

//# include	"PacketUnknown.hpp"

class Buffer
{
public:
  Buffer();
  ~Buffer();
  /*void			push(const PacketUnknown &);
  PacketUnknown		pop();
  size_t		len() const;
  void			clear();
  PacketUnknown		front();*/
  void			push(const std::string &);
  const std::string	pop();
  size_t		len() const;
  void			clear();
  std::string	front();
protected:
  //std::queue<PacketUnknown>		list;
  std::queue<std::string>		listS;
};

#endif
