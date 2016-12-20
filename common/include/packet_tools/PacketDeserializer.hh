//
// PacketDeserializer.hh for PacketDeserializer in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Oct 27 15:39:37 2016 Maxime Lecoq
// Last update Tue Dec 20 13:48:37 2016 lecoq
//

#ifndef PACKETDESERIALIZER_HH_
# define PACKETDESERIALIZER_HH_

# include	<stdint.h>
# include	<string>

namespace Packet
{
  class	PacketDeserializer
  {
  public:
    PacketDeserializer(const uint8_t *);
    ~PacketDeserializer();
    uint32_t	get32(const uint32_t &) const;
    uint32_t	getPacketSize() const;
	uint32_t	getPacketTickId() const;
    uint16_t	get16(const uint32_t &) const;
    uint8_t	get8(const uint32_t &) const;
    std::string	getString(const uint32_t &, const uint32_t &) const;
    void	setMsg(const uint8_t *m) { _msg = (uint8_t *)m; }
  private:
    uint8_t	*_msg;
	uint16_t _headerSize;
  };
};

using namespace Packet;

#endif /* !PACKETDESERIALIZER_HH_ */
