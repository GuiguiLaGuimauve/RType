//
// AManagePacket.cpp for AManagePacket in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 10:53:25 2016 Maxime Lecoq
// Last update Thu Dec 15 11:35:29 2016 lecoq
//

#include	"AManagePacket.hh"

AManagePacket::AManagePacket()
{
}

AManagePacket::~AManagePacket()
{
}

IPacketQueue		*AManagePacket::getPacketQueueRead() const
{
  return (_queueRead);
}

IPacketQueue		*AManagePacket::getPacketQueueWrite() const
{
  return (_queueWrite);
}
