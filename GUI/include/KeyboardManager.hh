#ifndef KEYBOARD_MANAGER_HH
#define KEYBOARD_MANAGER_HH

#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "IKeyboardManager.hh"

namespace Gui
{
  class KeyboardManager: public IKeyboardManager
  {
  public:
    KeyboardManager();
    virtual ~KeyboardManager();

    void        callback();
    void        setEventQueue(EventPart::IEventQueue *);
    void        bindKey(KEY, EventPart::Event::TYPE);    
  protected:
    EventPart::IEventQueue			*_queue;
    std::map<KEY, EventPart::Event::TYPE>	_events;
    //std::map<sf::Keyboard::Key, KEY>	       	_keys;
  };
}

#endif
