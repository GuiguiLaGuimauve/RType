#include	"ManageNetwork.hh"

using namespace Network;

ManageNetwork::ManageNetwork() : _port(4242), _init(false), _initServ(false)
{
	_serv = NULL;
}

ManageNetwork::~ManageNetwork()
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

bool			ManageNetwork::init()
{
  uint32_t		i;

	FD_ZERO(&fd_read);
	FD_ZERO(&fd_write);
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

bool			ManageNetwork::select_it()
{
  struct timeval	timeout;
	uint32_t		err;

	timeout.tv_sec = 2;
	timeout.tv_usec = 0;
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

std::vector<IUserNetwork *>	ManageNetwork::execClient()
{
	std::vector<IUserNetwork *>	newuser;
	int32_t						i;
	int32_t						add;

	i = 0;
	add = 0;
	while (i < (int32_t)_user.size() - add)
	{
		if (_user[i]->getStatus() == true)
			if (FD_ISSET(_user[i]->getFd(), &fd_read))
			{
				_user[i]->readSocket(_net);
				if (_user[i]->haveSomethingToRead() == true)
					std::cout << "READ: " << _user[i]->popBufferRead() << std::endl;
			}
		if (_user[i]->getStatus() == true)
			if (FD_ISSET(_user[i]->getFd(), &fd_write))
				_user[i]->writeSocket(_net);
		i++;
	}
	return (newuser);
}

std::vector<IUserNetwork *>	ManageNetwork::execServer()
{
	std::vector<IUserNetwork *>	newuser;
	IUserNetwork				*u;
	int32_t						i;

	i = 0;
	while (i < (int32_t)_user.size())
	  {
		  if (_user[i]->getStatus() == true)
			  if (FD_ISSET(_user[i]->getFd(), &fd_read))
			  {
				  u = _user[i]->readSocket(_net);
				  if (u != NULL && u->getFd() != _user[i]->getFd() && u->getStatus() == true)
				  {
					  std::cout << "adding newClient in newUser" << std::endl;
					  u->pushBufferWrite("WELCOME ON SERVER");
					  std::cout << "newUser size: " << newuser.size() << std::endl;
					  newuser.push_back(u);
					  std::cout << "newUser size2: " << newuser.size() << std::endl;
				  }
				  else
					  if (_user[i]->getStatus() == true && _user[i]->haveSomethingToRead() == true)
						  std::cout << "READ: " << _user[i]->popBufferRead() << std::endl;
			  }
		  if (_user[i]->getStatus() == true)
			  if (FD_ISSET(_user[i]->getFd(), &fd_write))
				  _user[i]->writeSocket(_net);
		  i++;
	}
	return (newuser);
}

uint32_t			ManageNetwork::getMaxFd() const
{
  if (_user.size() != 0)
    {
      uint32_t			i;
      uint32_t			res;

      i = 0;
      res = _user[i]->getFd();
      while (i < _user.size())
	{
	  if (res < (uint32_t)_user[i]->getFd())
	    res = _user[i]->getFd();
	  i++;
	}
      return (res + 1);
    }
  else
    return (0);
}

bool		ManageNetwork::run()
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
  return (true);
}

bool		ManageNetwork::run(const uint32_t &port, const uint32_t &maxCl)
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

bool			ManageNetwork::tryConnectClient(const uint32_t &port, const std::string &ip)
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

ISocket		*ManageNetwork::getSocket() const
{
  return (_net);
}

void			ManageNetwork::updateUsers(std::vector<IUserNetwork *> user)
{
	uint32_t	i = 0;
//	std::cout << "Update users:\nnewUser size: " << user.size() << std::endl;
//	std::cout << "_user size: " << _user.size() << std::endl;
	while (i < _user.size())
	{
		if (_user[i]->getStatus() == false)
		{
			std::cout << "Erase client from list: " << _user[i]->getFd() << std::endl;
			//delete (_user[i]);
			_user.erase(_user.begin() + i);
		}
		else
			i++;
	}
	i = 0;
	while (i < user.size())
	{
		if (user[i]->getStatus() == true)
		{
			std::cout << "New user in list: " << user[i]->getFd() << std::endl;
			_user.push_back(user[i]);
		}
		i++;
	}
}

void		ManageNetwork::pushToServ(const std::string &m)
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
