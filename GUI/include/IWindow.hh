#ifndef IWINDOW_HH
#define IWINDOW_HH

#include <string>

#include "IWidget.hh"

namespace Gui
{
  class IWindow
  {
  public:
    virtual ~IWindow(){};

    virtual IWidget		*addWidget(int, int, int, int) = 0;
    virtual void		deleteWidget(IWidget *) = 0;
    virtual void		drawAll() = 0;
    virtual void		hide(bool) = 0;
    virtual void		resize(int, int) = 0;
    virtual void		setBackground(const std::string &) = 0;
    virtual void		setEventQueue(IEventQueue *) = 0;
    virtual int			getWidth() const = 0;
    virtual int			getHeight() const = 0;
  };
}

#endif
