//
// Buffer.cpp for zappy in /home/bertho_i/rendu/PSU_2015_zappy/src/client
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Tue Jun 14 16:46:23 2016 Simon BERTHO
// Last update Sun Jan  1 06:20:39 2017 Lecoq Maxime
//

#include "Buffer.hh"
#include <iostream>

Buffer::Buffer() {}

Buffer::~Buffer() {}

void	Buffer::push(const PacketUnknown &pkt)
{
  if (pkt.getPacketData() != NULL)
    listS.push(pkt);
}

PacketUnknown		Buffer::pop()
{
  if (listS.empty())
    {
      PacketUnknown pkt;
      return (pkt);
    }
  PacketUnknown		dest = listS.front();
  listS.pop();
  return (dest);
}

size_t	Buffer::len() const
{
  return (listS.size());
}

void	Buffer::clear()
{
  while (!listS.empty())
    listS.pop();
}

PacketUnknown	Buffer::front()
{
  return (listS.front());
}


bool	Buffer::isEmpty() const
{
	if (listS.empty() == true)
		return (false);
	return (true);
}
