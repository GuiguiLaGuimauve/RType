#include "Window.hh"

using namespace Gui;

Window::Window(int w, int h, const std::string &s):
  _width(w), _height(h), _title(s)
{
  _hidden = false;
  _queue = NULL;
  sf::VideoMode	vm = sf::VideoMode::getDesktopMode();
  _width = vm.width;
  _height = vm.height;
  _win = new sf::RenderWindow(sf::VideoMode(_width, _height), _title,
			      sf::Style::None);
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
  _win->draw(_background2);
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
  _win->setSize(sf::Vector2u(_width, _height));
}


void        Window::setBackground(const std::string &s)
{
  if (_loadBackground.loadFromFile(s))
    {
      //_loadBackground.setRepeated(true);
      _loadBackground.setRepeated(false);
      _background.setTexture(_loadBackground);
      _background.setTextureRect({ 0, 0, _width, _height });
      _background2.setTexture(_loadBackground);
      _background2.setTextureRect({ 0, 0, _width, _height });
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

void	Window::deleteAllWidgets()
{
  for (auto elem : _list)
    delete elem;
  _list.clear();
}

sf::Sprite	Window::getBackground() const
{
  return (_background);
}

sf::Sprite	Window::getBackground2() const
{
  return (_background2);
}

void	Window::setBg1Pos(float x, float y)
{
  _background.setPosition(x, y);
}

void	Window::setBg2Pos(float x, float y)
{
  _background2.setPosition(x, y);
}
