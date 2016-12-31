//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Sat Dec 31 08:43:07 2016 Lecoq Maxime
//

#include	"CoreClient.hh"

CoreClient::CoreClient()
{
  _manager = new ManagerClient;
  _isInit = false;
  _eventPtr[EventPart::Event::QUIT] = &CoreClient::quit;
  _eventPtr[EventPart::Event::TRY_CONNECT] = &CoreClient::tryConnect;
  _eventPtr[EventPart::Event::TRY_LOGIN] = &CoreClient::tryLogin;
  _eventPtr[EventPart::Event::CREATE_GAME] = &CoreClient::createGame;
  _eventPtr[EventPart::Event::LEAVE_GAME] = &CoreClient::leaveRoom;
  _eventPtr[EventPart::Event::JOIN_GAME] = &CoreClient::joinRoom;
  _eventPtr[EventPart::Event::WATCH_GAME] = &CoreClient::watchRoom;
  _eventPtr[EventPart::Event::START_GAME] = &CoreClient::startGame;
  _eventPtr[EventPart::Event::ATTACK] = &CoreClient::shoot;
  _packetPtr[IPacket::PacketType::WELCOME] = &CoreClient::welcome;
  _packetPtr[IPacket::PacketType::ACCEPT] = &CoreClient::accept;
  _packetPtr[IPacket::PacketType::ERROR_PACKET] = &CoreClient::errorPacket;
  _packetPtr[IPacket::PacketType::ROOMS] = &CoreClient::rooms;
  _packetPtr[IPacket::PacketType::PROFILE] = &CoreClient::profile;
  _packetPtr[IPacket::PacketType::UDP_DATA] = &CoreClient::udpData;
  _packetPtr[IPacket::PacketType::PING] = &CoreClient::ping;
  _packetPtr[IPacket::PacketType::PONG] = &CoreClient::pong;
  _packetPtr[IPacket::PacketType::POSITION_PLAYER] = &CoreClient::positionPlayer;
  _packetPtr[IPacket::PacketType::PLAYERS] = &CoreClient::players;
  _packetPtr[IPacket::PacketType::SHOOTS] = &CoreClient::shoots;
  _packetPtr[IPacket::PacketType::GAMEENDED] = &CoreClient::gameEnded;
  _status = "connect";
  _backPtr["connect"] = &CoreClient::exitClient;
  _backPtr["login"] = &CoreClient::goConnect;
  _backPtr["rooms"] = &CoreClient::goLogin;
  _backPtr["game"] = &CoreClient::goRooms;
  _gameData = new GameData;
  _th = new Thread;
}

CoreClient::~CoreClient()
{
  _gameData->endGame();
  if (_th->joinable())
    _th->join();
  delete _gameData;
  delete _manager;
  delete _th;
}

void	CoreClient::run()
{
  bool	loop;

  loop = true;
  _gui->displayStart();
  while (loop == true)
    {
      if (manageGui() == false || manageNetwork() == false || managePackets() == false)
	loop = false;
    }
}

bool	CoreClient::manageGui()
{
  _gui->callback();
  while (_eventQueue->empty() == false)
    {
      EventPart::Event e = _eventQueue->pop();
      if (_eventPtr.find(e.type) != _eventPtr.end() && ((this->*_eventPtr[e.type])(e)) == false)
	return (false);
    }
  return (true);
}

bool				CoreClient::manageNetwork()
{
  std::vector<std::string>	delUsersName;
  std::vector<IUserNetwork *>	delUsers;
  uint64_t			i;

  _tcp->init();
  _udp->init();
  if (_tcp->selectIt() == false || _udp->selectIt() == false)
    return(false);
  else
    {
      delUsersName = _tcp->updateUsers(_tcp->exec());
      i = 0;
      while (i < delUsersName.size())
	{
#ifdef _WIN32
	  IUserNetwork      *tmp = new UserNetworkUDPWindowsClient();
#else
	  IUserNetwork      *tmp = new UserNetworkUDPUnixClient();
#endif
	  tmp->setPseudo(delUsersName[i]);
	  delUsers.push_back(tmp);
	  i++;
	}
      _udp->exec();
      _udp->updateUsers(delUsers);
    }
  if (_status != "connect" && _tcp->hasServerRunning() == false)
    {
      _gui->displayStart();
      _tcp->run(4242);
      _status = "connect";
      _gameData->endGame();
      if (_th->joinable())
	_th->join();
    }
  return (true);
}

bool	CoreClient::managePackets()
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
  return (true);
}

bool	CoreClient::initManager()
{
  try
    {
      if (_isInit == false)
	_manager->setManager();
      _isInit = true;
      _pkt = _manager->getPacketManager();
      _tcp = _manager->getNetworkTCPManager();
      _udp = _manager->getNetworkUDPManager();
      _gui = _manager->getGUI();
      _sound = _manager->getSoundManager();
      _eventQueue = _manager->getEventQueue();
      _gui->setEventQueue(_eventQueue);
      _gui->setSoundManager(_sound);
      _read = _pkt->getPacketQueueRead();
      _write = _pkt->getPacketQueueWrite();
      _factory = _pkt->getPacketFactory();
      _tcp->setPacketQueueRead(_read);
      _tcp->setPacketQueueWrite(_write);
      _tcp->setPacketFactory(_factory);
      _udp->setPacketQueueRead(_read);
      _udp->setPacketQueueWrite(_write);
      _udp->setPacketFactory(_factory);
    }
  catch (AError const &e)
    {
      e.error();
      return (false);
    }
  return (true);
}

void CoreClient::deleteManager()
{
  _sound->stopMusic();
  if (_isInit == true)
    _manager->deleteManager();
  _isInit = false;
}

bool	CoreClient::exitClient()
{
  return (false);
}

bool	CoreClient::goConnect()
{
  _gui->displayStart();
  _tcp->run(4242);
  _status = "connect";  
  return (true);
}

bool	CoreClient::goLogin()
{  
  return (true);
}

bool	CoreClient::goRooms()
{  
  return (true);
}

bool	CoreClient::quit(EventPart::Event e)
{
  (void)e;
  return (false);
}

bool	CoreClient::tryConnect(EventPart::Event e)
{
  std::string             port;
  Convert<int32_t>        conv;
  Convert<uint32_t>       conv2;
  uint64_t                i;
  std::vector<std::string>        ip;
  Vector          vec;
  StringCk                strCk;


  port = e.dataString["PORT"];
  ip = vec.getVector(e.dataString["IP"], '.');  
  if (ip.size() != 4)
    {
      _gui->showPopup(IP_FORMAT_ERROR);
      return (true);
    }
  if (strCk.isNumber(port) == false || conv.toNumber(port) < 1024)
    {
      _gui->showPopup(PORT_FORMAT_ERROR);
      return (true);
    }
  i = 0;
  while (i < ip.size())
    {
      if (strCk.isNumber(ip[i]) == false || conv.toNumber(ip[i]) < 0 \
	  || conv.toNumber(ip[i]) > 255)
	{
	  _gui->showPopup(IP_FORMAT_ERROR);
	  return (true);
	}
      i++;
      }
  if (_tcp->tryConnectClient(conv.toNumber(e.dataString["PORT"]), e.dataString["IP"]) == false)
    _gui->showPopup("Connection failed", 2000);
  return (true);
}

bool	CoreClient::tryLogin(EventPart::Event e)
{
  std::vector<std::string> p;
  if (e.dataString["LOGIN"].empty() == true || e.dataString["PWD"].empty() == true)
    _gui->showPopup(LOGIN_ERROR);
  else
    {
      IPacket *pa = _factory->getPacket("login", e.dataString["LOGIN"], e.dataString["PWD"]);
      _tcp->pushTo(p, pa->getPacketUnknown());
      delete pa;
    }
  return (true);
}


bool	CoreClient::createGame(EventPart::Event e)
{
  Convert<uint8_t>	conv;
  IPacket		*pa = _factory->getPacket("createroom", e.dataString["GAME_NAME"], e.dataInt["MAX_PLAYER"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  delete pa;
  (void)e;
  std::cout << "create room : " << e.dataString["GAME_NAME"] << " | " << e.dataInt["MAX_PLAYER"] << std::endl;
  return (true);
}

bool	CoreClient::leaveRoom(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("leaveroom", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  delete pa;
  return (true);
}

bool	CoreClient::joinRoom(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("joinroom", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  delete pa;
  return (true);
}

bool	CoreClient::watchRoom(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("watchgame", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  delete pa;
  return (true);
}

bool	CoreClient::startGame(EventPart::Event e)
{
  if (_status == "rooms")
    {
      IPacket *pa = _factory->getPacket("startgame", e.dataString["GAME_NAME"]);
      std::vector<std::string> p;
      _tcp->pushTo(p, pa->getPacketUnknown());
      delete pa;
      _status = "waitGame";
    }
  return (true);
}

bool	CoreClient::shoot(EventPart::Event e)
{
  _gameData->addShoot(e.dataInt["X"], e.dataInt["Y"]);
  return (true);
}

bool		CoreClient::errorPacket(const IPacket *pa, IUserNetwork *u)
{
  PacketError	*p = (PacketError *)pa;
  
  _gui->showPopup(p->getMessage());
  if (p->getErrorType() == IPacket::PacketType::START_GAME)
    _status = "rooms";
  (void)u;
  return (true);
}

bool		CoreClient::welcome(const IPacket *pa, IUserNetwork *u)
{
  PacketWelcome	*p = (PacketWelcome *)pa;
  IPacket	*co = _factory->getPacket("connect");
  PacketC	ret(co->getPacketUnknown(), u);
  (void)pa;
  std::cout << p->getMessage() << std::endl;
  _write->push(ret);
  delete co;
  return (true);
}

bool		CoreClient::accept(const IPacket *pa, IUserNetwork *u)
{
  PacketAccept	*p = (PacketAccept *)pa;

  std::cout << p->getMessage() << std::endl;
  _gui->displayLogin();
  _status = "waitingRooms";
  (void)u;(void)pa;
  return (true);
}

bool		CoreClient::rooms(const IPacket *pa, IUserNetwork *u)
{
  PacketRooms	*p = (PacketRooms *)pa;

  if (_status == "waitingRooms")
    _gui->displayMenu();
  if (_status == "waitingRooms" || _status == "rooms")
    {
      _gui->setRooms(p->getRooms());
      _status = "rooms";
    }
  (void)u;
  return (true);
}

bool		CoreClient::profile(const IPacket *pa, IUserNetwork *u)
{
  PacketProfile	*p = (PacketProfile *)pa;

  _gui->setProfile(p->getPlayer());
  (void)u;
  return (true);
}


bool		CoreClient::udpData(const IPacket *pa, IUserNetwork *u)
{
  IPacket				*pb;
  PacketUdpData				*p = (PacketUdpData *)pa;
  Convert<uint8_t>			conv;
  std::vector<std::string>		empty;
  std::string				ip;
  Thread				th;

  std::cout << "[UDP_DATA]" << std::endl;
  ip = conv.toString(p->getIp()[0]) + ".";
  ip += conv.toString(p->getIp()[1]) + ".";
  ip += conv.toString(p->getIp()[2]) + ".";
  ip += conv.toString(p->getIp()[3]);
  _udp->tryConnectClient(p->getPort(), _tcp->getRunning()->getIp());
  pb = _factory->getPacket("udpdata", calculIp(_tcp->getRunning()->getIp()), (uint16_t)p->getPort());
  _tcp->pushTo(empty, pb->getPacketUnknown());
  _tcp->setTimeout(0, 2);
  std::cout << "[UDP SERVER] ---> [" << _tcp->getRunning()->getIp() << "] [" << p->getPort() << "]" << std::endl;
  (void)u;
  delete pb;
  _status = "game";
  _gui->displayGame();
  _gameData->init();
  _game = p->getStatus();
  _th->launch(&CoreClient::timeLine, this);
  pb = _factory->getPacket("ping");
  uint8_t i = 0;
  while (i < 5)
    {
      _udp->pushTo(empty, pb->getPacketUnknown());
      i++;
    }
  delete pb;
  return (true);
}

void		CoreClient::timeLine()
{
  Clock		clo;
  std::vector<std::string> empty;
  
  while (_gameData->gameIsEnded() == false)
    {
      if (_game == "player" && _gameData->getTick() != (uint32_t)(clo.getTimeMilli() / 50))
	{
	  _gameData->setTick(clo.getTimeMilli() / 50);
	  IPacket *p;
	  p = _factory->getPacket("positionplayer", _gui->getPosX(), _gui->getPosY());
	  p->setTickId(_gameData->getTick());
	  _udp->pushTo(empty, p->getPacketUnknown());
	  delete p;
	  p = _factory->getPacket("shoots", _gameData->getShoots());
	  p->setTickId(_gameData->getTick());
	  _udp->pushTo(empty, p->getPacketUnknown());
	  delete p;
	}
    }
}

bool		CoreClient::ping(const IPacket *pa, IUserNetwork *u)
{
  IPacket	*p = new PacketPong;
  _write->push(PacketC(p->getPacketUnknown(), u));
  delete p;
  std::cout << "ping recu et pong envoyé" << std::endl;
  (void)pa;
  return (true);
}

bool		CoreClient::pong(const IPacket *pa, IUserNetwork *u)
{
  (void)pa; (void)u;
  std::cout << "pong recu" << std::endl;
  return (true);
}

bool		CoreClient::positionPlayer(const IPacket *pa, IUserNetwork *u)
{
  PacketPositionPlayer *p = (PacketPositionPlayer *)pa;

  (void)u;
  (void)p;
  _gui->setPosX(p->getX());
  _gui->setPosY(p->getY());
  return (true);
}

bool		CoreClient::players(const IPacket *pa, IUserNetwork *u)
{
  PacketPlayers	*p = (PacketPlayers *)pa;
  (void)u;
  (void)p;
  //  _gameData->setMarge(pa->getTickId() - _gameData->getTick());
  //if (pa->getTickId() == _gameData->getTick() || pa->getTickId() - _gameData->getTick() == 1)
  _gui->setPlayersPositions(p->getPlayers());
  return (true);
}

bool		CoreClient::shoots(const IPacket *pa, IUserNetwork *u)
{
  PacketShoots	*p = (PacketShoots *)pa;
  (void)u;
  (void)p;
  //_gameData->setMarge(pa->getTickId() - _gameData->getTick());
  //  if (pa->getTickId() == _gameData->getTick() || pa->getTickId() - _gameData->getTick() == 1)
  _gui->setShootsPositions(p->getShoots());
  return (true);
}

bool		CoreClient::gameEnded(const IPacket *pa, IUserNetwork *u)
{
  (void)pa; (void)u;
  IPacket *p;

  p = _factory->getPacket("askrooms");
  _write->push(PacketC(p->getPacketUnknown(), u));
  delete p;
  _gameData->reset();
  _status = "waitingRooms";
  _game = "";
  return (true);
}
