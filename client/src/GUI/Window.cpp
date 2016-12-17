#include "Window.hh"

using namespace Gui;

Window::Window(int w, int h, const std::string &s):
  _width(w), _height(h), _title(s)
{
  _hidden = false;
  _queue = NULL;
  _win = new sf::RenderWindow(sf::VideoMode(_width, _height), _title,
			      sf::Style::Close | sf::Style::Titlebar);
  _win->setTitle("RType");
}

Window::~Window()
{
  delete _win;
  for (auto i = _list.begin(); i != _list.end(); i++)
    if (*i)
      delete (*i);
  _list.clear();
}

IWidget*    Window::addWidget(int x, int y, int w, int h)
{
  IWidget *widget = new Widget(_win, x, y, w, h);
  widget->setEventQueue(_queue);
  _list.push_back(widget);
  return (widget);
}


void        Window::deleteWidget(IWidget *w)
{
  if (!w)
    return ;
  auto i = std::find(_list.begin(), _list.end(), w);
  if (i != _list.end())
    {
      if (*i)
	delete (*i);
      _list.erase(i);
    }
}

IWidget*    Window::isThereWidget(int x, int y)
{
  for (auto i = _list.begin(); i != _list.end(); i++)
    if (*i && (*i)->collision(x, y))
      return (*i);
  return (NULL);
}

void        Window::drawAll()
{
  _win->clear();
  if (_hidden)
    return ;
  _win->draw(_background);
  for (auto i = _list.begin(); i != _list.end(); i++)
    (*i)->draw();
  _win->display();
}


void        Window::hide(bool b)
{
  _hidden = b;
}


void        Window::resize(int w, int h)
{
  _width = w;
  _height = h;
  _win->setSize(sf::Vector2u(_height, _width));
}


void        Window::setBackground(const std::string &s)
{
  if (_loadBackground.loadFromFile(s))
    {
      //_loadBackground.setRepeated(true);
      _background.setTexture(_loadBackground);
      //_background.setTextureRect({ 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT });
    }
}


void        Window::setEventQueue(EventPart::IEventQueue *eq)
{
  _queue = eq;
}


int         Window::getWidth() const
{
  return (_width);
}

int         Window::getHeight() const
{
  return (_height);
}

void         Window::setTitle(const std::string &s)
{
  _title = s;
  _win->setTitle(_title);
}

std::string         Window::getTitle() const
{
  return (_title);
}

bool		Window::isOpen()
{
    return (_win->isOpen());
}

sf::RenderWindow	*Window::getSfmlWinPtr()
{
  return (_win);
}
