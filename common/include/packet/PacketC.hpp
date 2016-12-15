//
// Packet.hpp for Packet in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Sat Nov 12 09:39:16 2016 Maxime Lecoq
// Last update Sat Nov 12 10:01:54 2016 lecoq
//

#ifndef PACKET_HPP_
# define PACKET_HPP_

# include	"IUserNetwork.hh"
# include	"PacketUnknown.hpp"

using namespace Network;

class	PacketC
{
public:
  PacketC() : _n(NULL) {};
  PacketC(PacketUnknown &p, IUserNetwork *n) : _p(p), _n(n) {};
  ~PacketC() {};
  PacketUnknown getPacket() const { return (_p); };
  IUserNetwork	*getNetwork() const { return (_n); };
private :
  PacketUnknown _p;
  IUserNetwork	*_n;
};

#endif /* !PACKET_HPP_ */
