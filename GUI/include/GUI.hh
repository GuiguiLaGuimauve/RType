#define GUI_HH
#ifndef GUI_HH

#include <string>
#include <map>
#include <vectorm>

#include "IGUI.hh"
#include "IWindow.hh"
#include "IWidget.hh"
#include "ISoundManager.hh"

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
  protected:
    
  };
}

#endif
