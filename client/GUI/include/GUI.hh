#ifndef GUI_HH
#define GUI_HH

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <stdlib.h>

#include "IGUI.hh"

#include "Widget.hh"
#include "Window.hh"
#include "SoundManager.hh"
#include "GuiEventManager.hh"
#include "EventQueue.hh"
#include "Key.hh"

namespace Gui
{
  class GUI: public IGUI
  {
  protected:

    struct	data
    {
      int x = 50;
      int y = 50;
      int health = 100;
      //char *name = "1";
      int	type = 1;
    };

    struct Start
    {
      IWidget	*imput = NULL;
      IWidget	*button = NULL;
    };

    struct Login
    {
      IWidget	*login = NULL;
      IWidget	*password = NULL;
      IWidget	*confirm = NULL;
    };

    struct Menu
    {
      IWidget	*GameContainer = NULL;
      //std::vector<IWidget*>	Games = NULL;
      IWidget	*profile = NULL;
      IWidget	*createGame = NULL;
      IWidget	*confirm = NULL;
      /* Vecteur de joueurs connectés */
      /* Container des joueurs connectés */
    };

    struct Game
    {
      uint8_t			levelId;
      IWidget			*layout = NULL;
      //std::vector<IWidget>	*entities = NULL;
      //std::vector<Shoot>	shootsVector;
      /*
	char	*name;
	uint8_t	x;
	uint8_t	y;
       */
      //std::vector<Player>	playerVector;
      /*
	uint8_t id;
	uint8_t	x;
	uint8_t	y;
	uint8_t	health;
       */
      //std::vector<Monster>	monsterVector;
      /*
	uint8_t	type;
	uint8_t	x;
	uint8_t	y;
       */
      //std::vector<Environment>	envVector;
      /*
	uint8_t	type;
	uint8_t	x;
	uint8_t	y;
       */
      //Music Packet ?
    };
  public:
    GUI();
    virtual ~GUI();
    
    void        callback();
    void        displayGame();
    void        displayStart();
    void        displayMenu();
    void	displayLogin();
    void        updateGameInfo(/*const GameInfo &*/);
    void	setEventQueue(EventPart::IEventQueue *);
  protected:
    void	deleteWidgets();
  protected:
    Audio::ISoundManager	*_audio;
    IWindow			*_win;
    IGuiEventManager		*_userEvents;
    //    GameInfo			_gameInfo;
    EventPart::IEventQueue	*_coreQueue;
    EventPart::IEventQueue	*_guiQueue;
    // gestion effets graphiques
    IWidget			*_hoverWidget = NULL;
    IWidget			*_focusWidget = NULL;
    // liste des widgets dans les structures
    Start	*_startWidgets = NULL;
    Login	*_loginWidgets = NULL;
    Menu	*_menuWidgets = NULL;
    Game	*_gameWidgets = NULL;
    // Map de musique ?
    std::vector<data>	players;
    std::vector<data>	shots;
    std::vector<data>	envs;
    std::vector<data>	monsters;
  };
}

#endif
