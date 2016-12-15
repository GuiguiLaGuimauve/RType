//
// IPacketQueue.hh for IPacketQueue in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:02:19 2016 Maxime Lecoq
// Last update Thu Dec 15 11:40:37 2016 lecoq
//

#ifndef IPACKETQUEUE_HH_
# define IPACKETQUEUE_HH_

# include <vector>
# include "PacketC.hpp"

class IPacketQueue
{
public:
  virtual ~IPacketQueue() {};
  virtual void		push(const PacketC &) = 0;
  virtual PacketC	pop() = 0;
  virtual bool		isEmpty() const = 0;
};

#endif /* !IPACKETQUEUE_HH_ */
