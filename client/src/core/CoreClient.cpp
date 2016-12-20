//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Tue Dec 20 02:10:45 2016 lecoq
//

#include	"CoreClient.hh"

CoreClient::CoreClient()
{
  _manager = new ManagerClient;
  _isInit = false;
  _eventPtr[EventPart::Event::QUIT] = &CoreClient::quit;
  _eventPtr[EventPart::Event::TRY_CONNECT] = &CoreClient::tryConnect;
  _eventPtr[EventPart::Event::TRY_LOGIN] = &CoreClient::tryLogin;
  _packetPtr[IPacket::PacketType::WELCOME] = &CoreClient::welcome;
  _packetPtr[IPacket::PacketType::ACCEPT] = &CoreClient::accept;
  _packetPtr[IPacket::PacketType::ERROR_PACKET] = &CoreClient::errorPacket;
  _packetPtr[IPacket::PacketType::ROOMS] = &CoreClient::rooms;
  _isConnectToServ = false;
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

bool	CoreClient::manageNetwork()
{
  _tcp->init();
  _udp->init();
  if (_tcp->selectIt() == false || _udp->selectIt() == false)
    return(false);
  else
    {
      _tcp->updateUsers(_tcp->execServer());
      _udp->updateUsers(_udp->execServer());
    }
  if (_isConnectToServ == true && _tcp->hasServerRunning() == false)
    {
      _gui->displayStart();
      _isConnectToServ = false;
    }
  return (true);
}

bool	CoreClient::managePackets()
{
  while (_read->isEmpty() == false)
    {
      PacketC tmp = _read->pop();
      std::cout << (int)tmp.getPacket().getPacketData()[0] << std::endl;
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
  if (e.dataString["LOGIN"].empty() == true || e.dataString["PWD"].empty() == true)
    _gui->showPopup(LOGIN_ERROR);
  else
    {
      IPacket *pa = _factory->getPacket("login", e.dataString["LOGIN"], e.dataString["PWD"]);
      _tcp->pushToServ(pa->getPacketUnknown());
    }
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
  PacketWelcome	*p = (PacketWelcome *)pa;
  IPacket	*co = _factory->getPacket("connect");
  PacketC	ret(co->getPacketUnknown(), u);

  std::cout << p->getMessage() << std::endl;
  _write->push(ret);
  return (true);
}

bool		CoreClient::accept(const IPacket *pa, IUserNetwork *u)
{
  PacketAccept	*p = (PacketAccept *)pa;

  std::cout << p->getMessage() << std::endl;
  _gui->displayLogin();
  _isConnectToServ = true;
  (void)u;
  return (true);
}

bool		CoreClient::rooms(const IPacket *pa, IUserNetwork *u)
{
  PacketRooms	*p = (PacketRooms *)pa;

  _gui->setRooms(p->getRooms());
  _gui->displayMenu();
  (void)u;
  return (true);
}
