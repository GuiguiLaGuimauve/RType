#ifndef IKEYBOARD_MANAGER_HH
#define IKEYBOARD_MANAGER_HH

#include "Key.hh"
#include "Event.hpp"
#include "IEventQueue.hh"

namespace Gui
{
  class IGuiEventManager
  {
  public:
    virtual ~IGuiEventManager(){};

    virtual void	callback() = 0;
    virtual void	setEventQueue(EventPart::IEventQueue *) = 0;
    virtual void	bindKey(KEY, EventPart::Event::TYPE) = 0;
    virtual void	setMouseTracking(bool) = 0;
    virtual void	setTextTracking(bool) = 0;
  };
}

#endif
