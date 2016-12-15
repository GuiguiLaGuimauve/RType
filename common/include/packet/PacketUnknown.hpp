//
// PacketUnknown.hh for PacketUnknown in /home/lecoq_m/cpp_babel
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Thu Nov 10 17:29:55 2016 Maxime Lecoq
// Last update Fri Nov 11 14:10:11 2016 lecoq
//

#ifndef PACKETUNKNOWN_HPP_
# define PACKETUNKNOWN_HPP_

# include	<stdint.h>

class	PacketUnknown
{
private:
	uint8_t	*_data;
	int32_t	_size;
	bool		_ok;
public:
  PacketUnknown() :  _size(0), _ok(false)  { unsigned char *data = (unsigned char *)"\0"; _data = data;};
  PacketUnknown(uint8_t *data, const int32_t &size) : _data(data), _size(size), _ok(true) {};
  ~PacketUnknown() {};
  uint8_t	*getPacketData() const { return (_data); };
  int32_t	getPacketSize() const { return (_size); };
  bool		packetIsValid() const { return (_ok); }
};

#endif /* !PACKETUNKNOWN_HPP_ */
