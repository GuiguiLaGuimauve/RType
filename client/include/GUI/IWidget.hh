#ifndef IWIDGET_HH
#define IWIDGET_HH

#include <string>

#include "Click.hh"
#include "Style.hh"
#include "IEventQueue.hh"

namespace Gui
{
  class IWidget
  {
  public:
    virtual ~IWidget(){};

    typedef void (*ptrClick)(IWidget *, CLICK);
    typedef void (*ptrText)(IWidget *, const std::string &c);
    typedef void (*ptrFocus)(IWidget *);

    virtual void		draw() = 0;
    virtual void		setEventQueue(EventPart::IEventQueue *) = 0;
    virtual EventPart::IEventQueue		*getEventQueue() const = 0;
    virtual bool		collision(int, int) const = 0;
    virtual void		resize(int, int) = 0;
    virtual void		move(int, int) = 0;
    virtual void		setText(const std::string &) = 0;
    virtual std::string		getText() const = 0;
    virtual int			getX() const = 0;
    virtual int			getY() const = 0;
    virtual int			getWidth() const = 0;
    virtual int			getHeight() const = 0;
    virtual void		onClick(CLICK) = 0;
    virtual void		onFocus() = 0;
    virtual void		onLeaveFocus() = 0;
    virtual void		onHover() = 0;
    virtual void		onLeaveHover() = 0;
    virtual void		onTextEntered(const std::string &c) = 0;
    virtual void		setOnClick(ptrClick) = 0;
    virtual void		setOnFocus(ptrFocus) = 0;
    virtual void		setOnLeaveFocus(ptrFocus) = 0;
    virtual void		setOnHover(ptrFocus) = 0;
    virtual void		setOnLeaveHover(ptrFocus) = 0;
    virtual void		setOnTextEntered(ptrText) = 0;
    virtual void		setStyle(const Style &) = 0;
    virtual Style		getStyle() const = 0;
    virtual void	showPopup(const std::string &s, int tMilli) = 0;
	virtual int		getTextWidth() = 0;
  };
}

#endif
