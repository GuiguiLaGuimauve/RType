#include "AUserNetwork.hh"

using namespace Network;

AUserNetwork::AUserNetwork() 
{
	_fd = -1;
	_ip = "";
	_pseudo = "";
	_port = 4242;
	_status = false;
}

bool					AUserNetwork::getStatus() const
{
	return (_status);
}

void					AUserNetwork::setStatus(bool b)
{
	_status = b;
}


bool			AUserNetwork::haveSomethingToWrite() const
{
	return (buff_w.isEmpty());
}

bool			AUserNetwork::haveSomethingToRead() const
{
	return (buff_r.isEmpty());
}

void			AUserNetwork::setFd(const int32_t &fd)
{
	_fd = fd;
}

void			AUserNetwork::setPort(const uint32_t &port)
{
	_port = port;
}

void			AUserNetwork::setIp(const std::string &ip)
{
	_ip = ip;
}

const std::string		&AUserNetwork::getIp() const
{
	return (_ip);
}

void			AUserNetwork::setPseudo(const std::string &p)
{
	_pseudo = p;
}

const std::string		&AUserNetwork::getPseudo() const
{
	return (_pseudo);
}

uint32_t		AUserNetwork::getPort() const
{
	return (_port);
}

int32_t			AUserNetwork::getFd() const
{
	return (_fd);
}

void			AUserNetwork::pushBufferWrite(const PacketUnknown &mes)
{
  buff_w.push(mes);
}

void			AUserNetwork::pushBufferRead(const PacketUnknown &mes)
{
	buff_r.push(mes);
}

PacketUnknown		AUserNetwork::popBufferRead()
{
  return (buff_r.pop());
}

PacketUnknown		AUserNetwork::popBufferWrite()
{
  return (buff_w.pop());
}

void			AUserNetwork::cutRead(uint8_t *buff, const int32_t &nb)
{
  PacketDeserializer	ds(buff);
  int32_t		size = nb;

  while (ds.getPacketSize() + 9 < (uint32_t)size && size > 0)
    {
      //      std::cout << "Pkt type net :" << (int)buff[0] << std::endl;
      int32_t	tmp = ds.getPacketSize() + 9;
      PacketUnknown pk(buff, tmp);
      buff_r.push(pk);
      buff += tmp;
      size -= tmp;
      ds.setMsg(buff);
    }
  if (size > 0)
    {
      //      std::cout << "Pkt type net :" << (int)buff[0] << std::endl;
      PacketUnknown pkt((uint8_t *)buff, size);
      buff_r.push(pkt);
    }
}
