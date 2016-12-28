//
// ManageNetworkUDP.cpp for ManageNetworkUDP.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:37:09 2016 julien dufrene
// Last update Wed Dec 28 19:33:14 2016 lecoq
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
  while (_serv->haveSomethingToWrite() == true)
    _serv->writeSocket(_net);
  _serv->readSocket(_net);
  while (_serv->getStatus() == true && _serv->haveSomethingToRead())
    {
      PacketUnknown pk = _serv->popBufferRead();
      _read->push(PacketC(pk, _serv));
      std::cout << "un packet est lu" << std::endl;
      _serv->pushBufferWrite(pk);
    }
  /*  if (_serv->getStatus() == true)
    {
      IUserNetwork                                  *u;
      #ifdef _WIN32
      u = new UserNetworkUDPWindowsServer();
              #else
      u = new UserNetworkUDPUnixServer();
              #endif
      u->setIp("0.0.0.0");
      u->setFd(_net->getFdSocket());
      u->setPseudo("Accept");
      u = u->readSocket(_net);
      while (u->haveSomethingToRead() == true)
	{
	  PacketUnknown pk = u->popBufferRead();
	  _read->push(PacketC(pk, u));
	  std::cout << "un packet est lu" << std::endl;
	  if (_serv->getIp() == u->getIp())
	    {
	      while (_serv->haveSomethingToWrite() == true)
		u->pushBufferWrite(_serv->popBufferWrite());
	      _serv = u;
	    }
	  std::cout << "Server send me something" << std::endl;
	}
	}*/
  return (newuser);
}

bool		ManageNetworkUDPClient::run(const uint32_t &port, const uint32_t &maxCl)
{
  try {
#ifdef _WIN32
    _net = new SocketUDPWindows();
#else
    _net = new SocketUDPUnix();
#endif
  }
  catch (AError const &e)
    {
      e.quit();
    }
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
  u->setPseudo("Accept");
  _serv = u;
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
