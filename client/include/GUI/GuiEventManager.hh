#ifndef KEYBOARD_MANAGER_HH
#define KEYBOARD_MANAGER_HH

#include <map>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "IGuiEventManager.hh"

#include "Clock.hpp"
#include "Click.hh"

#define INTERVAL_CHECK_KEY 1
#define INTERVAL_CHECK_ATTACK 50

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
    void		setMouseTracking(bool);
    void		setTextTracking(bool);
  protected:
    sf::Window								*_win;
    EventPart::IEventQueue					*_queue;
    bool									_mouseTracking;
    bool									_textTracking;
    std::map<KEY, EventPart::Event::TYPE>	_events;
    std::map<sf::Keyboard::Key, KEY>	    _keys;
	Clock									clock;
	Clock									attackCd;
  };
}

#endif
