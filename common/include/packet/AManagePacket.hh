//
// AManagePacket.hh for AManagePacket in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 10:50:29 2016 Maxime Lecoq
// Last update Thu Dec 15 11:34:12 2016 lecoq
//

#ifndef AMANAGEPACKET_HH_
# define AMANAGEPACKET_HH_

# include	"IManagePacket.hh"

class	AManagePacket : public IManagePacket {
public:
  AManagePacket();
  ~AManagePacket();
  IPacketQueue *getPacketQueueRead() const;
  IPacketQueue *getPacketQueueWrite() const;
protected:
  IPacketQueue	*_queueRead;
  IPacketQueue	*_queueWrite;
  PacketFactory	_factory;
};

#endif /* !AMANAGEPACKET_HH_ */
