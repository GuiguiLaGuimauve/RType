//
// PacketQueue.hh for PacketQueue in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:06:44 2016 Maxime Lecoq
// Last update Sat Dec 31 14:24:28 2016 Lecoq Maxime
//

#ifndef PACKETQUEUE_HH_
# define PACKETQUEUE_HH_

# include "IPacketQueue.hh"

class PacketQueue : public IPacketQueue
{
public:
  PacketQueue();
  ~PacketQueue();
  void		push(const PacketC &);
  PacketC	pop();
  bool		isEmpty() const;
  uint64_t	size() const;
private:
  std::vector<PacketC>	_list;
};

#endif /* !PACKETQUEUE_HH_ */
