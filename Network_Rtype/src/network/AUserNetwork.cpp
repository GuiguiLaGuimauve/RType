#include "AUserNetwork.hh"

using namespace Network;

AUserNetwork::AUserNetwork() 
{
	_fd = -1;
	_ip = "";
	_port = 4242;
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

uint32_t		AUserNetwork::getPort() const
{
	return (_port);
}

int32_t			AUserNetwork::getFd() const
{
	return (_fd);
}

void			AUserNetwork::pushBufferWrite(const std::string &mes)
{
	buff_w.push(mes);
}

const std::string		AUserNetwork::popBufferRead()
{
	return (buff_r.pop());
}
