//
// ManageNetworkUDP.cpp for ManageNetworkUDP.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:37:09 2016 julien dufrene
// Last update Fri Dec 23 02:55:48 2016 julien dufrene
//

#include	"ManageNetworkUDPClient.hh"

using namespace Network;

ManageNetworkUDPClient::ManageNetworkUDPClient()
{
  _initServ = false;
  _serv = NULL;
}

ManageNetworkUDPClient::~ManageNetworkUDPClient()
{
  if (_init == true)
    {
      try {
	_net->closeIt();
	delete _net;
      }
      catch (AError const &e)
	{
	  std::cout << e.what() << std::endl;
	}
    }
}

std::vector<std::string>        ManageNetworkUDPClient::updateUsers(const std::vector<IUserNetwork *> &user)
{
  std::vector<std::string>	empty;

  if (user.size() != 0)
    {
      if (_initServ != false)
	std::cerr << "[UDP ERROR] closing socket server." << std::endl;
      _initServ = false;
      delete (_serv);
      _serv = NULL;
    }
  return (empty);
}

IUserNetwork            *ManageNetworkUDPClient::getRunning() const
{
  return (_serv);
}

bool			ManageNetworkUDPClient::init()
{
  return (true);
}

bool			ManageNetworkUDPClient::selectIt()
{
  return (true);
}

std::vector<IUserNetwork *>	ManageNetworkUDPClient::exec()
{
  std::vector<IUserNetwork *>	newuser;

  if (_initServ == false || _serv->getStatus() == false)
    return (newuser);
  if (_serv->haveSomethingToWrite() == true)
    _serv->writeSocket(_net);
  _serv->readSocket(_net);
  if (_serv->getStatus() == true && _serv->haveSomethingToRead())
    {
      PacketUnknown pk = _serv->popBufferRead();
      _read->push(PacketC(pk, _serv));
      std::cout << "un packet est lu" << std::endl;
      _serv->pushBufferWrite(pk);
    }
  return (newuser);
}

bool		ManageNetworkUDPClient::run(const uint32_t &port, const uint32_t &maxCl)
{
#ifdef _WIN32
  try {
    _net = new SocketUDPWindows();
  }
  catch (AError const &e)
    {
      e.quit();
    }
#else
  try {
    _net = new SocketUDPUnix();
  }
  catch (AError const &e)
    {
      e.quit();
    }
#endif
  _init = true;
  if (maxCl != 0 && _net->bindIt(port) == false)
    return (false);
  return (true);
}

bool			ManageNetworkUDPClient::tryConnectClient(const uint32_t &port, const std::string &ip)
{
#ifdef _WIN32
  IUserNetwork *u = new UserNetworkUDPWindowsClient();
#else
  IUserNetwork *u = new UserNetworkUDPUnixClient();
#endif
  u->setFd(_net->getFdSocket());
  u->setIp(ip);
  u->setPort(port);
  u->setStatus(true);
  int	i = 0;
  while (i < 40)
    {
      u->pushBufferWrite(_factory->getPacket("ping")->getPacketUnknown());
      i++;
    }
  _serv = u;
  // _user.push_back(u);
  _initServ = true;
  std::cout << "Client UDP connected, IP: " << _serv->getIp() << " port: " << _serv->getPort() << std::endl;
  return (true);
}

void		ManageNetworkUDPClient::pushTo(const std::vector<std::string> &s, const PacketUnknown &m)
{
  if (_initServ == true)
    {
      (void)s;
      uint32_t		i = 0;
      while (i < _user.size())
	{
	  if (_user[i] == _serv)
	    _serv->pushBufferWrite(m);
	  i++;
	}
    }
}
