//
// ManagerServer.cpp for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:53:17 2016 Maxime Lecoq
// Last update Fri Dec 16 14:55:35 2016 lecoq
//

# include	"ManagerClient.hh"

ManagerClient::ManagerClient() : _isSet(false) {}

ManagerClient::~ManagerClient() {}

void	ManagerClient::setManager()
{
  if (_isSet == false)
    {
      _isSet = true;
      _man = new Manager;
      _tcp = _man->getNetworkTCPManager();
      if (_tcp->run() == false)
	throw ErrorClient("Error to run client tcp network's");
      _udp = _man->getNetworkUDPManager();
      if (_udp->run() == false)
	throw ErrorClient("Error to run client udp network's");
      _gui = new GUI;
      _sound = new SoundManager;
      _pkt = new ManagerPacketClient;
      _eventQueue = new EventQueue;
    }
}

IManageNetwork		*ManagerClient::getNetworkTCPManager() const
{
  return (_tcp);
}

IManageNetwork		*ManagerClient::getNetworkUDPManager() const
{
  return (_udp);
}

void			ManagerClient::deleteManager()
{
  if (_isSet == true)
    {
      _isSet = false;
      _man->deleteManager();
      delete _eventQueue;
      delete _pkt;
      delete _man;
      delete _sound;
      delete _gui;
    }
}

IPacketManager		*ManagerClient::getPacketManager() const
{
  return (_pkt);
}

IGUI			*ManagerClient::getGUI() const
{
  return (_gui);
}

ISoundManager		*ManagerClient::getSoundManager() const
{
  return (_sound);
}

IEventQueue		*ManagerClient::getEventQueue() const
{
  return (_eventQueue);
}
