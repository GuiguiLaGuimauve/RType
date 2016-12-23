//
// ManageNetworkUDP.cpp for ManageNetworkUDP.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:37:09 2016 julien dufrene
// Last update Fri Dec 23 02:01:37 2016 julien dufrene
//

#include	"ManageNetworkUDPServer.hh"

using namespace Network;

ManageNetworkUDPServer::ManageNetworkUDPServer()
{
  _initServ = false;
  _serv = NULL;
}

ManageNetworkUDPServer::~ManageNetworkUDPServer()
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

IUserNetwork		*ManageNetworkUDPServer::getRunning() const
{
  unsigned int                  i;

  i = 0;
  while (i < _user.size())
    {
      if (_user[i]->getStatus() != false)
	if (_user[i]->getFd() == _net->getFdSocket())
	  return (_user[i]);
      i++;
    }
  return (NULL);
}

std::vector<std::string>        ManageNetworkUDPServer::updateUsers(const std::vector<IUserNetwork *> &user)
{
  uint32_t                      i = 0;
  uint32_t                      j = 0;
  std::vector<std::string>      del;

  while (j < user.size())
    {
      i = 0;
      while (i < _user.size())
	{
	  if (_user[i]->getPseudo() == user[j]->getPseudo())
	    {
	      if (_user[i] == _serv)
		_initServ = false;
	      if (_user[i]->getPseudo().empty() != true)
		del.push_back(_user[i]->getPseudo());
	      std::cout << "Erase client from UDP list: " << _user[i]->getFd() << std::endl;
	      delete (_user[i]);
	      _user.erase(_user.begin() + i);
	    }
	  else
	    i++;
	}
      j++;
    }
  return (del);
}

bool			ManageNetworkUDPServer::init()
{
  return (true);
}

bool			ManageNetworkUDPServer::selectIt()
{
  return (true);
}

std::vector<IUserNetwork *>	ManageNetworkUDPServer::exec()
{
  std::vector<IUserNetwork *>	newuser;
  int				i;

  i = 0;
  while (i < (int32_t)_user.size())
    {
      if (_user[i]->getStatus() != false)
	{
	  std::cout << "Have user: " << _user[i]->getIp() << ":" << _user[i]->getPort() << std::endl;
	  if (_user[i]->haveSomethingToWrite() == true)
	    _user[i]->writeSocket(_net);
	}
      i++;
    }
  if (_user.size() != 0)
    {
      _user[0]->readSocket(_net);
      if (_user[0]->getStatus() == true && _user[i]->haveSomethingToRead() == true)
	{
	  PacketUnknown pk = _user[i]->popBufferRead();
	  _read->push(PacketC(pk, _user[i]));
	  std::cout << "un packet est lu" << std::endl;
	  // _user[i]->pushBufferWrite(pk);
	}
    }
  return (newuser);
}

bool		ManageNetworkUDPServer::run(const uint32_t &port, const uint32_t &maxCl)
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
  std::cout << "Server UDP prepared, IP: " << _net->getIpInfo() << " port: " << port << std::endl;
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
  return (true);
}

bool			ManageNetworkUDPServer::tryConnectClient(const uint32_t &port, const std::string &ip)
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
  std::cout << "Server UDP connected, IP: " << _serv->getIp() << "port: " << port << std::endl;
  return (true);
}

void		ManageNetworkUDPServer::pushTo(const std::vector<std::string> &list, const PacketUnknown &p)
{
  uint64_t              i;

  i = 0;
  while (i < _user.size())
    {
      if (inList(_user[i]->getPseudo(), list) == true)
	_user[i]->pushBufferWrite(p);
      i++;
    }
}
