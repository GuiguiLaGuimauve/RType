//
// ManagerServer.cpp for ManagerServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:53:17 2016 Maxime Lecoq
// Last update Thu Dec 15 15:37:45 2016 lecoq
//

# include	"ManagerServer.hh"

ManagerServer::ManagerServer() : _isSet(false) {}

ManagerServer::~ManagerServer() {}

void	ManagerServer::setManager()
{
  if (_isSet == false)
    {
      _isSet = true;
      _man = new Manager;
      _tcp = _man->getNetworkTCPManager();
      _udp = _man->getNetworkUDPManager();
      _game = new GameManager;
      _pkt = new ManagePacketServer;
    }
}

IManageNetwork		*ManagerServer::getNetworkTCPManager() const
{
  return (_tcp);
}

IManageNetwork		*ManagerServer::getNetworkUDPManager() const
{
  return (_udp);
}

void			ManagerServer::deleteManager()
{
  if (_isSet == true)
    {
      _isSet = false;
      _man->deleteManager();
    }
}

IGameManager		*ManagerServer::getGameManager() const
{
  return (_game);
}

IPacketManager		*ManagerServer::getPacketManager() const
{
  return (_pkt);
}

