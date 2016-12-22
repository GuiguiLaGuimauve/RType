//
// ManagerServer.cpp for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:53:17 2016 Maxime Lecoq
// Last update Thu Dec 22 11:07:36 2016 julien dufrene
//

# include	"ManagerClient.hh"

ManagerClient::ManagerClient() : _isSet(false) {}

ManagerClient::~ManagerClient() {}

void	ManagerClient::setManager()
{
  if (_isSet == false)
    {
      _isSet = true;
      _tcp = new ManageNetworkTCPClient();
      if (_tcp->run(4243) == false)
  	throw ErrorClient("Error to run client tcp network's");
      _udp = new ManageNetworkUDPClient();
      if (_udp->run(4243) == false)
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
      delete _tcp;
      delete _udp;
      delete _eventQueue;
      delete _pkt;
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
