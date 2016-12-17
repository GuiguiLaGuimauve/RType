//
// PacketContener.hpp for PacketContener in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Sat Dec 17 11:34:59 2016 Maxime Lecoq
// Last update Sat Dec 17 12:33:18 2016 lecoq
//

#ifndef PACKETCONTENER_HPP_
# define PACKETCONTENER_HPP_

# include	<iostream>
# include	<string>
# include	"PacketList.h"
# include	"PacketFactory.hh"

class PacketFactory;

template<typename ... Args>
class PacketContener;

template<>
class PacketContener<const std::vector<DataPlayer *> &, const uint8_t &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataPlayer *> &, const uint8_t &); 
};

template<>
class PacketContener<const uint8_t *, const uint16_t &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const uint8_t *, const uint16_t &); 
};

template<>
class PacketContener<const std::string &, const uint8_t &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &, const uint8_t &);
};

template<>
class PacketContener<const std::vector<DataRoom *> &>
{
  typedef IPacket *(PacketFactory::*ptr)(const std::vector<DataRoom *> &);
};

template<>
class PacketContener<const std::string &, const IPacket::PacketType &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &, const IPacket::PacketType &);
};

template<>
class PacketContener<const std::string &>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(const std::string &);
};

template<>
class PacketContener<void>
{
public:
  typedef IPacket *(PacketFactory::*ptr)(); 
};

#endif /* !PACKETCONTENER_HPP_ */
