//
// ManageNetworkUDP.cpp for ManageNetworkUDP.cpp in /home/dufren_b/teck3/rendu/CPP/RType/common/src/network
// 
// Made by julien dufrene
// Login   <dufren_b@epitech.net>
// 
// Started on  Fri Dec 16 11:37:09 2016 julien dufrene
// Last update Fri Dec 30 20:39:08 2016 Lecoq Maxime
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
	  if (_user[i]->getPseudo() == user[j]->getPseudo() && user[j]->getStatus() == false)
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
  IUserNetwork					*u;
  uint64_t						i;
  bool							ok;

  i = 0;
  while (i < _user.size())
    {
      if (_user[i]->getStatus() != false)
	{
	  while (_user[i]->haveSomethingToWrite() == true)
	    _user[i]->writeSocket(_net);
	}
      i++;
    }
  if (_user.size() > 0)
    {
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
	  i = 0;
	  ok = false;
	  while (i < _user.size() && ok == false)
	    {
	      if (_user[i]->getIp() == u->getIp())
		{
			if (_user[i]->getPseudo().compare("Accept") != 0 && u->getPseudo().compare("Accept") == 0)
				u->setPseudo(_user[i]->getPseudo());
		  while (_user[i]->haveSomethingToWrite() == true)
		    u->pushBufferWrite(_user[i]->popBufferWrite());
		  u->setPseudo(_user[i]->getPseudo());
		  _user[i] = u;
		  ok = true;
		}
	      i++;
	    }
	  if (ok == false)
		  _user.push_back(u);
	}
    }
  return (newuser);
}

bool		ManageNetworkUDPServer::run(const uint32_t &port, const uint32_t &maxCl)
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
  std::cout << "Server UDP prepared, IP: " << _net->getIpInfo() << " port: " << port << std::endl;
  return (true);
}

bool			ManageNetworkUDPServer::tryConnectClient(const uint32_t &port, const std::string &ip)
{
#ifdef _WIN32
  IUserNetwork *u = new UserNetworkUDPWindowsServer();
#else
  IUserNetwork *u = new UserNetworkUDPUnixServer();
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
  _mtx.lock();
  while (i < _user.size())
    {
      if (inList(_user[i]->getPseudo(), list) == true)
	_user[i]->pushBufferWrite(p);
      i++;
    }
  _mtx.unlock();
}
