//
// IManagePacket.hh for IManagePacket in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 10:49:12 2016 Maxime Lecoq
// Last update Thu Dec 15 11:34:36 2016 lecoq
//

#ifndef IMANAGEPACKET_HH_
# define IMANAGEPACKET_HH_

# include	"PacketQueue.hh"

class IManagePacket
{
public:
  virtual ~IManagePacket() {};
  virtual IPacketQueue *getPacketQueueRead() const = 0;
  virtual IPacketQueue *getPacketQueueWrite() const = 0;
};

#endif /* !IMANAGEPACKET_HH_ */
