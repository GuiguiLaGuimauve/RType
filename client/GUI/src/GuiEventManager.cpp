#include "GuiEventManager.hh"

using namespace Gui;

GuiEventManager::GuiEventManager(sf::Window *w):
  _win(w), _queue(NULL), _mouseTracking(true), _textTracking(true)
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
	  {
	    if (_mouseTracking)
	      _queue->push(EventPart::Event(EventPart::Event::MOUSE_MOVED, "X", event.mouseMove.x,
					    "Y", event.mouseMove.y));
	    break;
	  }
	case sf::Event::KeyPressed :
	  {
	    auto i = _keys.find(event.key.code);
	    if (i != _keys.end())
	      _queue->push(EventPart::Event(_events[_keys[event.key.code]]));
	    break ;
	  }
	case sf::Event::TextEntered:
	  {
	    if (_textTracking)
	      {
		std::string s;
		s += (static_cast<char> (event.text.unicode));
		_queue->push(EventPart::Event(EventPart::Event::TEXT, "CHAR", s));
	      }
	    break;
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

void		GuiEventManager::setMouseTracking(bool b)
{
  _mouseTracking = b;
}

void		GuiEventManager::setTextTracking(bool b)
{
  _textTracking = b;
}