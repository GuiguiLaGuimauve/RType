#include	"ManageNetworkTCPClient.hh"

using namespace Network;

ManageNetworkTCPClient::ManageNetworkTCPClient() : AManageNetworkTCP()
{
  _initServ = false;
  _serv = NULL;
  _sec = 0;
  _usec = 1;
}

ManageNetworkTCPClient::~ManageNetworkTCPClient()
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

std::vector<std::string>        ManageNetworkTCPClient::updateUsers(const std::vector<IUserNetwork *> &user)
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

IUserNetwork		*ManageNetworkTCPClient::getRunning() const
{
  return (_serv);
}

bool			ManageNetworkTCPClient::init()
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

bool			ManageNetworkTCPClient::selectIt()
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
	  std::cerr << "Error on select(): " << errno << std::endl;
	  return (false);
	}
    }
  return (true);
}

std::vector<IUserNetwork *>	ManageNetworkTCPClient::exec()
{
  std::vector<IUserNetwork *>	newuser;
  int32_t			i;
  int32_t			add;
  
  i = 0;
  add = 0;
  if (_initServ == false)
    return (newuser);
  while (i < (int32_t)_user.size() - add)
    {
      if (_user[i]->getStatus() == true)
	{
	  if (FD_ISSET(_user[i]->getFd(), &fd_read))
	    {
	      _user[i]->readSocket(_net);
	      while (_user[i]->getStatus() == true && _user[i]->haveSomethingToRead() == true)
		{
		  PacketUnknown pk = _user[i]->popBufferRead();
		  _read->push(PacketC(pk, _user[i]));
		}
	    }
	}
      if (_user[i]->getStatus() == true)
	if (FD_ISSET(_user[i]->getFd(), &fd_write))
	  _user[i]->writeSocket(_net);
      i++;
    }
  if (_serv->getStatus() == false)
    {
      std::cerr << "[Error] Server Down" << std::endl;
      _initServ = false;
    }
  return (newuser);
}

bool		ManageNetworkTCPClient::run(const uint32_t &port, const uint32_t &maxCl)
{
  try {
#ifdef _WIN32
    _net = new SocketTCPWindowsClient();
#else
    _net = new SocketTCPUnixClient();
#endif
    _init = true;
    (void)port; (void)maxCl;
  }
 catch (AError const &e)
   {
    e.quit();
  }
  return (true);
}

bool			ManageNetworkTCPClient::tryConnectClient(const uint32_t &port, const std::string &ip)
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
  u->setPseudo("serveur");
  _serv = u;
  _user.push_back(u);
  _initServ = true;
  std::cout << "Client TCP connected, IP connect: " << _serv->getIp() << std::endl;
  return (true);
}

void		ManageNetworkTCPClient::pushTo(const std::vector<std::string> &s, const PacketUnknown &m)
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
  else
    std::cout << "Not connected to server!" << std::endl;
}

bool		ManageNetworkTCPClient::hasServerRunning() const
{
  return (_initServ);
}
