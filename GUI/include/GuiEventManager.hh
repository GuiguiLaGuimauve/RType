#ifndef KEYBOARD_MANAGER_HH
#define KEYBOARD_MANAGER_HH

#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "IGuiEventManager.hh"

#include "Click.hh"

namespace Gui
{
  class GuiEventManager: public IGuiEventManager
  {
  public:
    GuiEventManager(sf::Window *);
    virtual ~GuiEventManager();

    void        callback();
    void        setEventQueue(EventPart::IEventQueue *);
    void        bindKey(KEY, EventPart::Event::TYPE);    
  protected:
    sf::Window					*_win;
    EventPart::IEventQueue			*_queue;
    std::map<KEY, EventPart::Event::TYPE>	_events;
    std::map<sf::Keyboard::Key, KEY>	       	_keys;
  };
}

#endif