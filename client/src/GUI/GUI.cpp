#include "GUI.hh"
#include "SpriteMap.hpp"

using namespace Gui;

std::map<std::string, sf::Texture> SpriteMap::_textureMap;
std::map<std::string, sf::Sprite>  SpriteMap::_spriteMap;

GUI::GUI()
{
  // ptr init
  SpriteMap::SpriteMapLoad();
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
  //  displayMenu();
}

GUI::~GUI()
{
  deleteWidgets();
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
      EventPart::Event ep = EventPart::Event(EventPart::Event::DEFAULT);
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
	case EventPart::Event::MOUSE__MOVED :
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
	  case EventPart::Event::BUTTON_CONNECT :
          {
	    std::string stringIp, stringPort;
            auto tmpIp = _startWidgets->imput->getText();
            bool founded = false;
            for(unsigned int i = 0; i < tmpIp.size(); i++)
	      {
		if (tmpIp[i] == ':')
                  founded = true;
                else
                  if (founded == false)
                    stringIp += tmpIp[i];
		  else
                    stringPort +=tmpIp[i];
              }
            ep = EventPart::Event(EventPart::Event::TRY_CONNECT,
                                  "IP", stringIp,
                                  "PORT", stringPort);
	    break ;
          }
	case EventPart::Event::BUTTON_LOGIN :
	  {
	    ep = EventPart::Event(EventPart::Event::TRY_LOGIN,
                                  "LOGIN", _loginWidgets->login->getText(),
                                  "PWD", _loginWidgets->password->getText());
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

  //this->_gameWidgets->levelId = ...
  _win->setBackground("../client/Assets/RType_background.bmp");
  //_win->setBackground(this->backgroundMap[this->_gameWidgets->levelId]);// Ou on pourrait set le levelId ?
  _gameWidgets->layout = _win->addWidget(0, 0, WINDOW_WIDTH, 100);

  Style         s = _gameWidgets->layout->getStyle();;
  s.form = RECTANGLE;
  s.textColor = Color(0, 0, 250);
  s.backgroundColor = Color(250, 0, 0);
  _gameWidgets->layout->setStyle(s);

  struct data oui;

  this->players.push_back(oui);
  oui.x = 150;
  oui.y = 150;
  oui.health = 75;
  this->players.push_back(oui);
  oui.x = 300;
  oui.y = 300;
  oui.health = 50;
  this->players.push_back(oui);
  oui.x = 450;
  oui.y = 450;
  oui.health = 25;
  this->players.push_back(oui);

  //PLAYERS
  for (unsigned int i = 0; i < players.size(); i++)
    {
      IWidget *temp;
      std::string non = "Player" + std::to_string(i) + "\n\t" + std::to_string(players[i].health) + "HP";

      temp = _win->addWidget((WINDOW_WIDTH / 4) * i, 0, WINDOW_WIDTH / players.size(), 100);
      temp->setText(non);

      Style s1 = temp->getStyle();

      temp = _win->addWidget(players[i].x, 100 + players[i].y, 34, 20);
      s1.image = "Ship" + std::to_string(i + 1);
      s1.policeSize = 50;
      temp->setStyle(s1);
    }

  oui.x = 500;
  oui.y = 50;
  this->shots.push_back(oui);
  oui.x = 550;
  oui.y = 150;
  this->shots.push_back(oui);
  oui.x = 550;
  oui.y = 300;
  this->shots.push_back(oui);
  oui.x = 650;
  oui.y = 450;
  this->shots.push_back(oui);

  //SHOTS
  for (unsigned int i = 0; i < shots.size(); i++)
    {
      IWidget *temp;

      temp = _win->addWidget(shots[i].x, 100 + shots[i].y, 34, 20);

      Style s3 = temp->getStyle();

      //s.image = "Shot-" + _gameWidgets->shots[i].name;
      s3.image = "Shot-" + std::to_string(/*i + */1);
      temp->setStyle(s3);
    }

  oui.x = 700;
  oui.y = 30;
  this->monsters.push_back(oui);

  // MONSTERS
  for (unsigned int i = 0; i < monsters.size(); i++)
    {
      IWidget *temp;

      temp = _win->addWidget(monsters[i].x, 100 + monsters[i].y, 25, 25);

      Style s4 = temp->getStyle();

      s4.image = "Bydos";
      temp->setStyle(s4);
    }

  // Envs
  /*for (int i = 0; i < envs.size(); i++)
    {
      IWidget *temp;
      temp = _win->addWidget(envs[i].x, 100 + envs[i].y, 34, 20);

      Style s5 = temp->getStyle();

      //s.image = "Env-" + _gameWidgets->envs[i].name;
      s5.image = "Env-" + std::to_string();
      temp->setStyle(s5);
      }*/
}

void		GUI::displayStart()
{
  // custom window
  //_win->setBackground("/home/bertho_i/Downloads/Patate_pokémon.png");
  _win->setBackground("../client/Assets/RType_background.bmp");
  // init
  _startWidgets = new Start;
  _startWidgets->imput = _win->addWidget(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, 75);
  _startWidgets->button = _win->addWidget(WINDOW_WIDTH / 4, (2 * WINDOW_HEIGHT) / 3, WINDOW_WIDTH / 2, 75);
  _startWidgets->title = _win->addWidget(WINDOW_WIDTH / 4, 50, WINDOW_WIDTH / 2, 100);
  // custom button
  Style		logoStyle = _startWidgets->title->getStyle();
  logoStyle.image = "Logo";
  _startWidgets->title->setStyle(logoStyle);

  Style		s;
  s = _startWidgets->button->getStyle();
  _startWidgets->button->setText("Connect.");
  _startWidgets->button->setOnClick([](IWidget *fuckingButton, CLICK)
				    {
				      auto eq = fuckingButton->getEventQueue();
				      eq->push(EventPart::Event(EventPart::Event::BUTTON_CONNECT));
				      std::cout << "try connect" << std::endl;
				    });
  _startWidgets->button->setOnHover([](IWidget *w)
				    {
				      Style s1 = w->getStyle();
				      s1.backgroundColor.blue += 100;
 				      s1.backgroundColor.green += 100;
				      w->setStyle(s1);
				    });
  _startWidgets->button->setOnLeaveHover([](IWidget *w)
					 {
					   Style s2 = w->getStyle();
					   s2.backgroundColor.blue -= 100;
					   s2.backgroundColor.green -= 100;
					   w->setStyle(s2);
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
  _win->setBackground("../client/Assets/RType_background.bmp");
  //_win->setBackground("background1.jpg");
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
				      Style s1 = w->getStyle();
				      s1.backgroundColor.blue += 100;
 				      s1.backgroundColor.green += 100;
				      w->setStyle(s1);
				    });
  _menuWidgets->confirm->setOnLeaveHover([](IWidget *w)
					 {
					   Style s2 = w->getStyle();
					   s2.backgroundColor.blue -= 100;
					   s2.backgroundColor.green -= 100;
					   w->setStyle(s2);
					 });

  _menuWidgets->createGame->setText("+");
  _menuWidgets->createGame->setOnClick([](IWidget *, CLICK){std::cout << "Let's try to create a game !" << std::endl;});
  _menuWidgets->createGame->setOnHover([](IWidget *w)
				    {
				      Style s3 = w->getStyle();
				      s3.backgroundColor.blue += 100;
 				      s3.backgroundColor.green += 100;
				      w->setStyle(s3);
				    });
  _menuWidgets->createGame->setOnLeaveHover([](IWidget *w)
					 {
					   Style s4 = w->getStyle();
					   s4.backgroundColor.blue -= 100;
					   s4.backgroundColor.green -= 100;
					   w->setStyle(s4);
					 });

  // ergonomie focus
  _focusWidget = _menuWidgets->confirm;
}

void		GUI::displayLogin()
{
  _loginWidgets = new Login;
  _win->setBackground("../client/Assets/RType_background.bmp");
  //_win->setBackground("background1.jpg");
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
  _loginWidgets->confirm->setOnClick([](IWidget *w, CLICK)
				  {
				    auto eq = w->getEventQueue();
			            eq->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
				    std::cout << "Let's connect !" << std::endl;
				  });
  _loginWidgets->confirm->setOnHover([](IWidget *w)
				    {
				      Style s1 = w->getStyle();
				      s1.backgroundColor.blue += 100;
 				      s1.backgroundColor.green += 100;
				      w->setStyle(s1);
				    });
  _loginWidgets->confirm->setOnLeaveHover([](IWidget *w)
					 {
					   Style s2 = w->getStyle();
					   s2.backgroundColor.blue -= 100;
					   s2.backgroundColor.green -= 100;
					   w->setStyle(s2);
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

void			GUI::setSoundManager(Audio::ISoundManager *sound)
{
  _audio = sound;
}

void			GUI::showPopup(const std::string &string, int tMilli)
{
  if (_fadedWidget)
    {
      _win->deleteWidget(_fadedWidget);
    }
  // other init
  _fadedWidget = _win->addWidget(50, 350, string.size() * 20, 50);
  auto style = _fadedWidget->getStyle();
  style.backgroundColor.green = 250;
  style.form = RECTANGLE;
  style.policeSize = 24;
  style.textColor.red = 250;
  _fadedWidget->setStyle(style);
  _fadedWidget->showPopup(string, tMilli);
}
