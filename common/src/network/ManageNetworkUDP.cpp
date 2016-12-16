//
// ManageNetworkUDP.cpp for ManageNetworkUDP.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:37:09 2016 julien dufrene
// Last update Fri Dec 16 11:39:14 2016 julien dufrene
//

#include	"ManageNetworkUDP.hh"

using namespace Network;

ManageNetworkUDP::ManageNetworkUDP()
{
  _initServ = false;
  _serv = NULL;
}

ManageNetworkUDP::~ManageNetworkUDP()
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

bool			ManageNetworkUDP::init()
{
  return (true);
}

bool			ManageNetworkUDP::select_it()
{
  return (true);
}

std::vector<IUserNetwork *>	ManageNetworkUDP::execClient()
{
  std::vector<IUserNetwork *>	newuser;
  return (newuser);
}

std::vector<IUserNetwork *>	ManageNetworkUDP::execServer()
{
  std::vector<IUserNetwork *>	newuser;
  return (newuser);
}

bool		ManageNetworkUDP::run(const uint32_t &port, const uint32_t &maxCl)
{
#ifdef _WIN32
  try {
    _net = new SocketTCPWindows();
  }
  catch (AError const &e)
    {
      e.quit();
    }
#else
  try {
    _net = new SocketTCPUnix();
  }
  catch (AError const &e)
    {
      e.quit();
    }
#endif
  _init = true;
  if (_net->bindIt(port) == false
      || _net->listenIt(maxCl) == false)
    return (false);

#ifdef _WIN32
  IUserNetwork *u = new UserNetworkTCPWindowsServer();
#else
  IUserNetwork *u = new UserNetworkTCPUnixServer();
#endif // _WIN32

  u->setFd(_net->getFdSocket());
  u->setPort(port);
  u->setStatus(true);
  _user.push_back(u);
  std::cout << "User Network Server TCP prepared: " << _user[0]->getFd() << std::endl;
  return (true);
}

bool			ManageNetworkUDP::tryConnectClient(const uint32_t &port, const std::string &ip)
{
  if (_net->connectIt(ip, port) == false)
    return (false);
#ifdef _WIN32
  IUserNetwork *u = new UserNetworkTCPWindowsClient();
#else
  IUserNetwork *u = new UserNetworkTCPUnixClient();
#endif
  u->setFd(_net->getFdSocket());
  u->setIp(ip);
  u->setPort(port);
  u->setStatus(true);
  _serv = u;
  _user.push_back(u);
  _initServ = true;
  std::cout << "User Network Client TCP connected: " << _serv->getFd() << std::endl;
  return (true);
}

void		ManageNetworkUDP::pushToServ(const std::string &m)
{
	if (_initServ == true)
	{
		uint32_t		i = 0;
		while (i < _user.size())
		{
			if (_user[i] == _serv)
				_serv->pushBufferWrite(m);
			i++;
		}
	}
}
