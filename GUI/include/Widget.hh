#ifndef WIDGET_HH
#define WIDGET_HH

#include <SFML/Graphics.hpp>

#include "IWidget.hh"

namespace Gui
{
  class Widget : public IWidget
  {
  public:
    Widget(sf::Window *, int x = 0, int y = 0, int width = 0, int height = 0,
	   const std::string &text = "");
    virtual ~Widget();

    void                draw();
    void                setEventQueue(EventPart::IEventQueue *);
    bool                collision(int, int) const;
    void                resize(int, int);
    void                move(int, int);
    void                setText(const std::string &);
    std::string         getText() const;
    int                 getX() const;
    int                 getY() const;
    int                 getWidth() const;
    int                 getHeight() const;
    void                onClick(CLICK);
    void                onFocus();
    void                onHover();
    void                setOnClick(ptrClick);
    void                setOnFocus(ptrFocus);
    void                setOnHover(ptrFocus);
    void                setStyle(const Style &);
    Style               getStyle() const;
  protected:
    sf::Window				*_win;
    int					_x;
    int					_y;
    int					_width;
    int					_height;
    std::string				_text;
    ptrClick				_ptrClick;
    ptrFocus				_ptrFocus;
    ptrFocus				_ptrHover;
    EventPart::IEventQueue		*_eventQueue;
    Style				_style;

  };
}


#endif
