#include "GUI.hh"
#include "SpriteMap.hpp"

using namespace Gui;

std::map<std::string, sf::Texture> SpriteMap::_textureMap;
std::map<std::string, sf::Sprite>  SpriteMap::_spriteMap;

GUI::GUI()
{
  // ptr init
  SpriteMap::SpriteMapLoad();
  _audio = new Audio::SoundManager;
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
  //displayStart();
  //displayLogin();
  displayMenu();
}

GUI::~GUI()
{
  _coreQueue = NULL;
  deleteWidgets();
  delete _audio;
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
      EventPart::Event e = _guiQueue->pop();
      EventPart::Event ep(EventPart::Event(EventPart::Event::DEFAULT));
      switch (e.type)
	{
	case EventPart::Event::CLOSE_WINDOW :
	  ep = EventPart::Event(EventPart::Event::QUIT);
	  break;
	case EventPart::Event::CLICK :
	  {
	    IWidget *w = _win->isThereWidget(e.dataInt["X"], e.dataInt["Y"]);
	    if (w)
	      w->onClick(static_cast<CLICK> (e.dataInt["CLICK"]));
	    if (w != _focusWidget)
	      {
		if (_focusWidget)
		  _focusWidget->onLeaveFocus();
		if (w)
		  w->onFocus();
		_focusWidget = w;
	      }
	    break;
	  }
	case EventPart::Event::MOUSE_MOVED :
	  {
	    IWidget *w = _win->isThereWidget(e.dataInt["X"], e.dataInt["Y"]);
	    if (w != _hoverWidget)
	      {
		if (_hoverWidget)
		  _hoverWidget->onLeaveHover();
		if (w)
		  w->onHover();
		_hoverWidget = w;
	      }
	    break;
	  }
	case EventPart::Event::TEXT :
	  {
	    if (_focusWidget)
	      _focusWidget->onTextEntered(e.dataString["CHAR"]);
	    break ;
	  }
	default :
	  ep.type = EventPart::Event::DEFAULT;
	}
      if (ep.type != EventPart::Event::DEFAULT && _coreQueue)
	_coreQueue->push(ep);
    }
}

void		GUI::displayGame()
{
  /* Load le bon background en fonction du stage séléctionné */

  _gameWidgets = new Game;
}

void		GUI::displayStart()
{
  // custom window
  //_win->setBackground("/home/bertho_i/Downloads/Patate_pokémon.png");
  _win->setBackground("background1.jpg");
  // init
  _startWidgets = new Start;
  _startWidgets->imput = _win->addWidget(50, 50, 300, 75);
  _startWidgets->button = _win->addWidget(50, 150, 300, 75);
  // custom button
  Style		s;
  s = _startWidgets->button->getStyle();
  _startWidgets->button->setText("Connect.");
  _startWidgets->button->setOnClick([](IWidget *, CLICK){std::cout << "try connect" << std::endl;});
  _startWidgets->button->setOnHover([](IWidget *w)
				    {
				      Style s = w->getStyle();
				      s.backgroundColor.blue += 100;
 				      s.backgroundColor.green += 100;
				      w->setStyle(s);
				    });
  _startWidgets->button->setOnLeaveHover([](IWidget *w)
					 {
					   Style s = w->getStyle();
					   s.backgroundColor.blue -= 100;
					   s.backgroundColor.green -= 100;
					   w->setStyle(s);
					 });
  s.form = RECTANGLE;
  s.textColor = Color(0, 0, 250);
  s.policeSize = 35;
  s.backgroundColor = Color(250, 0, 0);
  _startWidgets->button->setStyle(s);
  // custom imput
  s.backgroundColor = Color(250, 250, 250);
  _startWidgets->imput->setStyle(s);
  _startWidgets->imput->setOnTextEntered([](IWidget *w, const std::string &c)
					 {
					   if (c[0] == 127 || c[0] == 8)
					     {
					       std::string tmp = w->getText();
					       if (tmp.length() > 0)
						 tmp.pop_back();
					       w->setText(tmp);
					     }
					   else if (isprint(c[0]))
					     w->setText(w->getText() + c);
					 });
  // ergonomie focus
  _focusWidget = _startWidgets->imput;
}

void		GUI::displayMenu()
{
  _win->setBackground("background1.jpg");
  _menuWidgets = new Menu;

  _menuWidgets->GameContainer = _win->addWidget(300, 100, 1000, 300);
  _menuWidgets->GameContainer->setText("Games");
  _menuWidgets->createGame = _win->addWidget(1450, 100, 300, 300);
  _menuWidgets->createGame->setText("+");
  _menuWidgets->profile = _win->addWidget(300, 500, 1000, 300);
  _menuWidgets->profile->setText("Profile");
  _menuWidgets->confirm = _win->addWidget(1450, 500, 300, 300);
  _menuWidgets->confirm->setText("Confirm");

  Style		s = _menuWidgets->confirm->getStyle();
  s.form = RECTANGLE;
  s.textColor = Color(0, 0, 250);
  s.policeSize = 35;
  s.backgroundColor = Color(250, 0, 0);

  _menuWidgets->GameContainer->setStyle(s);
  _menuWidgets->profile->setStyle(s);
  _menuWidgets->createGame->setStyle(s);
  _menuWidgets->confirm->setStyle(s);

  s.image = "Ship1";
  _menuWidgets->profile->setStyle(s);
  _menuWidgets->GameContainer->setStyle(s);

  _menuWidgets->confirm->setText("Confirm");
  _menuWidgets->confirm->setOnClick([](IWidget *, CLICK){std::cout << "Let's connect !" << std::endl;});
  _menuWidgets->confirm->setOnHover([](IWidget *w)
				    {
				      Style s = w->getStyle();
				      s.backgroundColor.blue += 100;
 				      s.backgroundColor.green += 100;
				      w->setStyle(s);
				    });
  _menuWidgets->confirm->setOnLeaveHover([](IWidget *w)
					 {
					   Style s = w->getStyle();
					   s.backgroundColor.blue -= 100;
					   s.backgroundColor.green -= 100;
					   w->setStyle(s);
					 });

  _menuWidgets->createGame->setText("+");
  _menuWidgets->createGame->setOnClick([](IWidget *, CLICK){std::cout << "Let's try to create a game !" << std::endl;});
  _menuWidgets->createGame->setOnHover([](IWidget *w)
				    {
				      Style s = w->getStyle();
				      s.backgroundColor.blue += 100;
 				      s.backgroundColor.green += 100;
				      w->setStyle(s);
				    });
  _menuWidgets->createGame->setOnLeaveHover([](IWidget *w)
					 {
					   Style s = w->getStyle();
					   s.backgroundColor.blue -= 100;
					   s.backgroundColor.green -= 100;
					   w->setStyle(s);
					 });

  // ergonomie focus
  _focusWidget = _menuWidgets->confirm;
}

void		GUI::displayLogin()
{
  _loginWidgets = new Login;
  _win->setBackground("background1.jpg");
  _loginWidgets->login = _win->addWidget(300, 120, 300, 75);
  _loginWidgets->password = _win->addWidget(300, 220, 300, 75);
  _loginWidgets->confirm = _win->addWidget(300, 370, 300, 75);

  Style		s = _loginWidgets->login->getStyle();
  s.form = RECTANGLE;
  s.textColor = Color(0, 0, 250);
  s.policeSize = 35;
  s.backgroundColor = Color(250, 0, 0);

  _loginWidgets->login->setStyle(s);
  _loginWidgets->password->setStyle(s);
  _loginWidgets->confirm->setStyle(s);


  /* je gère le clic, le hover et le unhover */
  _loginWidgets->confirm->setText("Confirm");
  _loginWidgets->confirm->setOnClick([](IWidget *, CLICK){std::cout << "Let's connect !" << std::endl;});
  _loginWidgets->confirm->setOnHover([](IWidget *w)
				    {
				      Style s = w->getStyle();
				      s.backgroundColor.blue += 100;
 				      s.backgroundColor.green += 100;
				      w->setStyle(s);
				    });
  _loginWidgets->confirm->setOnLeaveHover([](IWidget *w)
					 {
					   Style s = w->getStyle();
					   s.backgroundColor.blue -= 100;
					   s.backgroundColor.green -= 100;
					   w->setStyle(s);
					 });


  /* Je gère l'édition des 2 inputs */
  _loginWidgets->login->setOnTextEntered([](IWidget *w, const std::string &c)
					 {
					   if (c[0] == 127 || c[0] == 8)
					     {
					       std::string tmp = w->getText();
					       if (tmp.length() > 0)
						 tmp.pop_back();
					       w->setText(tmp);
					     }
					   else if (isprint(c[0]))
					     w->setText(w->getText() + c);
					 });
  _loginWidgets->password->setOnTextEntered([](IWidget *w, const std::string &c)
					 {
					   if (c[0] == 127 || c[0] == 8)
					     {
					       std::string tmp = w->getText();
					       if (tmp.length() > 0)
						 tmp.pop_back();
					       w->setText(tmp);
					     }
					   else if (isprint(c[0]))
					     w->setText(w->getText() + c);
					 });




  // ergonomie focus
  _focusWidget = _loginWidgets->login;
}

void		GUI::updateGameInfo(/*const GameInfo &*/)
{
}

void		GUI::setEventQueue(EventPart::IEventQueue *eq)
{
  _coreQueue = eq;
}

void		GUI::deleteWidgets()
{
  if (_startWidgets)
    {
      _win->deleteWidget(_startWidgets->imput);
      _win->deleteWidget(_startWidgets->button);
      delete _startWidgets;
      _startWidgets = NULL;
    }
  if (_loginWidgets)
    {
      delete _loginWidgets;
      _loginWidgets = NULL;
    }
  if (_menuWidgets)
    {
      delete _menuWidgets;
      _menuWidgets = NULL;
    }
  if (_gameWidgets)
    {
      delete _gameWidgets;
      _gameWidgets = NULL;
    }
}
