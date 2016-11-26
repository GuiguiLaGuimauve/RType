#ifndef GUI_HH
#define GUI_HH

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstdio>

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
    struct Start
    {
      IWidget	*imput = NULL;
      IWidget	*button = NULL;
    };

    struct Login
    {
    };

    struct Menu
    {
    };

    struct Game
    {
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
  };
}

#endif
