//
// CoreServer.hh for CoreServer in /home/lecoq_m/RType
// 
// Made by Maxime Lecoq
// Login   <maxime.lecoq@epitech.eu>
// 
// Started on  Fri Dec  2 14:19:16 2016 Maxime Lecoq
// Last update Thu Dec 15 15:13:55 2016 lecoq
//

#ifndef CORECLIENT_HH_
# define CORECLIENT_HH_

# include "ACore.hh"
# include "ManagerClient.hh"

using namespace Gui;
using namespace Gui::Audio;

class CoreClient : public ACore
{
  public:
  CoreClient();
  ~CoreClient();
  void		run();
  void		initManager();
  void		deleteManager();
private:
  IManagerClient	*_manager;
  IGUI		*_gui;
  ISoundManager *_sound;
};

#endif /* !CORECLIENT_HH_ */
