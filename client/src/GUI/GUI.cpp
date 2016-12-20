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
  //_audio = new Audio::SoundManager;
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
  _userEvents->bindKey(KEY_QUIT, EventPart::Event::CLOSE_WINDOW);
  //display init
  //displayStart();
  //displayLogin();
  //displayMenu();
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
	case EventPart::Event::BUTTON_CREATE_GAME :
	{
		ep = EventPart::Event(EventPart::Event::CREATE_GAME);
		break;
	}
	case EventPart::Event::BUTTON_JOIN_GAME:
	{
		ep = EventPart::Event(EventPart::Event::JOIN_GAME);
		break ;
	}
	case EventPart::Event::KEY_ATTACK :
	{
		if (_gameWidgets)
			ep = EventPart::Event(EventPart::Event::ATTACK);
		break;
	}
	case EventPart::Event::KEY_UP:
	{
		if (_gameWidgets)
			ep = EventPart::Event(EventPart::Event::MOVE_UP);
		break;
	}
	case EventPart::Event::KEY_DOWN:
	{
		if (_gameWidgets)
			ep = EventPart::Event(EventPart::Event::MOVE_DOWN);
		break;
	}
	case EventPart::Event::KEY_LEFT:
	{
		if (_gameWidgets)
			ep = EventPart::Event(EventPart::Event::MOVE_LEFT);
		break;
	}
	case EventPart::Event::KEY_RIGHT:
	{
		if (_gameWidgets)
			ep = EventPart::Event(EventPart::Event::MOVE_RIGHT);
		break;
	}
	case EventPart::Event::LOGIN_SWITCH_IMPUT :
	{
		if (_loginWidgets)
		{
			if (_focusWidget == _loginWidgets->login)
			{
				_loginWidgets->login->onLeaveFocus();
				_focusWidget = _loginWidgets->password;
				_loginWidgets->password->onFocus();
			}
			else if (_focusWidget == _loginWidgets->password)
			{
				_loginWidgets->password->onLeaveFocus();
				_focusWidget = _loginWidgets->login;
				_loginWidgets->login->onFocus();
			}
		}
	break;
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
  deleteWidgets();
  /* Load le bon background en fonction du stage séléctionné */
  _gameWidgets = new Game;

  //this->_gameWidgets->levelId = ...
  _win->setBackground("../client/Assets/RType_background.bmp");
  //_win->setBackground(this->backgroundMap[this->_gameWidgets->levelId]);// Ou on pourrait set le levelId ?

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
      int red[4] = {3, 161, 36, 255};
      int green[4] = {198, 0, 212, 3};
      int blue[4] = {252, 252, 43, 5};

      temp = _win->addWidget((_win->getWidth() / 4) * (int) i, 0, _win->getWidth() / (int) players.size(), 100);

      Style sheart = temp->getStyle();
      sheart.image = "Heart" + std::to_string(i + 1);
      temp->setStyle(sheart);

      temp = _win->addWidget((_win->getWidth() / 4) * (int) i + 100, 30, _win->getWidth() / (int) players.size(), 100);
      std::string non = " " + std::to_string(players[i].health) + " %";
      sheart.image = "";
      temp->setText(non);
      sheart.textColor = Color(red[i], green[i], blue[i]);
      sheart.policeSize = 60;
      temp->setStyle(sheart);
      
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

  oui.x = 1200;
  oui.y = 150;
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
  deleteWidgets();
  // custom window
  _win->setBackground("../client/Assets/RType_background.bmp");
  _audio->playMusic("TitleScreen");
  // init
  _startWidgets = new Start;
  _startWidgets->title = _win->addWidget(_win->getWidth() / 3 + 60, _win->getHeight() / 4, _win->getWidth() / 2, 100);
  _startWidgets->texte = _win->addWidget(_win->getWidth() / 3 - 80, _win->getHeight() / 2 - 100, _win->getWidth() / 2, 100);
  _startWidgets->imput = _win->addWidget(_win->getWidth() / 3, _win->getHeight() / 2 + 20, _win->getWidth() / 2, 175);
  _startWidgets->button = _win->addWidget(_win->getWidth() / 3 + 170, (2 * _win->getHeight()) / 3, 250, 40);
  _startWidgets->chevron = _win->addWidget((_win->getWidth() / 3) - 200, _win->getHeight() / 2 + 20, 0, 0);
  // custom button
  _startWidgets->texte->setText("ENTER THE ADDRESS:PORT");
  _startWidgets->button->setText("CONNECT");
  _startWidgets->chevron->setText(">");
  _startWidgets->imput->setText("127.0.0.1:4242");
  
  Style		logoStyle = _startWidgets->title->getStyle();
  logoStyle.image = "Logo";

  Style		s = _startWidgets->button->getStyle();
  s.form = RECTANGLE;
  s.textColor = Color(255, 215, 0);
  s.policeSize = 35;

  _startWidgets->title->setStyle(logoStyle);
  _startWidgets->imput->setStyle(s);
  _startWidgets->texte->setStyle(s);
  _startWidgets->button->setStyle(s);
  _startWidgets->chevron->setStyle(s);

  _startWidgets->button->setOnClick([](IWidget *fuckingButton, CLICK)
				    {
				      auto eq = fuckingButton->getEventQueue();
				      eq->push(EventPart::Event(EventPart::Event::BUTTON_CONNECT));
				      std::cout << "try connect" << std::endl;
				      });
  _startWidgets->button->setOnHover(TextColorFocus);
  _startWidgets->button->setOnLeaveHover(TextColorNoFocus);

  // custom imput
  _startWidgets->imput->setOnTextEntered([](IWidget *w, const std::string &c)
  {
	  if (c[0] == '\n')
	    w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_CONNECT));
	  else
	    textEntered(w, c);
  });
  // ergonomie focus
  _focusWidget = _startWidgets->imput;
}

void		GUI::displayMenu()
{
  deleteWidgets();
  _win->setBackground("../client/Assets/RType_background.bmp");
  _menuWidgets = new Menu;

  _menuWidgets->GameContainer = _win->addWidget(_win->getWidth() / 6, 100, 1000, 300);
  _menuWidgets->GameInfos = _win->addWidget(3 * (_win->getWidth() / 4), 100, 1000, 300);
  _menuWidgets->createGame = _win->addWidget(3 * (_win->getWidth() / 4), 5 * (_win->getHeight() / 6), 50, 60);
  _menuWidgets->profile = _win->addWidget(3 * (_win->getWidth() / 4), _win->getHeight() / 2, _win->getHeight() / 4, 300);
  _menuWidgets->confirm = _win->addWidget(4 * (_win->getWidth() / 5), 5 * (_win->getHeight() / 6) + 10, 135, 45);
  _menuWidgets->GameContainer->setText("Games");
  _menuWidgets->GameInfos->setText("Infos");
  _menuWidgets->createGame->setText("+");
  _menuWidgets->profile->setText("Profile");
  _menuWidgets->confirm->setText("Join");

  Style		s = _menuWidgets->confirm->getStyle();
  s.form = RECTANGLE;
  s.textColor = Color(255, 215, 0);

  s.policeSize = 35;
  _menuWidgets->GameContainer->setStyle(s);
  _menuWidgets->profile->setStyle(s);
  _menuWidgets->GameInfos->setStyle(s);
  _menuWidgets->confirm->setStyle(s);
  s.policeSize = 60;
  _menuWidgets->createGame->setStyle(s);

  std::cout << "A l'initialisation, la size de mes Rooms est " << _menuInfos.size() << std::endl;
  int i = 0;
  for (auto elem : _menuInfos)
    {
      IWidget *temp = _win->addWidget(_win->getWidth() / 6, 100 + ((i + 1) * 100), _win->getWidth() / 2, 100);
      Style sgame = temp->getStyle();
      sgame.policeSize = 20;
      sgame.textColor = Color(255, 215, 255) = 20;
      temp->setStyle(sgame);
      temp->setText(elem->getName() + "\t" + std::to_string(elem->getPlayers().size()) + "/" + std::to_string(elem->getMaxPlayers()) + "\tStage " + std::to_string(elem->getLevel()));
      // Mettre le OnClick à envoi d'Event avec numero de Game à update (voir avec ClientCore & Max)
      i++;
    }

  if (_currentGame)
    {
      _menuWidgets->selectedGame = _win->addWidget(3 * (_win->getWidth() / 4), 100, 300, 300);
      s.policeSize = 20;
      _menuWidgets->selectedGame->setStyle(s);
      _menuWidgets->selectedGame->setText("Name : " + _currentGame->getName() + "\nPlayers :\n");
      for (auto elem : _currentGame->getPlayers())
	_menuWidgets->selectedGame->setText(_menuWidgets->selectedGame->getText() + elem->getName() + "\n");
  }

  _menuWidgets->confirm->setOnClick([](IWidget *widget, CLICK)
				    {
				      std::cout << "Let's connect !" << std::endl;
				      auto eq = widget->getEventQueue();
				      eq->push(EventPart::Event(EventPart::Event::BUTTON_JOIN_GAME));
				    });
  _menuWidgets->confirm->setOnHover(TextColorFocus);
  _menuWidgets->confirm->setOnLeaveHover(TextColorNoFocus);

  _menuWidgets->createGame->setOnClick([](IWidget *widget, CLICK)
				       {
					 std::cout << "Let's try to create a game !" << std::endl;
					 auto eq = widget->getEventQueue();
					 eq->push(EventPart::Event(EventPart::Event::BUTTON_CREATE_GAME));
				       });
  _menuWidgets->createGame->setOnHover(TextColorFocus);
  _menuWidgets->createGame->setOnLeaveHover(TextColorNoFocus);

  // ergonomie focus
  _focusWidget = _menuWidgets->confirm;
}

void		GUI::displayLogin()
{
  deleteWidgets();
  _loginWidgets = new Login;
  _win->setBackground("../client/Assets/RType_background.bmp");
  _loginWidgets->login = _win->addWidget(_win->getWidth() / 3, _win->getHeight() / 4, _win->getWidth() / 2, 180);
  _loginWidgets->password = _win->addWidget(_win->getWidth() / 3, _win->getHeight() / 2, _win->getWidth() / 2, 180);
  _loginWidgets->confirm = _win->addWidget(_win->getWidth() / 3 + 150, (2 * _win->getHeight()) / 3,  250, 50);
  _loginWidgets->text1 = _win->addWidget(_win->getWidth() / 3 + 150, _win->getHeight() / 4 - 100, 0, 0);
  _loginWidgets->text2 = _win->addWidget(_win->getWidth() / 3 + 100, _win->getHeight() / 2 - 100, 0, 0);
  _loginWidgets->chevron1 = _win->addWidget(_win->getWidth() / 3 - 200, _win->getHeight() / 4, 0, 0);
  _loginWidgets->chevron2 = _win->addWidget(_win->getWidth() / 3 - 200, _win->getHeight() / 2, 0, 0);

  Style		s = _loginWidgets->login->getStyle();
  s.form = RECTANGLE;
  s.textColor = Color(255, 215, 0);
  s.policeSize = 35;

  _loginWidgets->login->setStyle(s);
  s.password = true;
  _loginWidgets->password->setStyle(s);
  s.password = false;
  _loginWidgets->confirm->setStyle(s);
  
  _loginWidgets->chevron1->setText(">");
  _loginWidgets->chevron2->setText(">");
  _loginWidgets->chevron1->setStyle(s);
  _loginWidgets->chevron2->setStyle(s);

  s.policeSize = 50;
  _loginWidgets->text1->setStyle(s);
  _loginWidgets->text2->setStyle(s);
  /* je gère le clic, le hover et le unhover */
  _loginWidgets->confirm->setText("Confirm");
  _loginWidgets->text1->setText("LOGIN");
  _loginWidgets->text2->setText("PASSWORD");
  _loginWidgets->confirm->setOnClick([](IWidget *w, CLICK)
				  {
				    auto eq = w->getEventQueue();
			            eq->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
				    std::cout << "Let's connect !" << std::endl;
				  });
  _loginWidgets->confirm->setOnHover(TextColorFocus);
  _loginWidgets->confirm->setOnLeaveHover(TextColorNoFocus);

  /* Je gère l'édition des 2 inputs */
  _loginWidgets->login->setOnFocus(TextColorFocus);
  _loginWidgets->login->setOnLeaveFocus(TextColorNoFocus);
  _loginWidgets->login->setOnTextEntered([](IWidget *w, const std::string &c)
  {
	  if (c[0] == '\t')
		  w->getEventQueue()->push(EventPart::Event(EventPart::Event::LOGIN_SWITCH_IMPUT));
	  else if (c[0] == '\n')
	    w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
	  else
	    textEntered(w, c);
  });
  _loginWidgets->password->setOnFocus(TextColorFocus);
  _loginWidgets->password->setOnLeaveFocus(TextColorNoFocus);
  _loginWidgets->password->setOnTextEntered([](IWidget *w, const std::string &c)
  {
	  if (c[0] == '\t')
		  w->getEventQueue()->push(EventPart::Event(EventPart::Event::LOGIN_SWITCH_IMPUT));
	  else if (c[0] == '\n')
	    w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
	  else
	    textEntered(w, c);
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
  _win->deleteAllWidgets();
  _hoverWidget = NULL;
  _focusWidget = NULL;
  if (_startWidgets)
    delete _startWidgets;
  if (_loginWidgets)
    delete _loginWidgets;
  if (_menuWidgets)
    delete _menuWidgets;
  if (_gameWidgets)
    delete _gameWidgets;
  _startWidgets = NULL;
  _loginWidgets = NULL;
  _menuWidgets = NULL;
  _gameWidgets = NULL;
}

void			GUI::setSoundManager(Audio::ISoundManager *sound)
{
  _audio = sound;
  loadSoundAssets();
}

void			GUI::showPopup(const std::string &string, int tMilli)
{
  if (_fadedWidget)
    {
      _win->deleteWidget(_fadedWidget);
    }
  // other init
  _fadedWidget = _win->addWidget(50, 350, (int) string.size() * 20, 50);
  auto style = _fadedWidget->getStyle();
  style.backgroundColor.green = 250;
  style.form = RECTANGLE;
  style.policeSize = 24;
  style.textColor.red = 250;
  _fadedWidget->setStyle(style);
  _fadedWidget->showPopup(string, tMilli);
}

void			GUI::loadSoundAssets()
{
  _audio->loadSound("../client/Assets/TitleScreen.ogg", "TitleScreen");
  _audio->loadSound("../client/Assets/Stage1.ogg", "Stage1");
  _audio->loadSound("../client/Assets/Stage2.ogg", "Stage2");
  _audio->loadSound("../client/Assets/Stage3.ogg", "Stage3");
  _audio->loadSound("../client/Assets/Stage4.ogg", "Stage4");
}

void			GUI::setRooms(const std::vector<DataRoom *> &d)
{
  std::cout << "Je recois un setRoom " << std::endl;
  _menuInfos = d;
}
