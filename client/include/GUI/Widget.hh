#ifndef WIDGET_HH
#define WIDGET_HH

#include <iostream>

#include <SFML/Graphics.hpp>

#include "IWidget.hh"
#include "Clock.hpp"

namespace Gui
{
  class Widget : public IWidget
  {
  public:
    Widget(sf::RenderWindow *, int x = 0, int y = 0, int width = 0,
	   int height = 0, const std::string &text = "");
    virtual ~Widget();

    void                draw();
    void                setEventQueue(EventPart::IEventQueue *);
    EventPart::IEventQueue		*getEventQueue() const;
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
    void		onLeaveFocus();
    void                onHover();
    void		onLeaveHover();
    void		onTextEntered(const std::string &c);
    void                setOnClick(ptrClick);
    void                setOnFocus(ptrFocus);
    void		setOnLeaveFocus(ptrFocus);
    void                setOnHover(ptrFocus);
    void		setOnLeaveHover(ptrFocus);
    void		setOnTextEntered(ptrText);
    void                setStyle(const Style &);
    Style               getStyle() const;
    void	showPopup(const std::string &s, int tMilli);
	int		getTextWidth();
  protected:
    sf::RenderWindow	       		*_win;
    int					_x;
    int					_y;
    int					_width;
    int					_height;
    std::string				_text;
    ptrClick				_ptrClick;
    ptrFocus				_ptrFocus;
    ptrFocus				_ptrLeaveFocus;
    ptrFocus				_ptrHover;
    ptrFocus				_ptrLeaveHover;
    ptrText				_ptrText;
    EventPart::IEventQueue		*_eventQueue;
    Style				_style;
    // sfml stuffs
    sf::CircleShape			_circle;
    sf::RectangleShape			_rectangle;
    sf::Text				_sfmlText;
    sf::Font				_font;
    sf::Sprite				_background;
    //    sf::Texture				_loadBackground;
    Clock	clock;
    int		timeLimit = -1;
	// animations
	std::map<std::string, std::vector < sf::Sprite > > animations;
  };
}

#endif
