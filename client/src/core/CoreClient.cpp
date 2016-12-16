//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Fri Dec 16 15:19:22 2016 lecoq
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

void	CoreClient::run()
{
  bool	loop;

  loop = true;
  while (loop == true)
    {
      if (manageGui() == false || manageNetwork() == false)
	loop = false;
    }
}

bool	CoreClient::manageGui()
{
  _gui->callback();
  while (_eventQueue->empty() == false)
    {
      EventPart::Event e = _eventQueue->pop();
      std::cout << e.type << std::endl;
    }
  return (true);
}

bool	CoreClient::manageNetwork()
{
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
