//
// IManager.hh for IManager in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 15:44:58 2016 Maxime Lecoq
// Last update Thu Dec 15 15:26:23 2016 lecoq
//

#ifndef IMANAGERSERVER_HH_
# define IMANAGERSERVER_HH_

# include "Manager.hh"
# include "GUI.hh"
# include "SoundManager.hh"
# include "ManagerPacketClient.hh"

using namespace Gui;
using namespace Gui::Audio;

class IManagerClient : public IManager
{
public:
  virtual			~IManagerClient() {};
  virtual void			setManager() = 0;
  virtual IManageNetwork	*getNetworkTCPManager() const = 0;
  virtual IManageNetwork	*getNetworkUDPManager() const = 0;
  virtual void			deleteManager() = 0;
  virtual IPacketManager	*getPacketManager() const = 0;
  virtual IGUI			*getGUI() const = 0;
  virtual ISoundManager		*getSoundManager() const = 0;

};

#endif /* !IMANAGER_HH_ */
