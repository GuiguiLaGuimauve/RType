#ifndef WINDOW_HH
#define WINDOW_HH

#include <list>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "IWindow.hh"

#include "Widget.hh"

namespace Gui
{
  class	Window : public IWindow
  {
  public:
    Window(int w = 500, int h = 350, const std::string &s = "");
    virtual ~Window();

    IWidget*		addWidget(int, int, int, int);
    void		deleteWidget(IWidget *);
    IWidget*		isThereWidget(int, int);
    void		drawAll();
    void		hide(bool);
    void		resize(int, int);
    void		setBackground(const std::string &);
    void		setEventQueue(EventPart::IEventQueue *);
    int			getWidth() const;
    int			getHeight() const;
    void		setTitle(const std::string &);
    std::string		getTitle() const;
    bool		isOpen();
    sf::RenderWindow	*getSfmlWinPtr();
  protected:
    int				_width;
    int				_height;
    std::string			_title;
    bool			_hidden;
    std::list<IWidget *>	_list;
    sf::RenderWindow   		*_win;
    sf::Sprite			_background;
    sf::Texture			_loadBackground;
    EventPart::IEventQueue     	*_queue;
  };
}

#endif
