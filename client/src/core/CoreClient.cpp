//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Fri Dec 23 00:41:11 2016 julien dufrene
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
  _packetPtr[IPacket::PacketType::WELCOME] = &CoreClient::welcome;
  _packetPtr[IPacket::PacketType::ACCEPT] = &CoreClient::accept;
  _packetPtr[IPacket::PacketType::ERROR_PACKET] = &CoreClient::errorPacket;
  _packetPtr[IPacket::PacketType::ROOMS] = &CoreClient::rooms;
  _packetPtr[IPacket::PacketType::PROFILE] = &CoreClient::profile;
  _packetPtr[IPacket::PacketType::UDP_DATA] = &CoreClient::udpData;
  _packetPtr[IPacket::PacketType::PING] = &CoreClient::ping;
  _status = "connect";
  _backPtr["connect"] = &CoreClient::exitClient;
  _backPtr["login"] = &CoreClient::goConnect;
  _backPtr["rooms"] = &CoreClient::goLogin;
  _backPtr["game"] = &CoreClient::goRooms;
}

CoreClient::~CoreClient()
{
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
	  IUserNetwork      *tmp = new UserNetworkUDPUnix();
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
    }
  return (true);
}

bool	CoreClient::managePackets()
{
  while (_read->isEmpty() == false)
    {
      PacketC tmp = _read->pop();
      //std::cout << (int)tmp.getPacket().getPacketData()[0] << std::endl;
      IPacket *packet = _factory->getPacket(tmp.getPacket().getPacketData());
      if (packet != NULL && _packetPtr.find(packet->getType()) != _packetPtr.end())
	(this->*_packetPtr[packet->getType()])(packet, tmp.getNetwork());
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
   delete _manager;
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

std::string rmname;

bool	CoreClient::tryLogin(EventPart::Event e)
{
  std::vector<std::string> p;
  if (e.dataString["LOGIN"].empty() == true || e.dataString["PWD"].empty() == true)
    _gui->showPopup(LOGIN_ERROR);
  else
    {
      IPacket *pa = _factory->getPacket("login", e.dataString["LOGIN"], e.dataString["PWD"]);
      _tcp->pushTo(p, pa->getPacketUnknown());
      rmname = e.dataString["LOGIN"] + " room's";
    }
  return (true);
}


bool	CoreClient::createGame(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("createroom", rmname, 4);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  (void)e;
  return (true);
}

bool	CoreClient::leaveRoom(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("leaveroom", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  return (true);
}

bool	CoreClient::joinRoom(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("joinroom", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  return (true);
}

bool	CoreClient::watchRoom(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("watchgame", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  return (true);
}

bool	CoreClient::startGame(EventPart::Event e)
{
  IPacket *pa = _factory->getPacket("startgame", e.dataString["GAME_NAME"]);
  std::vector<std::string> p;
  _tcp->pushTo(p, pa->getPacketUnknown());
  return (true);
}

bool		CoreClient::errorPacket(const IPacket *pa, IUserNetwork *u)
{
  PacketError	*p = (PacketError *)pa;
  
  _gui->showPopup(p->getMessage());
  (void)u;
  return (true);
}

bool		CoreClient::welcome(const IPacket *pa, IUserNetwork *u)
{
  // PacketWelcome	*p = (PacketWelcome *)pa;
  IPacket	*co = _factory->getPacket("connect");
  PacketC	ret(co->getPacketUnknown(), u);
  (void)pa;
  //std::cout << p->getMessage() << std::endl;
  _write->push(ret);
  return (true);
}

bool		CoreClient::accept(const IPacket *pa, IUserNetwork *u)
{
  // PacketAccept	*p = (PacketAccept *)pa;

  //std::cout << p->getMessage() << std::endl;
  _gui->displayLogin();
  _status = "login";
  (void)u;(void)pa;
  return (true);
}

bool		CoreClient::rooms(const IPacket *pa, IUserNetwork *u)
{
  PacketRooms	*p = (PacketRooms *)pa;

  if (_status == "login")
    _gui->displayMenu();
  _gui->setRooms(p->getRooms());
  _status = "rooms";
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


/* je reçoit un [UDP_DATA] <-- tryconnect --> [IP du server TCP] [PORT du packet] */
/* j'envoie un [UDP DATA] [IP du server TCP] [PORT du packet] */
bool		CoreClient::udpData(const IPacket *pa, IUserNetwork *u)
{
  IPacket				*pb;
  PacketUdpData				*p = (PacketUdpData *)pa;
  Convert<uint8_t>			conv;
  std::vector<std::string>		empty;
  std::string				ip;

  std::cout << "[UDP_DATA]" << std::endl;
  ip = conv.toString(p->getIp()[0]) + ".";
  ip += conv.toString(p->getIp()[1]) + ".";
  ip += conv.toString(p->getIp()[2]) + ".";
  ip += conv.toString(p->getIp()[3]);
  _udp->tryConnectClient(p->getPort(), _tcp->getRunning()->getIp());
  pb = _factory->getPacket("udpdata", calculIp(_tcp->getRunning()->getIp()), (uint16_t)4244);
  _tcp->pushTo(empty, pb->getPacketUnknown());
  _tcp->setTimeout(0, 0);
  std::cout << "[UDP SERVER] ---> [" << _tcp->getRunning()->getIp() << "] [" << p->getPort() << "]" << std::endl;
  (void)u;
  return (true);
}

bool		CoreClient::ping(const IPacket *pa, IUserNetwork *u)
{
  (void)pa; (void)u;
  std::cout << "ping" << std::endl;
  return (true);
}
