//
// PacketQueue.hpp for PacketQueue in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Sat Nov 12 09:26:50 2016 Maxime Lecoq
// Last update Sat Nov 12 10:01:06 2016 lecoq
//

#ifndef IPACKETQUEUE_HH_
# define IPACKETQUEUE_HH_

# include	<vector>
# include	<stdint.h>
# include	"PacketC.hpp"

using namespace Network;

class		IPacketQueue
{
public:
  virtual ~IPacketQueue() {};
  virtual void		push(const PacketC &) = 0;
  virtual PacketC	pop() = 0;
  virtual bool		empty() const = 0;
  virtual uint32_t	size() const = 0;
  };

#endif /* !IPACKETQUEUE_HH_ */
