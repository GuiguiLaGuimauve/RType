//
// PacketQueue.cpp for PacketQueue in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:08:06 2016 Maxime Lecoq
// Last update Thu Dec 15 11:33:29 2016 lecoq
//

#include	"PacketQueue.hh"

PacketQueue::PacketQueue() {}
PacketQueue::~PacketQueue() {}

void		PacketQueue::push(const PacketC &p)
{
  _list.push_back(p);
}

PacketC		PacketQueue::pop()
{
  if (_list.empty() == false)
    {
      PacketC	ret = _list.front();
      _list.erase(_list.begin());
      return (ret);
    }
  else
    {
      PacketC ret; 
      return (ret);
    }
}

bool		PacketQueue::isEmpty() const
{
  return (_list.empty());
}
