//
// Buffer.cpp for zappy in /home/bertho_i/rendu/PSU_2015_zappy/src/client
// 
// Made by Simon BERTHO
// Login   <bertho_i@epitech.net>
// 
// Started on  Tue Jun 14 16:46:23 2016 Simon BERTHO
// Last update Sat Nov 12 14:06:51 2016 lecoq
//

#include "Buffer.hh"
#include <iostream>

Buffer::Buffer() {}

Buffer::~Buffer() {}
/*
void	Buffer::push(const PacketUnknown &pkt)
{
  list.push(pkt);
}

PacketUnknown		Buffer::pop()
{
  if (list.empty())
    {
      PacketUnknown pkt;
      return (pkt);
    }
  PacketUnknown		dest = list.front();
  list.pop();
  return (dest);
}

size_t	Buffer::len() const
{
  return (list.size());
}

void	Buffer::clear()
{
  while (!list.empty())
    list.pop();
}

PacketUnknown	Buffer::front()
{
  return (list.front());
}
*/

bool	Buffer::isEmpty() const
{
	return (listS.empty());
}

void	Buffer::push(const std::string &pkt)
{
	listS.push(pkt);
}

const std::string		Buffer::pop()
{
	if (listS.empty())
	{
		std::cerr << "Buffer: pop on empty buffer" << std::endl;
		std::string pkt = "";
		return (pkt);
	}
	std::string		dest = listS.front();
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

std::string	Buffer::front()
{
	return (listS.front());
}
