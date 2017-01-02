//
// ManagerClient.hh for ManagerClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Wed Dec 21 02:00:04 2016 julien dufrene
//

#ifndef MANAGERPCLIENT_HH_
# define MANAGERPCLIENT_HH_

# include	"IManagerClient.hh"
# include	"IPacketManager.hh"
# include	"ManageNetworkTCPClient.hh"
# include	"ManageNetworkUDPClient.hh"
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
  IEventQueue		*getEventQueue() const;
private:
  IGUI			*_gui;
  ISoundManager		*_sound;
  IPacketManager	*_pkt;
  bool			_isSet;
  IManageNetwork	*_tcp;
  IManageNetwork	*_udp;
  IEventQueue		*_eventQueue;
};

#endif /* !MANAGER_HH_ */
