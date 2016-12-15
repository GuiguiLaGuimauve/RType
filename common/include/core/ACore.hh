//
// ICore.hh for ICore in /home/lecoq_m/RType/build
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:12:15 2016 Maxime Lecoq
// Last update Thu Dec 15 15:09:35 2016 lecoq
//

#ifndef ACORE_HH_
# define ACORE_HH_

# include "ICore.hh"
# include "IPacketManager.hh"
# include "IManageNetwork.hh"

class ACore : public ICore
{
public:
  ACore() {};
  virtual ~ACore() {};
  virtual void run() = 0;
  virtual void initManager() = 0;
  virtual void deleteManager() = 0;
protected:
  IPacketManager		*_pkt;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  bool			_isInit;
};

#endif /* !ICORE_HH_ */
