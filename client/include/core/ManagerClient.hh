//
// ManagerClient.hh for ManagerClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Fri Dec 16 12:08:47 2016 lecoq
//

#ifndef MANAGERPCLIENT_HH_
# define MANAGERPCLIENT_HH_

# include	"IManagerClient.hh"
# include	"IPacketManager.hh"
# include	"ManageNetworkTCP.hh"
# include	"ManageNetworkUDP.hh"
# include	"ErrorClient.hpp"

using namespace Network;
using namespace Error;

class ManagerClient : public IManagerClient
{
public:
  ManagerClient();
  ~ManagerClient();
  void                  setManager();
  IManageNetwork        *getNetworkTCPManager() const;
  IManageNetwork        *getNetworkUDPManager() const;
  void                  deleteManager();
  IPacketManager	*getPacketManager() const;
  IGUI			*getGUI() const;
  ISoundManager		*getSoundManager() const;
private:
  IManager		*_man;
  IGUI			*_gui;
  ISoundManager		*_sound;
  IPacketManager	*_pkt;
  bool			_isSet;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
};

#endif /* !MANAGER_HH_ */
