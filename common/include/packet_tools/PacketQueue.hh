//
// PacketQueue.hh for PacketQueue in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:06:44 2016 Maxime Lecoq
// Last update Thu Dec 15 11:10:36 2016 lecoq
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
private:
  std::vector<PacketC>	_list;
};

#endif /* !PACKETQUEUE_HH_ */
