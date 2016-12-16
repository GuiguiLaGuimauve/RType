//
// Manager.cpp for Manager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:53:17 2016 Maxime Lecoq
// Last update Fri Dec 16 11:46:38 2016 lecoq
//

# include	"Manager.hh"

Manager::Manager() : _isSet(false) {}

Manager::~Manager() {}

void	Manager::setManager()
{
  if (_isSet == false)
    {
      _isSet = true;
      _tcp = new ManageNetworkTCP;
      _udp = new ManageNetworkUDP;
    }
}

IManageNetwork		*Manager::getNetworkTCPManager() const
{
  return (_tcp);
}

IManageNetwork		*Manager::getNetworkUDPManager() const
{
  return (_udp);
}

void			Manager::deleteManager()
{
  if (_isSet == true)
    {
      _isSet = false;
      delete _tcp;
      delete _udp;
    }
}
