#include	"ManageNetworkTCP.hh"

using namespace Network;

ManageNetworkTCP::ManageNetworkTCP()
{
  _initServ = false;
  _serv = NULL;
}

ManageNetworkTCP::~ManageNetworkTCP()
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

bool			ManageNetworkTCP::init()
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
		{
			std::cout << "init write: " << _user[i]->getFd() << std::endl;
			FD_SET(_user[i]->getFd(), &fd_write);
		}
		i++;
	}
	return (true);
}

bool			ManageNetworkTCP::selectIt()
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

std::vector<IUserNetwork *>	ManageNetworkTCP::execClient()
{
  std::vector<IUserNetwork *>	newuser;
  int32_t			i;
  int32_t			add;
  
  i = 0;
  add = 0;
  while (i < (int32_t)_user.size() - add)
    {
      if (_user[i]->getStatus() == true)
	if (FD_ISSET(_user[i]->getFd(), &fd_read))
	  {
	    _user[i]->readSocket(_net);
	    if (_user[i]->getStatus() == true && _user[i]->haveSomethingToRead() == true)
	      {
		PacketUnknown pk = _user[i]->popBufferRead();
		_read->push(PacketC(pk, _user[i]));
		std::cout << "un packet est lu" << std::endl;
	      }
	  }
      if (_user[i]->getStatus() == true)
	if (FD_ISSET(_user[i]->getFd(), &fd_write))
	  _user[i]->writeSocket(_net);
      i++;
    }
  return (newuser);
}

std::vector<IUserNetwork *>	ManageNetworkTCP::execServer()
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
		u->pushBufferWrite(_factory->getPacket("welcome", WELCOME_SERVERM)->getPacketUnknown());
		std::cout << "new client tcp" << std::endl;
		newuser.push_back(u);
	      }
	    else
	      if (_user[i]->getStatus() == true && _user[i]->haveSomethingToRead() == true)
		{
		  PacketUnknown pk = _user[i]->popBufferRead();
		  _read->push(PacketC(pk, _user[i]));
		  std::cout << "un packet est lu" << std::endl;
		}
	  }
      if (_user[i]->getStatus() == true)
	if (FD_ISSET(_user[i]->getFd(), &fd_write))
	  _user[i]->writeSocket(_net);
      i++;
    }
  return (newuser);
}

bool		ManageNetworkTCP::run()
{
#ifdef _WIN32
  try {
    _net = new SocketTCPWindowsClient();
  }
  catch (AError const &e)
    {
      e.quit();
    }
#else
  try {
    _net = new SocketTCPUnixClient();
  }
  catch (AError const &e)
    {
      e.quit();
    }
#endif
  _init = true;
  _sec = 0;
  _usec = 2;
  return (true);
}

bool		ManageNetworkTCP::run(const uint32_t &port, const uint32_t &maxCl)
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

bool			ManageNetworkTCP::tryConnectClient(const uint32_t &port, const std::string &ip)
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

void		ManageNetworkTCP::pushToServ(const PacketUnknown &m)
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
	else
	  std::cout << "Not connected to server!" << std::endl;
}
