//
// Manager.hh for Manager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Fri Dec 16 11:46:19 2016 lecoq
//

#ifndef MANAGER_HH_
# define MANAGER_HH_

# include	"IManager.hh"
# include	"ManageNetworkTCP.hh"
# include	"ManageNetworkUDP.hh"

using namespace Network;
using namespace Error;

class Manager : public IManager
{
public:
  Manager();
  ~Manager();
  void                  setManager();
  IManageNetwork        *getNetworkTCPManager() const;
  IManageNetwork        *getNetworkUDPManager() const;
  void                  deleteManager();
private:
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  bool			_isSet;
};

#endif /* !MANAGER_HH_ */
