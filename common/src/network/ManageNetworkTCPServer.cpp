#include	"ManageNetworkTCPServer.hh"

using namespace Network;

ManageNetworkTCPServer::ManageNetworkTCPServer() : AManageNetworkTCP()
{
  _initServ = false;
  _serv = NULL;
  _sec = 2;
  _usec = 0;
}

ManageNetworkTCPServer::~ManageNetworkTCPServer()
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

IUserNetwork                    *ManageNetworkTCPServer::getRunning() const
{
  unsigned int                  i;

  i = 0;
  while (i < _user.size())
    {
      if (_user[i]->getFd() == _net->getFdSocket())
  	return (_user[i]);
      i++;
    }
  return (NULL);
}

std::vector<std::string>        ManageNetworkTCPServer::updateUsers(const std::vector<IUserNetwork *> &user)
{
  uint32_t                      i = 0;
  std::vector<std::string>      del;

  while (i < _user.size())
    {
      if (_user[i]->getStatus() == false)
	{
	  if (_user[i] == _serv)
	    _initServ = false;
	  if (_user[i]->getPseudo().empty() != true)
	    del.push_back(_user[i]->getPseudo());
	  delete (_user[i]);
	  _user.erase(_user.begin() + i);
	}
      else
	i++;
    }
  i = 0;
  while (i < user.size())
    {
      if (user[i]->getStatus() == true)
	_user.push_back(user[i]);
      i++;
    }
  return (del);
  }

bool			ManageNetworkTCPServer::init()
{
  uint32_t		i;

  FD_ZERO(&fd_read);
  FD_ZERO(&fd_write);
  i = 0;
  while (_write->isEmpty() == false)
    {
      PacketC	tmp = _write->pop();
      tmp.getNetwork()->pushBufferWrite(tmp.getPacket());
    }
  i = 0;
  while (i < _user.size())
    {
      FD_SET(_user[i]->getFd(), &fd_read);
      if (_user[i]->haveSomethingToWrite() == true)
	FD_SET(_user[i]->getFd(), &fd_write);
      i++;
    }
  return (true);
}

bool			ManageNetworkTCPServer::selectIt()
{
  struct timeval	timeout;
  uint32_t		err;
  
  timeout.tv_sec = _sec;
  timeout.tv_usec = _usec;
  if (getMaxFd() != 0)
    {
      err = select(getMaxFd(), &fd_read, &fd_write, NULL, &timeout);
      if ((uint32_t)err == (uint32_t)-1)
	{
	  std::cerr << "Error on select(): " << err << std::endl;
	  return (false);
	}
    }
  return (true);
}

std::vector<IUserNetwork *>	ManageNetworkTCPServer::exec()
{
  std::vector<IUserNetwork *>	newuser;
  IUserNetwork			*u;
  int32_t			i;
  
  i = 0;
  while (i < (int32_t)_user.size())
    {
      if (_user[i]->getStatus() == true)
	if (FD_ISSET(_user[i]->getFd(), &fd_read))
	  {
	    u = _user[i]->readSocket(_net);
	    if (u != NULL && u->getFd() != _user[i]->getFd() && u->getStatus() == true)
	      {
		IPacket	*tmp = _factory->getPacket("welcome", WELCOME_SERVERM);
		u->pushBufferWrite(tmp->getPacketUnknown());
		newuser.push_back(u);
		delete tmp;
	      }
	    else
	      while (_user[i]->getStatus() == true && _user[i]->haveSomethingToRead() == true)
		{
		  PacketUnknown pk = _user[i]->popBufferRead();
		  _read->push(PacketC(pk, _user[i]));
		}
	  }
      if (_user[i]->getStatus() == true)
	if (FD_ISSET(_user[i]->getFd(), &fd_write))
	  _user[i]->writeSocket(_net);
      i++;
    }
  return (newuser);
}

bool		ManageNetworkTCPServer::run(const uint32_t &port, const uint32_t &maxCl)
{
  try {
#ifdef _WIN32
    _net = new SocketTCPWindows();
#else
    _net = new SocketTCPUnix();
#endif
    _init = true;
  }
  catch (AError const &e)
    {
      e.quit();
    }
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
  u->setIp(_net->getIpInfo());
  u->setStatus(true);
  std::cout << "Server TCP prepared, IP serveur: " << u->getIp() << std::endl;
  _user.push_back(u);
  return (true);
}

void		ManageNetworkTCPServer::pushTo(const std::vector<std::string> &list, const PacketUnknown &p)
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
