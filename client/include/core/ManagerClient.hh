//
// ManagerClient.hh for ManagerClient in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:50:05 2016 Maxime Lecoq
// Last update Thu Dec 15 15:20:19 2016 lecoq
//

#ifndef MANAGERPCLIENT_HH_
# define MANAGERPCLIENT_HH_

# include "IManagerClient.hh"
# include "IPacketManager.hh"

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
