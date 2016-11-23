#include "GUI.hh"

using namespace Gui;

GUI::GUI()
{
  // ptr init
  _audio = NULL; // à changer quand j'aurai créé l'audio
  _win = new Window;
  _userEvents = new GuiEventManager(static_cast<Window *> (_win)->getSfmlWinPtr());
  _coreQueue = NULL;
  _guiQueue = new EventPart::EventQueue;
  // set event queue
  _win->setEventQueue(_guiQueue);
  _userEvents->setEventQueue(_guiQueue);
  // bind key init
  _userEvents->bindKey(KEY_UP, EventPart::Event::KEY_UP);
  _userEvents->bindKey(KEY_RIGHT, EventPart::Event::KEY_RIGHT);
  _userEvents->bindKey(KEY_LEFT, EventPart::Event::KEY_LEFT);
  _userEvents->bindKey(KEY_DOWN, EventPart::Event::KEY_DOWN);
  _userEvents->bindKey(KEY_ATTACK, EventPart::Event::KEY_ATTACK);
  // display init
  displayStart();
}

GUI::~GUI()
{
  //  delete _audio;
  delete _win;
  delete _userEvents;
  delete _guiQueue;
}

void		GUI::callback()
{
  _userEvents->callback();
  _win->drawAll();
  while (!_guiQueue->empty())
    {
      std::cout << "gui queue se vide" << std::endl;
      EventPart::Event e = _guiQueue->pop();
      switch (e.type)
	{
	case EventPart::Event::CLOSE_WINDOW :
	  e = EventPart::Event(EventPart::Event::QUIT);
	  break;
	default :
	  e.type = EventPart::Event::DEFAULT;
	}
      if (e.type != EventPart::Event::DEFAULT && _coreQueue)
	_coreQueue->push(e);
    }
}

void		GUI::displayGame()
{
}

void		GUI::displayStart()
{
}

void		GUI::displayMenu()
{
}

void		GUI::updateGameInfo(/*const GameInfo &*/)
{
}

void		GUI::setEventQueue(EventPart::IEventQueue *eq)
{
  _coreQueue = eq;
}

