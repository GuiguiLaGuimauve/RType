//
// CoreServer.cpp for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Mon Dec 19 12:17:53 2016 julien dufrene
//

#include	"CoreServer.hh"

CoreServer::CoreServer()
{
  _manager = new ManagerServer;
  _isInit = false;
  _packetPtr[IPacket::PacketType::CONNECT] = &CoreServer::connect;
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
	  _tcp->updateUsers(_tcp->execServer());
	  _udp->updateUsers(_udp->execServer());
	}
      if (managePackets() == false)
	loop = false;
    }
}

bool	CoreServer::managePackets()
{
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
  IPacket	*co = _factory->getPacket("error packet");
  PacketC	ret(co->getPacketUnknown(), u);
  _write->push(ret);
  return (true);
}
