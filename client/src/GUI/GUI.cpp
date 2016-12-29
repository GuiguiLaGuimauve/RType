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
	  case EventPart::Event::CLOSE_WINDOW:
		  ep = EventPart::Event(EventPart::Event::QUIT);
		  break;
	  case EventPart::Event::CLICK:
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
	  case EventPart::Event::MOUSE__MOVED:
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
	  case EventPart::Event::TEXT:
	  {
		  if (_focusWidget)
			  _focusWidget->onTextEntered(e.dataString["CHAR"]);
		  break;
	  }
	  case EventPart::Event::BUTTON_CONNECT:
	  {
		  std::string stringIp, stringPort;
		  auto tmpIp = _startWidgets->input->getText();
		  bool founded = false;
		  for (unsigned int i = 0; i < tmpIp.size(); i++)
		  {
			  if (tmpIp[i] == ':')
				  founded = true;
			  else
				  if (founded == false)
					  stringIp += tmpIp[i];
				  else
					  stringPort += tmpIp[i];
		  }
		  if (stringPort == "")
			  stringPort = "4242";
		  ep = EventPart::Event(EventPart::Event::TRY_CONNECT,
			  "IP", stringIp,
			  "PORT", stringPort);
		  break;
	  }
	  case EventPart::Event::BUTTON_LOGIN:
	  {
		  ep = EventPart::Event(EventPart::Event::TRY_LOGIN,
			  "LOGIN", _loginWidgets->login->getText(),
			  "PWD", _loginWidgets->password->getText());
		  break;
	  }
	  case EventPart::Event::BUTTON_CREATE_GAME:
	  {
	    ep = EventPart::Event(EventPart::Event::CREATE_GAME, "GAME_NAME", _menuWidgets->chooseRoomName->getText(),
				  "MAX_PLAYER", _menuWidgets->changeMaxPlayer->getText()[0] - 48);
	    break;
	  }
	  case EventPart::Event::BUTTON_JOIN_GAME:
	  {
		  ep = EventPart::Event(EventPart::Event::JOIN_GAME, "GAME_NAME", _currentGame->getName());
		  break;
	  }
	  case EventPart::Event::BUTTON_LEAVE_GAME:
	  {
		  ep = EventPart::Event(EventPart::Event::LEAVE_GAME, "GAME_NAME", _currentGame->getName());
		  break;
	  }
	  case EventPart::Event::BUTTON_WATCH_GAME:
	  {
		  ep = EventPart::Event(EventPart::Event::WATCH_GAME, "GAME_NAME", _currentGame->getName());
		  break;
	  }
	  case EventPart::Event::BUTTON_START_GAME:
	  {
		  ep = EventPart::Event(EventPart::Event::START_GAME, "GAME_NAME", _currentGame->getName());
		  break;
	  }
	  case EventPart::Event::BUTTON_SCROLL_UP:
	  {
		  if (_menuWidgets->itScroll < NB_GAME_SCROLL)
			  _menuWidgets->itScroll++;
		  updateGameInfo();
		  break;
	  }
	  case EventPart::Event::BUTTON_SCROLL_DOWN:
	  {
		  if (_menuWidgets->itScroll > 0)
			  _menuWidgets->itScroll--;
		  updateGameInfo();
		  break;
	  }
	  case EventPart::Event::KEY_ATTACK:
	  {
		  if (_gameWidgets)
			  ep = EventPart::Event(EventPart::Event::ATTACK, "X", _gameWidgets->_x, "Y", _gameWidgets->_y);
		  break;
	  }
	  case EventPart::Event::KEY_UP:
	  {
		  if (_gameWidgets)
		  {
		    std::cout << "J'augmente le Y qui passe de " << _gameWidgets->_y;
		    _gameWidgets->_y -= MOVE_SPEED;
		    ep = EventPart::Event(EventPart::Event::MOVE_UP);
		    std::cout << " à " << _gameWidgets->_y << std::endl;
		  }
		  break;
	  }
	  case EventPart::Event::KEY_DOWN:
	  {
		  if (_gameWidgets)
		  {
			  _gameWidgets->_y += MOVE_SPEED;
			  ep = EventPart::Event(EventPart::Event::MOVE_DOWN);
		  }
		  break;
	  }
	  case EventPart::Event::KEY_LEFT:
	  {
		  if (_gameWidgets)
		  {
			  _gameWidgets->_x -= MOVE_SPEED;
			  ep = EventPart::Event(EventPart::Event::MOVE_LEFT);
		  }
		  break;
	  }
	  case EventPart::Event::KEY_RIGHT:
	  {
		  if (_gameWidgets)
		  {
			  _gameWidgets->_x += MOVE_SPEED;
			  ep = EventPart::Event(EventPart::Event::MOVE_RIGHT);
		  }
		  break;
	  }
	  case EventPart::Event::LOGIN_SWITCH_IMPUT:
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
				  break;
			  nb++;
		  }
		  _currentGame = _menuInfos[nb + _menuWidgets->itScroll];
		  updateCurrentGame();
		  break;
	  }
	  case EventPart::Event::CHAT_SEND_MESSAGE :
	  {
		  ep = EventPart::Event(EventPart::Event::NEW_CHAT_MESSAGE, "MSG", _menuWidgets->chat->getAndClearInput());
		  break;
	  }
	  default:
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

  _audio->stopMusic();
  _audio->playMusic("Stage1");
  //this->_gameWidgets->levelId = ...
  _win->setBackground(PICTURE_BACKGROUND);
  //_win->setBackground(this->backgroundMap[this->_gameWidgets->levelId]);// Ou on pourrait set le levelId ?

  struct data oui;

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
  _startWidgets->input->setOnFocus(TextColorFocus);
  _startWidgets->input->setOnLeaveFocus(TextColorNoFocus);
  
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
	//_menuWidgets->chat = new Chat(_win, _guiQueue, 1200, 700);

	updateGameInfo();

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
	_menuWidgets->createGame = _win->addWidget(_win->getWidth() / 6, 5 * (_win->getHeight() / 6), 50, 60);
	_menuWidgets->createGame->setText("+");
	s = _menuWidgets->createGame->getStyle();
	s.policeSize = 60;
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
	// init chooseRoomName
	_menuWidgets->chooseRoomName = _win->addWidget(_menuWidgets->createGame->getX() + 150, _menuWidgets->createGame->getY() + 13, 300, 100);
	s = _menuWidgets->chooseRoomName->getStyle();
	s.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
	s.policeSize = 35;
	s.inputMode = true;
	_menuWidgets->chooseRoomName->setStyle(s);
	_menuWidgets->chooseRoomName->setOnTextEntered([](IWidget *w, const std::string &c)
	{
		if (c[0] == '\n' || c[0] == '\r')
			w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_CREATE_GAME));
		else
			textEntered(w, c);
	});
	_menuWidgets->chooseRoomName->setOnFocus(TextColorFocus);
	_menuWidgets->chooseRoomName->setOnLeaveFocus(TextColorNoFocus);
	// ############################################################
	// init changeMaxPlayer
	_menuWidgets->changeMaxPlayer = _win->addWidget(_menuWidgets->createGame->getX() + 75, _menuWidgets->createGame->getY() + 13, 50, 50);
	_menuWidgets->changeMaxPlayer->setText("4");
	s = _menuWidgets->changeMaxPlayer->getStyle();
	s.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
	s.policeSize = 35;
	_menuWidgets->changeMaxPlayer->setStyle(s);
	_menuWidgets->changeMaxPlayer->setOnHover(TextColorFocus);
	_menuWidgets->changeMaxPlayer->setOnLeaveHover(TextColorNoFocus);
	_menuWidgets->changeMaxPlayer->setOnClick(
		[](IWidget *w, CLICK)
	{
		auto tmpString = w->getText();
		tmpString[0] += 1;
		if (tmpString[0] > '4')
			tmpString[0] = '1';
		w->setText(tmpString);
	});
	// ##############################################################
	// init profile text
	_menuWidgets->profile = _win->addWidget(3 * (_win->getWidth() / 4), 3 * (_win->getHeight() / 4), _win->getHeight() / 4, 300);
	_menuWidgets->profile->setText("Profile");
	s = _menuWidgets->profile->getStyle();
	s.policeSize = 35;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->profile->setStyle(s);

	// init profile into
	_menuWidgets->profileInfo = _win->addWidget(3 * (_win->getWidth() / 4), 3 * (_win->getHeight() / 4) + 60, _win->getHeight() / 4, 300);
	if (_profile != NULL)
	{
	  _menuWidgets->profileInfo->setText("Name :\t" + _profile->getName()
					     + "\n\nSuccess :\t" + std::to_string(_profile->getGamePlayed())
					     + "/" + std::to_string(_profile->getStageSucceed()));
	  if (_menuWidgets->chooseRoomName)
	    if (_menuWidgets->chooseRoomName->getText() == "")
	      _menuWidgets->chooseRoomName->setText(_profile->getName() + "'s room");
	}
	s = _menuWidgets->profileInfo->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 255);
	_menuWidgets->profileInfo->setStyle(s);

	// bouton confirm pour join
	_menuWidgets->confirm = _win->addWidget(3 * (_win->getWidth() / 4), 600, 100, 35);
	_menuWidgets->confirm->setText("JOIN");
	s = _menuWidgets->confirm->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->confirm->setStyle(s);
	_menuWidgets->confirm->setOnClick([](IWidget *widget, CLICK)
	{
		std::cout << "Let's join !" << std::endl;
		auto eq = widget->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_JOIN_GAME));
	});
	_menuWidgets->confirm->setOnHover(TextColorFocus);
	_menuWidgets->confirm->setOnLeaveHover(TextColorNoFocus);

	// bouton confirm pour leave
	_menuWidgets->leaveButton = _win->addWidget(3 * (_win->getWidth() / 4), 600, 100, 35);
	_menuWidgets->leaveButton->setText("LEAVE");
	s = _menuWidgets->leaveButton->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->leaveButton->setStyle(s);
	_menuWidgets->leaveButton->setOnClick([](IWidget *widget, CLICK)
	{
		std::cout << "Let's leave !" << std::endl;
		auto eq = widget->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_LEAVE_GAME));
	});
	_menuWidgets->leaveButton->setOnHover(TextColorFocus);
	_menuWidgets->leaveButton->setOnLeaveHover(TextColorNoFocus);

	// bouton pour regarder la game
	_menuWidgets->watchButton = _win->addWidget(5 * (_win->getWidth() / 6), 600, 100, 35);
	_menuWidgets->watchButton->setText("WATCH");
	s = _menuWidgets->watchButton->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->watchButton->setStyle(s);
	_menuWidgets->watchButton->setOnClick([](IWidget *widget, CLICK)
	{
		std::cout << "Let's watch !" << std::endl;
		auto eq = widget->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_WATCH_GAME));
	});
	_menuWidgets->watchButton->setOnHover(TextColorFocus);
	_menuWidgets->watchButton->setOnLeaveHover(TextColorNoFocus);

	// bouton pour lancer la game
	_menuWidgets->startButton = _win->addWidget(5 * (_win->getWidth() / 6) + 120, 600, 100, 35);
	_menuWidgets->startButton->setText("START");
	s = _menuWidgets->startButton->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->startButton->setStyle(s);
	_menuWidgets->startButton->setOnClick([](IWidget *widget, CLICK)
	{
		std::cout << "Let's begin !" << std::endl;
		auto eq = widget->getEventQueue();
		eq->push(EventPart::Event(EventPart::Event::BUTTON_START_GAME));
	});
	_menuWidgets->startButton->setOnHover(TextColorFocus);
	_menuWidgets->startButton->setOnLeaveHover(TextColorNoFocus);
	// bouton pour monter dans la "scrollbar"
	_menuWidgets->upScrollButton = _win->addWidget(1100, 400, 40, 40);
	_menuWidgets->upScrollButton->setText("UP");
	s = _menuWidgets->upScrollButton->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->upScrollButton->setStyle(s);
	_menuWidgets->upScrollButton->setOnClick([](IWidget *widget, CLICK)
	{
		widget->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_SCROLL_UP));
	});
	_menuWidgets->upScrollButton->setOnHover(TextColorFocus);
	_menuWidgets->upScrollButton->setOnLeaveHover(TextColorNoFocus);
	// bouton pour descendre dans la "scrollbar"
	_menuWidgets->downScrollButton = _win->addWidget(1100, 300, 100, 40);
	_menuWidgets->downScrollButton->setText("DOWN");
	s = _menuWidgets->downScrollButton->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 0);
	_menuWidgets->downScrollButton->setStyle(s);
	_menuWidgets->downScrollButton->setOnClick([](IWidget *widget, CLICK)
	{
		widget->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_SCROLL_DOWN));
	});
	_menuWidgets->downScrollButton->setOnHover(TextColorFocus);
	_menuWidgets->downScrollButton->setOnLeaveHover(TextColorNoFocus);

	// affichage de toutes les rooms dans updateGameInfo()
	// affichage des infos de la game selectionnée
	_menuWidgets->selectedGame = _win->addWidget(3 * (_win->getWidth() / 4), 150, 0, 0);
	s = _menuWidgets->selectedGame->getStyle();
	s.policeSize = 20;
	s.textColor = Color(255, 215, 255);
	_menuWidgets->selectedGame->setStyle(s);
	updateCurrentGame();// A mettre a la reception d'un setDataRoom()
}

void		GUI::displayLogin()
{
  // Delete all unused Widgets
  deleteWidgets();

  // Create the Login widget
  _loginWidgets = new Login;

  // Background
  _win->setBackground(PICTURE_BACKGROUND);

  // Default text style
  Style s;
  s.form = NO_FORM;
  s.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  s.policeSize = 35;

  // Default text style
  Style title;
  title.form = NO_FORM;
  title.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  title.policeSize = 50;

  // Default input style
  Style in;
  in.form = NO_FORM;
  in.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  in.policeSize = 35;
  in.inputMode = true;

  // Default input password style
  Style p;
  p.form = NO_FORM;
  p.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
  p.policeSize = 35;
  p.password = true;
  p.inputMode = true;
    
  // Input : Login
  _loginWidgets->login = _win->addWidget(0, 280, 1920, 40);
  _loginWidgets->login->setStyle(in);
  _loginWidgets->login->setOnFocus(TextColorFocus);
  _loginWidgets->login->setOnLeaveFocus(TextColorNoFocus);
  _loginWidgets->login->move((GUI_WIDTH - _loginWidgets->login->getTextWidth()) / 2, 280);
  _loginWidgets->login->setOnTextEntered([](IWidget *w, const std::string &c)
  {
	  if (c[0] == '\t')
		  w->getEventQueue()->push(EventPart::Event(EventPart::Event::LOGIN_SWITCH_IMPUT));
	  else if (c[0] == '\n' || c[0] == '\r')
		  w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
	  else
		  textEntered(w, c);
	  w->move((GUI_WIDTH - w->getTextWidth()) / 2, 280);
  });

  // Input : Password
  _loginWidgets->password = _win->addWidget(0, 640, 1920, 40);
  _loginWidgets->password->setStyle(p);
  _loginWidgets->password->setOnFocus(TextColorFocus);
  _loginWidgets->password->setOnLeaveFocus(TextColorNoFocus);
  _loginWidgets->password->move((GUI_WIDTH - _loginWidgets->password->getTextWidth()) / 2, 640);
  _loginWidgets->password->setOnTextEntered([](IWidget *w, const std::string &c)
  {
	  if (c[0] == '\t')
		  w->getEventQueue()->push(EventPart::Event(EventPart::Event::LOGIN_SWITCH_IMPUT));
	  else if (c[0] == '\n' || c[0] == '\r')
		  w->getEventQueue()->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
	  else
		  textEntered(w, c);
	  w->move((GUI_WIDTH - w->getTextWidth()) / 2, 640);
  });
  
  // Button confirm
  _loginWidgets->confirm = _win->addWidget(0, 820, 250, 50);
  _loginWidgets->confirm->setStyle(s);
  _loginWidgets->confirm->setOnClick([](IWidget *w, CLICK)
  {
	  auto eq = w->getEventQueue();
	  eq->push(EventPart::Event(EventPart::Event::BUTTON_LOGIN));
	  std::cout << "Let's connect !" << std::endl;
  });
  _loginWidgets->confirm->setOnHover(TextColorFocus);
  _loginWidgets->confirm->setOnLeaveHover(TextColorNoFocus);
  _loginWidgets->confirm->setText("Confirm");
  _loginWidgets->confirm->move((GUI_WIDTH - _loginWidgets->confirm->getTextWidth()) / 2, 820);

  // Title : Login
  _loginWidgets->text1 = _win->addWidget(0, 180, 0, 0);
  _loginWidgets->text1->setText("LOGIN");
  _loginWidgets->text1->setStyle(title);
  _loginWidgets->text1->move((GUI_WIDTH - _loginWidgets->text1->getTextWidth()) / 2, 180);

  // Title : Password
  _loginWidgets->text2 = _win->addWidget(0, 540, 0, 0);
  _loginWidgets->text2->setText("PASSWORD");
  _loginWidgets->text2->setStyle(title);
  _loginWidgets->text2->move((GUI_WIDTH - _loginWidgets->text2->getTextWidth()) / 2, 540);

  // Default focus
  _focusWidget = _loginWidgets->login;
  _focusWidget->onFocus();
}

void		GUI::updateGameInfo(/*const GameInfo &*/)
{
  // Todo : Update game info
  int i = 0;
  int nb = 0;

  if (_menuWidgets)
    cleanGames();
  std::cout << "scroll iterator = " << _menuWidgets->itScroll << std::endl;
  if (_menuWidgets->itScroll >= _menuInfos.size())
	  _menuWidgets->itScroll = (unsigned int) _menuInfos.size() - 1;
  _menuWidgets->itScroll = ((int)_menuWidgets->itScroll < 0) ? 0 : _menuWidgets->itScroll;
  for (auto elem : _menuInfos)
    {
	  if (nb >= NB_GAME_SCROLL + (int)_menuWidgets->itScroll || (int)_menuWidgets->itScroll > nb)
	  {
		  nb++;
		  continue;
	  }
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
	  nb++;
    }
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
  _fadedWidget->move((_win->getWidth() - _fadedWidget->getTextWidth()) / 2, 1000);
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
  if (_currentGame)
    {
      bool	update = false;
      for (auto elem : d)
	{
	  if (elem->getName() == _currentGame->getName())
	    {
	      _currentGame = elem;
	      update = true;
	    }
	}
      if (update == false)
	_currentGame = NULL;
    }
  updateGameInfo();
  updateCurrentGame();
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
  if (!_currentGame)
    if (_menuInfos.size() != 0)
      _currentGame = _menuInfos[0];

  // affichage du texte
	if (_currentGame)
	{
		std::stringstream ss;
		ss << "Name : " << _currentGame->getName();
		if (_currentGame->getWatchers().size() != 0)
		  ss << "\n\nViewers : " << _currentGame->getWatchers().size();
		ss << "\n\nPlayers :\n";
		for (unsigned int i = 0; i < _currentGame->getPlayers().size(); i++)
		  {
		    ss << "\n - ";
		    ss << _currentGame->getPlayers()[i]->getName() << "\t";
		    ss << _currentGame->getPlayers()[i]->getGamePlayed() << "/";
		    ss << _currentGame->getPlayers()[i]->getStageSucceed();
		  }
		_menuWidgets->selectedGame->setText(ss.str());
	}
	else
	{
		_menuWidgets->selectedGame->setText("");
	}
	// affichage du bouton join
	if (_currentGame && _currentGame->getNbPlayers() < _currentGame->getMaxPlayers() && _currentGame->getStarted() == false
	    && (isInGame(_currentGame->getPlayers()) == false && isInGame(_currentGame->getWatchers()) == false))
	{
	  _menuWidgets->confirm->setText("JOIN");
	  _menuWidgets->confirm->resize(100, 35);
	}
	else
	{
	  _menuWidgets->confirm->setText("");
	  _menuWidgets->confirm->resize(0, 0);
	}
	// affichage du bouton leave
	if (_currentGame && _profile && (isInGame(_currentGame->getPlayers()) == true
					 || isInGame(_currentGame->getWatchers()) == true))
	{
	  _menuWidgets->leaveButton->setText("LEAVE");
	  _menuWidgets->leaveButton->resize(100, 35);
	}
	else
	{
	  _menuWidgets->leaveButton->setText("");
	  _menuWidgets->leaveButton->resize(0, 0);
	}
	// bouton watch
	// affichage du bouton watch
	if (_currentGame && isInGame(_currentGame->getPlayers()) == false
	    && isInGame(_currentGame->getWatchers()) == false)
	{
		_menuWidgets->watchButton->setText("WATCH");
		_menuWidgets->watchButton->resize(100, 35);
	}
	else
	{
		_menuWidgets->watchButton->setText("");
		_menuWidgets->watchButton->resize(0, 0);
	}
	// bouton start
	// affichage du bouton start
	if (_currentGame && _profile && _currentGame->getPlayers()[0]->getName() == _profile->getName())
	{
	  _menuWidgets->startButton->setText("START");
	  _menuWidgets->startButton->resize(100, 35);
	}
	else
	{
	  _menuWidgets->startButton->setText("");
	  _menuWidgets->startButton->resize(0, 0);
	}
	// bouton scroll down et scroll up
	if (_currentGame && _menuInfos.size() > NB_GAME_SCROLL)
	{
		_menuWidgets->downScrollButton->setText("UP");
		_menuWidgets->downScrollButton->resize(40, 40);
		_menuWidgets->upScrollButton->setText("DOWN");
		_menuWidgets->upScrollButton->resize(100, 40);
	}
	else
	{
		_menuWidgets->downScrollButton->setText("");
		_menuWidgets->downScrollButton->resize(0, 0);
		_menuWidgets->upScrollButton->setText("");
		_menuWidgets->upScrollButton->resize(0, 0);
	}
}

bool	GUI::isInGame(std::vector<DataPlayer*> roomPlayers)
{
  if (_profile)
    for (auto elem : roomPlayers)
      {
	if (elem->getName() == _profile->getName())
	  return (true);
      }
  return (false);
}

void	GUI::cleanGames()
{
  if (_menuWidgets->games.size() != 0)
    {
      for (auto elem : _menuWidgets->games)
	{
	  if (elem == _focusWidget)
	    _focusWidget = NULL;
	  if (elem == _hoverWidget)
	    _hoverWidget = NULL;
	  _win->deleteWidget(elem);
	}
      _menuWidgets->games.clear();
    }
}

void	GUI::setPlayersPositions(const std::vector<DataPlayer *> &dp)
{
  int	red[4] = {3, 161, 36, 255};
  int	green[4] = {198, 0, 212, 3};
  int	blue[4] = {252, 252, 43, 5};

  if (_gameWidgets == NULL)
    return;
  for (auto elem : _playersPos)
    {
      _win->deleteWidget(elem);
    }
  _playersPos.clear();
  if (dp.size())
    for (auto elem : dp)
      {
	IWidget	*temp;
	Style	s;
	
	/* Ajout du Widget d'HUD pour le joueur i */
	temp = _win->addWidget((_win->getWidth() / 4) * (int)(elem->getId()) + 100, 30, _win->getWidth() / (int) dp.size(), 100);
	temp->setText(" " + std::to_string(elem->getHealth()) + " %");
	s = temp->getStyle();
	s.textColor = Color(red[elem->getId()], green[elem->getId()], blue[elem->getId()]);
	s.policeSize = 60;
	s.image = "Heart" + std::to_string((elem->getId() + 1));
	temp->setStyle(s);
	_playersPos.push_back(temp);
	
	/* Ajout du Sprite pour le joueur i */
	temp = _win->addWidget(elem->getX(), 100 + elem->getY(), 0, 0);
	s.image = "Ship" + std::to_string((elem->getId() + 1));
	temp->setStyle(s);
	_playersPos.push_back(temp);
      }
}

void	GUI::setShootsPos(const std::vector<Packet::DataShoot *> &ds)
{
  if (_gameWidgets == NULL)
    return;
  for (auto elem : _shotsPos)
    {
      _win->deleteWidget(elem);
    }
  _shotsPos.clear();
  if (ds.size())
    for (auto elem : ds)
      {
	IWidget	*temp = _win->addWidget(elem->getX(), 100 + elem->getY(), 0, 0);
	Style	s = temp->getStyle();
	
	/* Ajout du Widget de tir */
	//s.image = "Shot-" + std::to_string((elem->getId() + 1));
	s.image = "Shot-1";
	temp->setStyle(s);
	_shotsPos.push_back(temp);
      }
}

uint64_t	GUI::getPosX()
{
  if (_gameWidgets == NULL)
    return (0);
  return (_gameWidgets->_x);
}


uint64_t	GUI::getPosY()
{
  if (_gameWidgets == NULL)
    return (0);
  return (_gameWidgets->_y);
}

void	GUI::setPosX(uint64_t x)
{
  if (_gameWidgets != NULL)
    _gameWidgets->_x = x;
}

void	GUI::setPosY(uint64_t y)
{
  if (_gameWidgets != NULL)
    _gameWidgets->_y = y;
}

void	GUI::addChatMessage(const std::string &s)
{
	if (_menuWidgets && _menuWidgets->chat)
		_menuWidgets->chat->post(s);
}
