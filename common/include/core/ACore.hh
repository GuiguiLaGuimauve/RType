//
// ICore.hh for ICore in /home/lecoq_m/RType/build
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:12:15 2016 Maxime Lecoq
// Last update Wed Dec 21 08:32:53 2016 julien dufrene
//

#ifndef ACORE_HH_
# define ACORE_HH_

# include "ICore.hh"
# include "IPacketManager.hh"
# include "IManageNetwork.hh"
# include "Vector.hh"

class ACore : public ICore
{
public:
  ACore() {};
  virtual ~ACore() {};
  virtual void run() = 0;
  virtual bool initManager() = 0;
  virtual void deleteManager() = 0;
protected:
uint8_t         *calculIp(const std::string &_ip) const
  {
    Convert<uint8_t>              c;
    Convert<int32_t>              conv;
    StringCk                      strCk;
    uint64_t                      i;
    uint8_t                       *ret = new uint8_t[4];
    std::vector<std::string>      ip;
    Vector                        vec;

    ip = vec.getVector(_ip, '.');
    if (ip.size() != 4)
      return (NULL);
    i = 0;
    while (i < ip.size())
      {
	if (strCk.isNumber(ip[i]) == false || conv.toNumber(ip[i]) < 0	\
	    || conv.toNumber(ip[i]) > 255)
	  {
	    return (NULL);
	  }
	i++;
      }
    ret[0] = c.toNumber(ip[0]);
    ret[1] = c.toNumber(ip[1]);
    ret[2] = c.toNumber(ip[2]);
    ret[3] = c.toNumber(ip[3]);
    return (ret);
  }
  IPacketManager	*_pkt;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  bool			_isInit;
  IPacketQueue          *_read;
  IPacketQueue          *_write;
  PacketFactory         *_factory;
};

#endif /* !ICORE_HH_ */
