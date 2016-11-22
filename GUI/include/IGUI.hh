#ifndef IGUI_HH
#define IGUI_HH

namespace Gui
{
  class IGUI
  {
  public:
    virtual ~IGUI(){};

    virtual void	callback() = 0;
    virtual void	displayGame() = 0;
    virtual void	displayStart() = 0;
    virtual void	displayMenu() = 0;
    virtual void	updateGameInfo(/*const GameInfo &*/) = 0;
  };
}

#endif
