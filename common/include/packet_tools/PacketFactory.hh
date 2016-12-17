//
// PacketFactory.hh for PacketFactory in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Dec 15 11:41:19 2016 Maxime Lecoq
// Last update Sat Dec 17 12:29:15 2016 lecoq
//

#ifndef PACKETFACTORY_HH_
# define PACKETFACTORY_HH_

# include	<iostream>
# include	<string>
# include	<map>
# include	"IPacket.hh"
# include	"PacketList.h"
# include	"PacketContener.hpp"

using namespace Packet;

class	PacketFactory
{
public:
  PacketFactory();
  ~PacketFactory();
  IPacket	*getPacket(const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &);
  IPacket	*getPacket(const std::string &, const std::string &, const IPacket::PacketType &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &, const IPacket::PacketType &);
  IPacket	*getPacket(const std::string &, const std::string &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &);
  IPacket	*getPacket(const std::string &, const std::vector<DataRoom *> &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataRoom *> &);
  IPacket	*getPacket(const std::string &, const std::string &, const uint8_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::string &, const uint8_t &);
  IPacket	*getPacket(const std::string &, const uint8_t *, const uint16_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const uint8_t *, const uint16_t &);

  IPacket	*getPacket(const std::string &, const std::vector<DataPlayer *> &, const uint8_t &);
  IPacket	*getPacket(const IPacket::PacketType &, const std::vector<DataPlayer *> &, const uint8_t &);

  void		getPacket(const uint8_t *) const;
  void		enable(const std::string &);

private:
  IPacket	*getConnect();
  IPacket	*udpDataFree();
  
  IPacket	*getError(const std::string &, const IPacket::PacketType &);
  
  IPacket	*getWelcome(const std::string &);
  IPacket	*joinRoom(const std::string &);
  IPacket	*joinError(const std::string &);
  IPacket	*startGame(const std::string &);
  IPacket	*startError(const std::string &);
  IPacket	*leaveRoom(const std::string &);

  IPacket	*getRooms(const std::vector<DataRoom *> &);

  IPacket	*createRoom(const std::string &, const uint8_t &);

  IPacket	*udpData(const uint8_t *, const uint16_t &);

  IPacket	*getDataRoom(const std::vector<DataPlayer *> &, const uint8_t &);

private:
  PacketContener<void>										_pkt1;
  PacketContener<const std::string &, const IPacket::PacketType &>				_pkt2;
  PacketContener<const std::string &>								_pkt3;
  PacketContener<const std::vector<DataRoom *> &>						_pkt4;
  PacketContener<const std::string &, const uint8_t &>						_pkt5;
  PacketContener<const uint8_t *, const uint16_t &>						_pkt6;
  PacketContener<const std::vector<DataPlayer *> &, const uint8_t &>				_pkt7;
};

#endif /* !PACKETFACTORY_HH_ */
