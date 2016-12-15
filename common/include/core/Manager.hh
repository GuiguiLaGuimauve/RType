//
// Manager.hh for Manager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Thu Dec 15 10:40:54 2016 lecoq
//

#ifndef MANAGER_HH_
# define MANAGER_HH_

# include "IManager.hh"

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
