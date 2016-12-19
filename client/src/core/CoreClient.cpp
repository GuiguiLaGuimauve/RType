//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Mon Dec 19 11:12:32 2016 lecoq
//

#include	"CoreClient.hh"

CoreClient::CoreClient()
{
  _manager = new ManagerClient;
  _isInit = false;
  _eventPtr[EventPart::Event::QUIT] = &CoreClient::quit;
  _eventPtr[EventPart::Event::TRY_CONNECT] = &CoreClient::tryConnect;
  _packetPtr[IPacket::PacketType::WELCOME] = &CoreClient::welcome;
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
  Convert<uint32_t>	conv;

  if (_tcp->tryConnectClient(conv.toNumber(e.dataString["PORT"]), e.dataString["IP"]) == false)
    std::cout << "ploup" << std::endl;
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
