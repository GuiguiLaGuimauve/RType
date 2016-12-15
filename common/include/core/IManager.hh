//
// IManager.hh for IManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:44:58 2016 Maxime Lecoq
// Last update Thu Dec 15 14:28:19 2016 lecoq
//

#ifndef IMANAGER_HH_
# define IMANAGER_HH_

# include "IManageNetwork.hh"

class IManager
{
public:
  virtual			~IManager() {};
  virtual void			setManager() = 0;
  virtual IManageNetwork	*getNetworkTCPManager() const = 0;
  virtual IManageNetwork	*getNetworkUDPManager() const = 0;
  virtual void			deleteManager() = 0;
};

#endif /* !IMANAGER_HH_ */
