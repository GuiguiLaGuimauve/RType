#ifndef IGUI_HH
#define IGUI_HH

#include	<vector>
#include	"IEventQueue.hh"
#include	"ISoundManager.hh"
#include	"DataRoom.hpp"

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
    virtual void	displayLogin() = 0;
    virtual void	updateGameInfo(/*const GameInfo &*/) = 0;
    virtual void	setEventQueue(EventPart::IEventQueue *) = 0;
    virtual void	setSoundManager(Audio::ISoundManager *) = 0;
    virtual void	showPopup(const std::string &s, int tMilli = 2000) = 0;
    virtual void	setRooms(const std::vector<DataRoom *> &) = 0;
  };
}

#endif
