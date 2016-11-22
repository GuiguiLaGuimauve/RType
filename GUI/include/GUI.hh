#ifndef GUI_HH
#define GUI_HH

#include <string>
#include <map>
#include <vector>

#include "IGUI.hh"
#include "IWidget.hh"

#include "Window.hh"
#include "SoundManager.hh"
#include "KeyboardManager.hh"
#include "EventQueue.hh"

namespace Gui
{
  class GUI: public IGUI
  {
  public:
    GUI();
    virtual ~GUI();
    
    void        callback();
    void        displayGame();
    void        displayStart();
    void        displayMenu();
    void        updateGameInfo(/*const GameInfo &*/);
    void	setEventQueue(EventPart::IEventQueue *);
  protected:
    Audio::ISoundManager	*_audio;
    IWindow			*_win;
    IKeyboardManager		*_keyboard;
    //    GameInfo			_gameInfo;
    EventPart::IEventQueue	*_coreQueue;
    EventPart::IEventQueue	*_guiQueue;
  };
}

#endif
