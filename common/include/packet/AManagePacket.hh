//
// AManagePacket.hh for AManagePacket in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 10:50:29 2016 Maxime Lecoq
// Last update Thu Dec 15 15:07:57 2016 lecoq
//

#ifndef AMANAGEPACKET_HH_
# define AMANAGEPACKET_HH_

# include	"IPacketManager.hh"
# include	"PacketFactory.hh"

class	AManagePacket : public IPacketManager {
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
