//
// Manager.hh for Manager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Fri Dec 16 11:18:58 2016 lecoq
//

#ifndef MANAGER_HH_
# define MANAGER_HH_

# include	"IManager.hh"
# include	"ManageNetwork.hh"

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
