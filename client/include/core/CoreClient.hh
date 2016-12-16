//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Fri Dec 16 15:17:04 2016 lecoq
//

#ifndef CORECLIENT_HH_
# define CORECLIENT_HH_

# include	"ACore.hh"
# include	"ManagerClient.hh"
# include	"EventQueue.hh"

using namespace Gui;
using namespace Gui::Audio;
using namespace Network;
using namespace Error;
using namespace EventPart;

class CoreClient : public ACore
{
  public:
  CoreClient();
  ~CoreClient();
  void		run();
  bool		initManager();
  void		deleteManager();
private:
  bool		manageGui();
  bool		manageNetwork();
private:
  IManagerClient	*_manager;
  IGUI			*_gui;
  ISoundManager		*_sound;
  IEventQueue		*_eventQueue;
};

#endif /* !CORECLIENT_HH_ */
