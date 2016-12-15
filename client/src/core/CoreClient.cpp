//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Thu Dec 15 14:35:26 2016 lecoq
//

#include	"CoreClient.hh"

CoreClient::CoreClient()
{
  _manager = new ManagerClient;
  _isInit = false;
}

CoreClient::~CoreClient()
{
}

void CoreClient::run()
{
}

void CoreClient::initManager()
{
   if (_isInit == false)
     _manager->setManager();
   _isInit = true;
   _pkt = _manager->getPacketManager();
   _tcp = _manager->getNetworkTCPManager();
   _udp = _manager->getNetworkUDPManager();
   _gui = _manager->getGUI();
   _sound = _manager->getSoundManager();
}

void CoreClient::deleteManager()
{
 if (_isInit == true)
   _manager->deleteManager();
   delete _manager;
   _isInit = false;
}
