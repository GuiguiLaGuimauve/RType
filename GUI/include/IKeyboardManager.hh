#ifndef IKEYBOARD_MANAGER_HH
#define IKEYBOARD_MANAGER_HH

#include "Key.hh"
#include "Event.hpp"
#include "IEventQueue.hh"

namespace Gui
{
  class IKeyboardManager
  {
  public:
    virtual ~IKeyboardManager(){};

    virtual void	callback() = 0;
    virtual void	setEventQueue(EventPart::IEventQueue *) = 0;
    virtual void	bindKey(KEY, EventPart::Event::TYPE) = 0;
  };
}

#endif
