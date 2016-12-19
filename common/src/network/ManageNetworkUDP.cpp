//
// ManageNetworkUDP.cpp for ManageNetworkUDP.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:37:09 2016 julien dufrene
// Last update Tue Dec 20 00:47:25 2016 julien dufrene
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

bool			ManageNetworkUDP::selectIt()
{
  return (true);
}

std::vector<IUserNetwork *>	ManageNetworkUDP::execClient()
{
  std::vector<IUserNetwork *>	newuser;
  IUserNetwork			*u;

  if (_initServ == false || _serv->getStatus() == false)
    return (newuser);
  u = _serv->readSocket(_net);
  if (u != NULL && u != _serv && u->getStatus() == true)
    {
      //      u->pushBufferWrite("WELCOME ON UDP SERVER");
      newuser.push_back(u);
    }
  else
    if (_serv->getStatus() == true && _serv->haveSomethingToRead())
      {
	std::cout << "READ: " << std::endl;
      }
  if (_serv->getStatus() == true && _serv->haveSomethingToWrite() == true)
    _serv->writeSocket(_net);
  return (newuser);
}

std::vector<IUserNetwork *>	ManageNetworkUDP::execServer()
{
  std::vector<IUserNetwork *>	newuser;
  IUserNetwork			*u;
  int				i;

  i = 0;
  while (i < (int32_t)_user.size())
    {
      u = _user[i]->readSocket(_net);
      if (_user[i]->getIp() != u->getIp())
	{
	  std::cout << "new client udp" << std::endl;
	  if (u->haveSomethingToRead() == true)
	    {
	      PacketUnknown pk = u->popBufferRead();
	      _read->push(PacketC(pk, u));
	      std::cout << "un packet est lu" << std::endl;
	    }
	  newuser.push_back(u);
	}
      else
	if (_user[i]->haveSomethingToRead() == true)
	  {
	    PacketUnknown pk = _user[i]->popBufferRead();
	    _read->push(PacketC(pk, _user[i]));
	    std::cout << "un packet est lu" << std::endl;
	  }
      if (_user[i]->haveSomethingToWrite() == true)
	_user[i]->writeSocket(_net);
    }
  return (newuser);
}

bool		ManageNetworkUDP::run()
{
  return (false);
}

bool		ManageNetworkUDP::run(const uint32_t &port, const uint32_t &maxCl)
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
  /*
#ifdef _WIN32
    IUserNetwork *u = new UserNetworkUDPWindows();
#else
  IUserNetwork *u = new UserNetworkUDPUnix();
#endif // _WIN32
  (void)maxCl;
  u->setFd(_net->getFdSocket());
  u->setPort(port);
  u->setStatus(true);
  _user.push_back(u);*/
  std::cout << "User Network UDP prepared: " << _net->getFdSocket() << std::endl;
  return (true);
}

bool			ManageNetworkUDP::tryConnectClient(const uint32_t &port, const std::string &ip)
{
#ifdef _WIN32
  IUserNetwork *u = new UserNetworkUDPWindows();
#else
  IUserNetwork *u = new UserNetworkUDPUnix();
#endif
  u->setFd(_net->getFdSocket());
  u->setIp(ip);
  u->setPort(port);
  u->setStatus(true);
  _serv = u;
  _user.push_back(u);
  _initServ = true;
  std::cout << "User Network Client UDP connected: " << _serv->getFd() << std::endl;
  return (true);
}

void		ManageNetworkUDP::pushToServ(const PacketUnknown &m)
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
