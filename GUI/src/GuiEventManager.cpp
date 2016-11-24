#include "GuiEventManager.hh"

using namespace Gui;

GuiEventManager::GuiEventManager(sf::Window *w):
  _win(w), _queue(NULL)
{
  _keys[sf::Keyboard::Left] = KEY_LEFT;
  _keys[sf::Keyboard::Right] = KEY_RIGHT;
  _keys[sf::Keyboard::Down] = KEY_DOWN;
  _keys[sf::Keyboard::Up] = KEY_UP;
  _keys[sf::Keyboard::Space] = KEY_ATTACK;
}

GuiEventManager::~GuiEventManager()
{
}

void		GuiEventManager::callback()
{
  if (!_queue)
    return ;
  sf::Event event;
  while (_win->pollEvent(event))
    {
      switch (event.type)
	{
	case sf::Event::Closed :
	  _queue->push(EventPart::Event(EventPart::Event::CLOSE_WINDOW));
	  break;
	case sf::Event::MouseButtonPressed :
	  {
	    int click = 0;
	    switch (event.mouseButton.button)
	      {
	      case sf::Mouse::Right : click = CLICK_RIGHT;
	      case sf::Mouse::Left : click = CLICK_LEFT;
	      case sf::Mouse::Middle: click = CLICK_WHEEL;
	      }
	    _queue->push(EventPart::Event(EventPart::Event::CLICK, "X", event.mouseButton.x,
					  "Y", event.mouseButton.y, "CLICK", click));
	    break;
	  }
	case sf::Event::MouseMoved :
	  _queue->push(EventPart::Event(EventPart::Event::MOUSE_MOVED, "X", event.mouseMove.x,
					"Y", event.mouseMove.y));
	case sf::Event::KeyPressed :
	  {
	    auto i = _keys.find(event.key.code);
	    if (i != _keys.end())
	      _queue->push(EventPart::Event(_events[_keys[event.key.code]]));
	  }
	}
    }
}

void		GuiEventManager::setEventQueue(EventPart::IEventQueue *eq)
{
  _queue = eq;
}

void		GuiEventManager::bindKey(KEY k, EventPart::Event::TYPE e)
{
  _events[k] = e;
}
