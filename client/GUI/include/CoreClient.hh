#ifndef CORE_CLIENT_HPP
#define CORE_CLIENT_HPP

#include "ACore.hh"
#include "IManagerClient.hh"
#include "IGUI.hh"
#include "ISoundManager.hh"

namespace Core
{
  class CoreClient
  {
  public:
    CoreClient();
    virtual ~CoreClient();

    virtual void	initManager() = 0;
    virtual void	run() = 0;
  protected:
    IManagerClient	*_manager;
    IGUI		*_gui;
    ISoundManager	*_sound;
  };
};

#endif
