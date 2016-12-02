//
// ICore.hh for ICore in /home/lecoq_m/RType/build
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:12:15 2016 Maxime Lecoq
// Last update Fri Dec  2 15:35:12 2016 lecoq
//

#ifndef ACORE_HH_
# define ACORE_HH_

# include "ICore.hh"

class ACore : public ICore
{
public:
  ACore() {};
  virtual ~ACore() {};
  virtual void run() = 0;
  virtual void initManager() = 0;
  virtual void deleteManager() = 0;
protected:
  IManagePacket		*_pkt;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  bool			_isInit;
};

#endif /* !ICORE_HH_ */
