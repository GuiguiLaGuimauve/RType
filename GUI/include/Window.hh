#ifndef WINDOW_HH
#define WINDOW_HH

#include <list>

#include <SFML/Graphics.hpp>

#include "IWindow.hh"

namespace Gui
{
  class	Window : public IWindow
  {
  public:
    Window();
    virtual ~Window();

    IWidget*	addWidget(int, int, int, int);
    void        deleteWidget(IWidget *);
    void        drawAll();
    void        hide(bool);
    void        resize(int, int);
    void        setBackground(const std::string &);
    void	setEventQueue(EventPart::IEventQueue *);
    int		getWidth() const;
    int		getHeight() const;
  protected:
    bool			_hidden;
    std::list<IWidget *>	_list;
    sf::Window			*_win;
    sf::Sprite			_background;
    EventPart::IEventQueue     	*queue;
    int				_width;
    int				_height;
  };
}

#endif
