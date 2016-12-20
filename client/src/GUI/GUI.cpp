#include "GUI.hh"
#include "SpriteMap.hpp"
#include "Assets.hh"

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
            auto tmpIp = _startWidgets->input->getText();
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
		ep = EventPart::Event(EventPart::Event::JOIN_GAME, "GAME_NAME", _currentGame->getName());
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
	case EventPart::Event::CLICK_SELECT_GAME:
	{
		int nb = 0;
		for (auto room : _menuWidgets->games)
		{
			if (room->getX() == e.dataInt["X"] && room->getY() == e.dataInt["Y"])
				_menuWidgets->selectedRoom = nb;
			else
				nb++;
		}
		_currentGame = _menuInfos[0];
		updateCurrentGame();
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
  _win->setBackground(PICTURE_BACKGROUND);
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
  // Delete widget
  deleteWidgets();

  // Set Background
  _win->setBackground(PICTURE_BACKGROUND);

  // Launch music
  _audio->playMusic("TitleScreen");
  
  // Init startWidgets
  _startWidgets = new Start;

  // Default text style
  Style	s;
  s.form = NO_FORM;
  s.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  s.policeSize = 35;

  // Default input style
  Style	inputStyle;
  inputStyle.form = NO_FORM;
  inputStyle.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  inputStyle.policeSize = 35;
  inputStyle.inputMode = true;

  // Sprite : Logo
  _startWidgets->title = _win->addWidget((GUI_WIDTH - 445) / 2, GUI_HEIGHT / 6, 0, 0);
  Style	titleStyle;
  titleStyle.image = "Logo";
  _startWidgets->title->setStyle(titleStyle);
  
  // Text : Enter the address
  _startWidgets->texte = _win->addWidget(0, 0, GUI_WIDTH / 2, 100);
  _startWidgets->texte->setText(TEXT_ADDRESS);
  _startWidgets->texte->setStyle(s);
  _startWidgets->texte->move((GUI_WIDTH - _startWidgets->texte->getTextWidth()) / 2, 400);

  // Input : address
  _startWidgets->input = _win->addWidget(0, 0, GUI_WIDTH / 2, 175);
  _startWidgets->input->setText(TEXT_DEFAULT_IP);
  _startWidgets->input->setStyle(inputStyle);
  _startWidgets->input->move((GUI_WIDTH - _startWidgets->input->getTextWidth()) / 2, 600);
  
  // Button : connect
  _startWidgets->button = _win->addWidget(0, 0, 250, 40);
  _startWidgets->button->setText(TEXT_CONNECT);
  _startWidgets->button->setStyle(s);
  _startWidgets->button->move((GUI_WIDTH - _startWidgets->button->getTextWidth()) / 2, 800);
  
  // On click
  _startWidgets->button->setOnClick([](IWidget *fuckingButton, CLICK)
	{
		auto eq = fuckingButton->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_CONNECT));
		std::cout << "try connect" << std::endl;
	});
  _startWidgets->button->setOnHover(TextColorFocus);
  _startWidgets->button->setOnLeaveHover(TextColorNoFocus);

  // On Key Pressed
  _startWidgets->input->setOnTextEntered([](IWidget *w, const std::string &c)
  {
	  // Catch event
	  if (c[0] == '\n' || c[0] == '\r')
		w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_CONNECT));
	  else
	    textEntered(w, c);

	  // Move text
	  w->move((GUI_WIDTH - w->getTextWidth()) / 2, 600);
  });

  // Defaut focus
  _focusWidget = _startWidgets->input;
  _focusWidget->onFocus();
}

void		GUI::displayMenu()
{
	Style		s;
	deleteWidgets();
	_win->setBackground(PICTURE_BACKGROUND);
	_menuWidgets = new Menu;

	// init le gameText
	_menuWidgets->GameText = _win->addWidget(_win->getWidth() / 6, 100, 0, 0);
	_menuWidgets->GameText->setText("Games");
	s = _menuWidgets->GameText->getStyle();
	s.policeSize = 35;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->GameText->setStyle(s);
	// init gameInfo
	_menuWidgets->GameInfos = _win->addWidget(3 * (_win->getWidth() / 4), 100, 1000, 300);
	_menuWidgets->GameInfos->setText("Infos");
	s = _menuWidgets->GameInfos->getStyle();
	s.policeSize = 35;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->GameInfos->setStyle(s);
	// init createGame
	_menuWidgets->createGame = _win->addWidget(3 * (_win->getWidth() / 4), 5 * (_win->getHeight() / 6), 50, 60);
	_menuWidgets->createGame->setText("+");
	s = _menuWidgets->createGame->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->createGame->setStyle(s);
	_menuWidgets->createGame->setOnClick([](IWidget *widget, CLICK)
	{
		std::cout << "Let's try to create a game !" << std::endl;
		auto eq = widget->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_CREATE_GAME));
	});
	_menuWidgets->createGame->setOnHover(TextColorFocus);
	_menuWidgets->createGame->setOnLeaveHover(TextColorNoFocus);
	// init profile text
	_menuWidgets->profile = _win->addWidget(3 * (_win->getWidth() / 4), _win->getHeight() / 2, _win->getHeight() / 4, 300);
	_menuWidgets->profile->setText("Profile");
	s = _menuWidgets->profile->getStyle();
	s.policeSize = 35;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->profile->setStyle(s);
	// init profile into
	_menuWidgets->profileInfo = _win->addWidget(3 * (_win->getWidth() / 4), _win->getHeight() / 2 + 100, _win->getHeight() / 4, 300);
	if (_profile != NULL)
	{
		_menuWidgets->profileInfo->setText("Name :\t" + _profile->getName()
			+ "\nPlay/Succes :\t" + std::to_string(_profile->getGamePlayed())
			+ "/" + std::to_string(_profile->getStageSucceed()));
	}
	s = _menuWidgets->profileInfo->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 255);
	s = _menuWidgets->profileInfo->getStyle();
	// bouton confirm pour join
	_menuWidgets->confirm = _win->addWidget(4 * (_win->getWidth() / 5), 5 * (_win->getHeight() / 6) + 10, 135, 45);
	_menuWidgets->confirm->setText("Join");
	s = _menuWidgets->confirm->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->confirm->setStyle(s);
	_menuWidgets->confirm->setOnClick([](IWidget *widget, CLICK)
	{
		std::cout << "Let's connect !" << std::endl;
		auto eq = widget->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_JOIN_GAME));
	});
	_menuWidgets->confirm->setOnHover(TextColorFocus);
	_menuWidgets->confirm->setOnLeaveHover(TextColorNoFocus);
	//std::cout << "A l'initialisation, la size de mes Rooms est " << _menuInfos.size() << std::endl;
	// affichage de toutes les rooms
	int i = 0;
	for (auto elem : _menuInfos)
	{
		// crée un widget pour chaque room
		IWidget *temp = _win->addWidget(_win->getWidth() / 6, 100 + ((i + 1) * 100), _win->getWidth() / 2, 100);
		Style sgame = temp->getStyle();
		sgame.policeSize = 20;
		sgame.textColor = Color(255, 215, 255);
		temp->setStyle(sgame);
		temp->setText(elem->getName() + "\t" + std::to_string(elem->getPlayers().size())
			+ "/" + std::to_string(elem->getMaxPlayers())
			+ "\tStage " + std::to_string(elem->getLevel() + 1));
		temp->setOnClick([](IWidget *w, CLICK)
		{
			w->getEventQueue()->push(EventPart::Event(EventPart::Event::CLICK_SELECT_GAME, "X", w->getX(), "Y", w->getY()));
		});
		_menuWidgets->games.push_back(temp);
		i++;
	}
	// affichage des infos de la game selectionnée
	_menuWidgets->selectedGame = _win->addWidget(800, 300, 0, 0);
	s = _menuWidgets->selectedGame->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 255);
	_menuWidgets->selectedGame->setStyle(s);
	updateCurrentGame();
}

void		GUI::displayLogin()
{
  deleteWidgets();
  _loginWidgets = new Login;
  _win->setBackground(PICTURE_BACKGROUND);
  _loginWidgets->login = _win->addWidget(_win->getWidth() / 3, _win->getHeight() / 4, _win->getWidth() / 2, 180);
  _loginWidgets->password = _win->addWidget(_win->getWidth() / 3, _win->getHeight() / 2, _win->getWidth() / 2, 180);
  _loginWidgets->confirm = _win->addWidget(_win->getWidth() / 3 + 150, (2 * _win->getHeight()) / 3,  250, 50);
  _loginWidgets->text1 = _win->addWidget(_win->getWidth() / 3 + 150, _win->getHeight() / 4 - 100, 0, 0);
  _loginWidgets->text2 = _win->addWidget(_win->getWidth() / 3 + 100, _win->getHeight() / 2 - 100, 0, 0);
  _loginWidgets->chevron1 = _win->addWidget(_win->getWidth() / 3 - 200, _win->getHeight() / 4, 0, 0);
  _loginWidgets->chevron2 = _win->addWidget(_win->getWidth() / 3 - 200, _win->getHeight() / 2, 0, 0);

  Style		s = _loginWidgets->login->getStyle();
  s.form = NO_FORM;
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
	  else if (c[0] == '\n' || c[0] == '\r')
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
	  else if (c[0] == '\n' || c[0] == '\r')
	    w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
	  else
	    textEntered(w, c);
  });

  // ergonomie focus
  _focusWidget = _loginWidgets->login;
  _focusWidget->onFocus();
}

void		GUI::updateGameInfo(/*const GameInfo &*/)
{
	// Todo : Update game info
}

void		GUI::setEventQueue(EventPart::IEventQueue *eq)
{
  // Define Event Queue
  _coreQueue = eq;
}

void		GUI::deleteWidgets()
{
  // Init widget
  _win->deleteAllWidgets();
  _hoverWidget = NULL;
  _focusWidget = NULL;

  // Delete defined widgets
  if (_startWidgets)
    delete _startWidgets;
  if (_loginWidgets)
    delete _loginWidgets;
  if (_menuWidgets)
    delete _menuWidgets;
  if (_gameWidgets)
    delete _gameWidgets;

  // Set to NULL
  _startWidgets = NULL;
  _loginWidgets = NULL;
  _menuWidgets = NULL;
  _gameWidgets = NULL;
}

void			GUI::setSoundManager(Audio::ISoundManager *sound)
{
  // Set Sound Manager
  _audio = sound;
  loadSoundAssets();
}

void			GUI::showPopup(const std::string &string, int tMilli)
{
  // Delete old popup
  if (_fadedWidget)
	_win->deleteWidget(_fadedWidget);

  // Create widget
  _fadedWidget = _win->addWidget(0, 0, 1920, 40);

  // Get style
  auto style = _fadedWidget->getStyle();

  // Edit style
  style.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  style.policeSize = 24;

  // Set style
  _fadedWidget->setStyle(style);

  // Show Popup
  _fadedWidget->showPopup(string, tMilli);

  // Define position
  _fadedWidget->move((_win->getWidth() - _fadedWidget->getTextWidth()) / 2, 1040);
}

void			GUI::loadSoundAssets()
{
	// Load title screen sound
	_audio->loadSound(SOUNDS_TITLESCREEN, "TitleScreen");

	// Load sounds for levels
	_audio->loadSound(SOUNDS_STAGE1, "Stage1");
	_audio->loadSound(SOUNDS_STAGE2, "Stage2");
	_audio->loadSound(SOUNDS_STAGE3, "Stage3");
	_audio->loadSound(SOUNDS_STAGE4, "Stage4");
}

void			GUI::setRooms(const std::vector<DataRoom *> &d)
{
  std::cout << "Je recois un setRoom " << std::endl;
  _menuInfos = d;
  updateGameInfo();
}

void			GUI::setProfile(DataPlayer *p)
{
  std::cout << "Je met a jour le profile, mon nom est " << p->getName()
	    << " mon nombre partie jouees/gagnes" << std::to_string(p->getGamePlayed())
	    << "/" << std::to_string(p->getStageSucceed()) << std::endl;
  _profile = p;
}

void		GUI::updateCurrentGame()
{
	if (_currentGame)
	{
		_menuWidgets->selectedGame->setText(_currentGame->getName());
		_menuWidgets->confirm->setText("JOIN");
		_menuWidgets->confirm->resize(200, 200);
	}
	else
	{
		_menuWidgets->confirm->setText("");
		_menuWidgets->confirm->resize(0, 0);
	}
}