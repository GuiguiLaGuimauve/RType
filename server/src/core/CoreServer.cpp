//
// CoreServer.cpp for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Tue Dec 27 17:54:19 2016 lecoq
//

#include	"CoreServer.hh"

CoreServer::CoreServer()
{
  _manager = new ManagerServer;
  _isInit = false;
  _packetPtr[IPacket::PacketType::CONNECT] = &CoreServer::connect;
  _packetPtr[IPacket::PacketType::LOGIN] = &CoreServer::login;
  _packetPtr[IPacket::PacketType::CREATE_ROOM] = &CoreServer::createRoom;
  _packetPtr[IPacket::PacketType::LEAVE_ROOM] = &CoreServer::leaveRoom;
  _packetPtr[IPacket::PacketType::JOIN_ROOM] = &CoreServer::joinRoom;
  _packetPtr[IPacket::PacketType::WATCH_GAME] = &CoreServer::watchGame;
  _packetPtr[IPacket::PacketType::START_GAME] = &CoreServer::startGame;
  _packetPtr[IPacket::PacketType::UDP_DATA] = &CoreServer::udpData;
  _packetPtr[IPacket::PacketType::PING] = &CoreServer::ping;
  _packetPtr[IPacket::PacketType::PONG] = &CoreServer::pong;
  _packetPtr[IPacket::PacketType::ASK_ROOMS] = &CoreServer::askRooms;
  _packetPtr[IPacket::PacketType::POSITION_PLAYER] = &CoreServer::game;
  _threadPool = new ThreadPool;
}

CoreServer::~CoreServer() {
  delete _threadPool;
  delete _manager;
}

void				CoreServer::run()
{
  bool				loop;
  std::vector<IUserNetwork *>	delUsers;
  std::vector<std::string>	delUsersName;
  uint32_t			i;

  loop = true;
  while (loop == true)
    {
      _tcp->init();
      _udp->init();
      if (_tcp->selectIt() == false || _udp->selectIt() == false)
	loop = false;
      else
	{
	  delUsersName = _tcp->updateUsers(_tcp->exec());
	  i = 0;
	  while (i < delUsersName.size())
	    {
#ifdef _WIN32
	      IUserNetwork	*tmp = new UserNetworkUDPWindowsServer();
#else
	      IUserNetwork	*tmp = new UserNetworkUDPUnixServer();
#endif
	      tmp->setPseudo(delUsersName[i]);
	      delUsers.push_back(tmp);
	      i++;
	    }
	  _data->logout(delUsersName);
	  _udp->updateUsers(delUsers);
	  _udp->exec();
	}
      if (managePackets() == false || _gameManager->gamesUpdate() == false)
	loop = false;
    }
}

bool	CoreServer::managePackets()
{
  while (_read->isEmpty() == false)
    {
      PacketC tmp = _read->pop();
      IPacket *packet = _factory->getPacket(tmp.getPacket().getPacketData());
      if (packet != NULL && _packetPtr.find(packet->getType()) != _packetPtr.end())
	{
	  (this->*_packetPtr[packet->getType()])(packet, tmp.getNetwork());
	  delete packet;
	}
    }
  if (_data->roomAreUpdate() == true)
    {
      IPacket *pa = _factory->getPacket("rooms", _data->getRooms());
      _tcp->pushTo(_data->getOnlineClients(), pa->getPacketUnknown());
      delete pa;
    }
  return (true);
}

bool	CoreServer::initManager()
{
     try
     {
       if (_isInit == false)
	 _manager->setManager();
       _isInit = true;
       _pkt = _manager->getPacketManager();
       _tcp = _manager->getNetworkTCPManager();
       _udp = _manager->getNetworkUDPManager();
       _gameManager = _manager->getGameManager();
       _read = _pkt->getPacketQueueRead();
       _write = _pkt->getPacketQueueWrite();
       _factory = _pkt->getPacketFactory();
       _tcp->setPacketQueueRead(_read);
       _tcp->setPacketQueueWrite(_write);
       _tcp->setPacketFactory(_factory);
       _udp->setPacketQueueRead(_read);
       _udp->setPacketQueueWrite(_write);
       _udp->setPacketFactory(_factory);
       _data = _manager->getServerData();
       _gameManager->setFactory(_factory);
       _gameManager->setThreadPool(_threadPool);
     }
   catch (AError const &e)
     {
       e.error();
       return (false);
     }
   return (true);
}

void CoreServer::deleteManager()
{
 if (_isInit == true)
   _manager->deleteManager();
 _isInit = false;
}

bool		CoreServer::connect(const IPacket *pa, IUserNetwork *u)
{
  PacketConnect	*p = (PacketConnect *)pa;
  PacketConnect	ck;
  IPacket	*co;
  
  if (p->getCode() != ck.getCode())
    {
      co = _factory->getPacket("error", ERROR_CONNECT, IPacket::PacketType::CONNECT);
      PacketC       ret(co->getPacketUnknown(), u);
      _write->push(ret);
    }
  else
    {
      co = _factory->getPacket("accept", ACCEPT_MESSAGE);
      PacketC       ret(co->getPacketUnknown(), u);
      _write->push(ret);
    }
  delete co;
  return (true);
}

bool		CoreServer::login(const IPacket *pa, IUserNetwork *u)
{
  PacketLogin	*p = (PacketLogin *)pa;
  PacketC	c;
  IPacket	*pkt;
  
  c.setNetwork(u);
  if (_data->loginPlayer(p->getLogin(), p->getPassword()) == false &&
      _data->registerPlayer(p->getLogin(), p->getPassword()) == false)
    {
      if (p->getLogin().empty() == true || p->getPassword().empty() == true)
	{
	  pkt = _factory->getPacket("error", LOGIN_EMPTY, IPacket::PacketType::LOGIN);
	  c.setPacket(pkt->getPacketUnknown());
	}
      else
	{
	  pkt = _factory->getPacket("error", WRONG_AUTHENTIFICATION, IPacket::PacketType::LOGIN);
	  c.setPacket(pkt->getPacketUnknown());
	}
    }
  else
    {
      DataPlayer *data = _data->getPlayer(p->getLogin());
      pkt = _factory->getPacket("profile", data);
      PacketC	c2(pkt->getPacketUnknown(), u);

      _write->push(c2);
      delete pkt;
      pkt = _factory->getPacket("rooms", _data->getRooms());
      c.setPacket(pkt->getPacketUnknown());
      u->setPseudo(p->getLogin());
    }
  _write->push(c);
  delete pkt;
  return (true);
}

bool		CoreServer::createRoom(const IPacket *pa, IUserNetwork *u)
{
  PacketCreateRoom *p = (PacketCreateRoom *)pa;
  
  std::cout << "create room : " << p->getGameName() << " | " << p->getMaxPlayers() << std::endl;
  if (_data->createRoom(p->getGameName(), p->getMaxPlayers(), u->getPseudo()) == false)
    {
      IPacket *pac = _factory->getPacket("error", ERROR_CREATE_ROOM, IPacket::PacketType::CREATE_ROOM);
      PacketC c(pac->getPacketUnknown(), u);
      _write->push(c);
      delete pac;
    }
  return (true);
}

bool		CoreServer::leaveRoom(const IPacket *pa, IUserNetwork *u)
{
  PacketLeaveRoom *p = (PacketLeaveRoom *)pa;
  
  _data->leaveRoom(p->getGameName(), u->getPseudo());
  return (true);
}

bool		CoreServer::joinRoom(const IPacket *pa, IUserNetwork *u)
{
  PacketJoinRoom *p = (PacketJoinRoom *)pa;

  _data->joinRoom(p->getGameName(), u->getPseudo());
  return (true);
}

bool		CoreServer::watchGame(const IPacket *pa, IUserNetwork *u)
{
  PacketWatchGame *p = (PacketWatchGame *)pa;

  _data->watchGame(p->getGameName(), u->getPseudo());
  return (true);
}

void CoreServer::createGame(DataRoom *r, const uint8_t *ip)
{
  _gameManager->createGame(r, ip);
}

bool				CoreServer::startGame(const IPacket *pa, IUserNetwork *u)
{
  std::vector<std::string>	playersName;
  PacketStartGame		*p = (PacketStartGame *)pa;
  DataRoom			*room = _data->getRoom(p->getGameName());
  uint8_t			*ip;

  if (room == NULL)
    {
      IPacket *pac = _factory->getPacket("error", ERROR_START_GAME, IPacket::PacketType::START_GAME);
      PacketC c(pac->getPacketUnknown(), u);
      _write->push(c);
      delete pac;
    }
  else
    {
      room->setStarted(true);
      if ((ip = calculIp(u->getIp())) != NULL)
	_threadPool->launchTask(&CoreServer::createGame, this, room, ip);
    }
  return (true);
}

bool		CoreServer::udpData(const IPacket *pa, IUserNetwork *u)
{
  PacketUdpData                         *p = (PacketUdpData *)pa;
  Convert<uint8_t>                      conv;
  std::string                           ip;
#ifdef _WIN32
  IUserNetwork				*udpUser = new UserNetworkUDPWindowsServer();
#else
  IUserNetwork				*udpUser = new UserNetworkUDPUnixServer();
#endif
  std::cout << "[UDP_DATA]" << std::endl;
  ip = conv.toString(p->getIp()[0]) + ".";
  ip += conv.toString(p->getIp()[1]) + ".";
  ip += conv.toString(p->getIp()[2]) + ".";
  ip += conv.toString(p->getIp()[3]);
  udpUser->setFd(_udp->getSocket()->getFdSocket());
  udpUser->setIp(u->getIp());
  udpUser->setPort(p->getPort());
  udpUser->setPseudo(u->getPseudo());
  udpUser->setStatus(true);
  int	i = 0;
  while (i < 40)
    {
      udpUser->pushBufferWrite(_factory->getPacket("ping")->getPacketUnknown());
      i++;
    }
  _udp->pushNewUser(udpUser);
  _tcp->setTimeout(0, 2);
  std::cout << "[UDP User] --> [" << udpUser->getIp() << "] [" << udpUser->getPort() << "]" << std::endl;
  return (true);
}

bool		CoreServer::ping(const IPacket *pa, IUserNetwork *u)
{
  IPacket       *p = new PacketPong;
  _write->push(PacketC(p->getPacketUnknown(), u));
  delete p;
  std::cout << "ping recu et pong envoyé" << std::endl; 
  (void)u;
  (void)pa;
  return (true);
}

bool            CoreServer::pong(const IPacket *pa, IUserNetwork *u)
{
  (void)pa; (void)u;
  std::cout << "pong recu" << std::endl;
  return (true);
}

bool            CoreServer::askRooms(const IPacket *pa, IUserNetwork *u)
{
  if (_data->playerExist(u->getPseudo()) == true)
    {
      DataPlayer *data = _data->getPlayer(u->getPseudo());
      pkt = _factory->getPacket("profile", data);
      PacketC	c2(pkt->getPacketUnknown(), u);
      PacketC	c;
      
      _write->push(c2);
      delete pkt;
      pkt = _factory->getPacket("rooms", _data->getRooms());
      c.setPacket(pkt->getPacketUnknown());
      c.setNetwork(u);
      _write->push(c);
      delete pkt;
    }
  return (true);
}

bool		CoreServer::game(const IPacket *pa, IUserNetwork *u)
{
  return (_gameManager->execPacket(pa, u->getPseudo()));
}

