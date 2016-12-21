//
// CoreServer.cpp for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Wed Dec 21 18:38:51 2016 lecoq
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
}

CoreServer::~CoreServer() {}

void CoreServer::run()
{
  bool	loop;

  loop = true;
  while (loop == true)
    {
      _tcp->init();
      _udp->init();
      if (_tcp->selectIt() == false || _udp->selectIt() == false)
	loop = false;
      else
	{
	  _data->logout(_tcp->updateUsers(_tcp->exec()));
	  _udp->updateUsers(_udp->exec());
	}
      if (managePackets() == false)
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
	(this->*_packetPtr[packet->getType()])(packet, tmp.getNetwork());
    }
  if (_data->roomAreUpdate() == true)
    {
      IPacket *pa = _factory->getPacket("rooms", _data->getRooms());
      _tcp->pushTo(_data->getOnlineClients(), pa->getPacketUnknown());
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
   delete _manager;
   _isInit = false;
}

bool		CoreServer::connect(const IPacket *pa, IUserNetwork *u)
{
  PacketConnect	*p = (PacketConnect *)pa;
  PacketConnect	ck;

  //std::cout << _factory->isEnableSerialise("error") << " " << _factory->isEnableSerialise("accept") << std::endl;
  if (p->getCode() != ck.getCode())
    {
      IPacket       *co = _factory->getPacket("error", ERROR_CONNECT, IPacket::PacketType::CONNECT);
      PacketC       ret(co->getPacketUnknown(), u);
      _write->push(ret);
    }
  else
    {
      IPacket       *co = _factory->getPacket("accept", ACCEPT_MESSAGE);
      PacketC       ret(co->getPacketUnknown(), u);
      _write->push(ret);
    }
  return (true);
}

bool		CoreServer::login(const IPacket *pa, IUserNetwork *u)
{
  PacketLogin	*p = (PacketLogin *)pa;
  PacketC	c;

  c.setNetwork(u);
  if (_data->loginPlayer(p->getLogin(), p->getPassword()) == false &&
      _data->registerPlayer(p->getLogin(), p->getPassword()) == false)
    {
      if (p->getLogin().empty() == true || p->getPassword().empty() == true)
	c.setPacket(_factory->getPacket("error", LOGIN_EMPTY, IPacket::PacketType::LOGIN)->getPacketUnknown());
      else
	c.setPacket(_factory->getPacket("error", WRONG_AUTHENTIFICATION, IPacket::PacketType::LOGIN)->getPacketUnknown());
    }
  else
    {
      DataPlayer *data = _data->getPlayer(p->getLogin());
      PacketC	c2(_factory->getPacket("profile", data)->getPacketUnknown(), u);

      _write->push(c2);
      c.setPacket(_factory->getPacket("rooms", _data->getRooms())->getPacketUnknown());
      u->setPseudo(p->getLogin());
    }
  _write->push(c);
  return (true);
}

bool		CoreServer::createRoom(const IPacket *pa, IUserNetwork *u)
{
  PacketCreateRoom *p = (PacketCreateRoom *)pa;
  
  if (_data->createRoom(p->getGameName(), p->getMaxPlayers(), u->getPseudo()) == false)
    {
      IPacket *pac = _factory->getPacket("error", ERROR_CREATE_ROOM, IPacket::PacketType::CREATE_ROOM);
      PacketC c(pac->getPacketUnknown(), u);
      _write->push(c);
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

bool				CoreServer::startGame(const IPacket *pa, IUserNetwork *u)
{
  std::vector<std::string>	playersName;
  IUserNetwork			*runU;
  PacketStartGame		*p = (PacketStartGame *)pa;
  IPacket			*pb;
  DataRoom			*room = _data->getRoom(p->getGameName());
  uint8_t			*ip;

  if (room == NULL)
    {
      IPacket *pac = _factory->getPacket("error", ERROR_START_GAME, IPacket::PacketType::START_GAME);
      PacketC c(pac->getPacketUnknown(), u);
      _write->push(c);
    }
  else
    {
      if ((runU = _tcp->getRunning()) == NULL)
	{
	  std::cout << "error" << std::endl;
	  return (true);
	}
      if ((ip = calculIp(u->getIp())) == NULL)
      	return (false);
      if ((pb = _factory->getPacket("udpdata", ip, (uint16_t)runU->getPort())) == NULL)
	std::cout << "error factory" << std::endl;
      uint64_t		i = 0;
      while (i < room->getPlayers().size())
	{
	  playersName.push_back(room->getPlayers()[i]->getName());
	  i++;
	}
      i = 0;
      while (i < room->getWatchers().size())
	{
	  playersName.push_back(room->getWatchers()[i]->getName());
	  i++;
	}
      _tcp->pushTo(playersName, pb->getPacketUnknown());
    }
  return (true);
}

bool		CoreServer::udpData(const IPacket *pa, IUserNetwork *u)
{
  PacketUdpData                         *p = (PacketUdpData *)pa;
  Convert<uint8_t>                      conv;
  std::string                           ip;
#ifdef _WIN32
  IUserNetwork				*udpUser = new UserNetworkUDPWindows();
#else
  IUserNetwork				*udpUser = new UserNetworkUDPUnix();
#endif

  ip = conv.toString(p->getIp()[0]) + ".";
  ip += conv.toString(p->getIp()[1]) + ".";
  ip += conv.toString(p->getIp()[2]) + ".";
  ip += conv.toString(p->getIp()[3]);
  //std::cout << "udpData recu ip : " << ip << " port : " << p->getPort() << std::endl;
  //std::cout << "tcpIP: " << u->getIp() << std::endl;
  udpUser->setFd(_udp->getSocket()->getFdSocket());
  udpUser->setIp(u->getIp());
  udpUser->setPort(p->getPort());
  udpUser->setPseudo(u->getPseudo());
  udpUser->setStatus(true);
  
  udpUser->pushBufferWrite(_factory->getPacket("positionpacket", 5, 5)->getPacketUnknown());
  _udp->pushNewUser(udpUser);
  return (true);
}
