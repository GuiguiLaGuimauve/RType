//
// ManagerServer.cpp for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:53:17 2016 Maxime Lecoq
// Last update Thu Dec 15 10:47:14 2016 lecoq
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
      _udp = _man->getNetworkUDPManager();
      _gui = new GUI;
      //maybe ou la logique c est nous qui le creons et qui le setons a la gui instant
      //_sound = _gui->getSoundManager();
      _pkt = new PacketManager;
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
