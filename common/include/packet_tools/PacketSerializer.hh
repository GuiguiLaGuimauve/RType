//
// PacketSerializer.hh for PacketSerializer in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Oct 27 14:38:40 2016 Maxime Lecoq
// Last update Thu Oct 27 18:33:36 2016 Maxime Baconnais
//

#ifndef PACKETSERIALIZER_HH_
# define PACKETSERIALIZER_HH_

# include	<string>
# include	<stdint.h>
# include	"Convert.hpp"

namespace Packet
{
  class	PacketSerializer
  {
  public:
    PacketSerializer();
    ~PacketSerializer();
    void		add(const uint32_t &);
    void		add(const uint16_t &);
    void		add(const uint8_t &);
    void		add(const std::string &);
    void		add(const char *);
    uint8_t	*getPacket() const;
    uint32_t	getPacketSize() const;
  private:
    std::string	_string;
  };
};

using namespace Packet;

#endif /* !PACKETSERIALIZER_HH_ */
