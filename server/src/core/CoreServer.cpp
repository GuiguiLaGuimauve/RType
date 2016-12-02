//
// CoreServer.cpp for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Fri Dec  2 15:40:31 2016 lecoq
//

CoreServer::CoreServer()
{
  _manager = new ManagerServer;
  _isInit = false;
}

CoreServer::~CoreServer()
{
}

void CoreServer::run()
{
}

void CoreServer::initManager()
{
   if (_isInit == false)
     _manager->setManager();
   _isInit = true;
   _pkt = _manager->getPacketManager();
   _tcp = _manager->getNetworkTCPManager();
   _udp = _manager->getNetworkUDPManager();
   _gameManager = _manager->getGameManager();
}

void CoreServer::deleteManager()
{
 if (_isInit == true)
   _manager->deleteManager();
   delete _manager;
}
