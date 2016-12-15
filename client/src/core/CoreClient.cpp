//
// CoreClient.cpp for CoreClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:38:54 2016 Maxime Lecoq
// Last update Thu Dec 15 14:49:09 2016 Simon BERTHO
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
  while (1)
    {
      gui.callback();
      while (!_eventQueue.empty())
        {
          auto e = _eventQueue.pop();
          switch (e.type)
            {
            case EventPart::Event::QUIT :
              return ;
            case EventPart::Event::ATTACK :
              {
                break ;
              }
            case EventPart::Event::MOVE_UP :
              {
                break ;
              }
            case EventPart::Event::MOVE_DOWN :
              {
                break ;
              }
            case EventPart::Event::MOVE_RIGHT :
              {
                break ;
              }
            case EventPart::Event::MOVE_LEFT :
              {
                break ;
              }
            case EventPart::Event::TRY_CONNECT :
              {
                break ;
              }
            case EventPart::Event::TRY_LOGIN :
              {
                break ;
              }
            case EventPart::Event::CREATE_GAME :
              {
                break ;
              }
            case EventPart::Event::JOIN_GAME :
              {
                break ;
              }
	    case EventPart::Event::DEFAULT :
              {
                break ;
              }
            default :
              {
		std::cout << "Event inconnu! " << std::endl;
              }
            }
	}
    }
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
