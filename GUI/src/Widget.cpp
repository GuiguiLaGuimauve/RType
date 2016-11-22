#include "Widget.hh"

using namespace Gui;

Widget::Widget(sf::Window *w, int x, int y, int width, int height, const std::string &text):
  _win(w), _x(x), _y(y), _width(width), _height(height), _text(text),
  _ptrClick(NULL), _ptrFocus(NULL), _ptrHover(NULL), _eventQueue(NULL)
{
  /*Ici il faudra surement mettre un style de base*/
}

Widget::~Widget()
{
}

void                Widget::draw()
{
  // à remplir en fonction du style
}

void                Widget::setEventQueue(EventPart::IEventQueue *eq)
{
  _eventQueue = eq;
}

bool                Widget::collision(int x, int y) const
{
  if (x > _x && x < _x + _width &&
      y > _y && y < _y + _height)
    return (true);
  return (false);
}

void                Widget::resize(int w, int h)
{
  _width = w;
  _height = h;
}

void                Widget::move(int x, int y)
{
  _x = x;
  _y = y;
}

void                Widget::setText(const std::string &s)
{
  _text = s ;
}

std::string         Widget::getText() const
{
  return (_text);
}

int                 Widget::getX() const
{
  return (_x);
}

int                 Widget::getY() const
{
  return (_y);
}

int                 Widget::getWidth() const
{
  return (_width);
}

int                 Widget::getHeight() const
{
  return (_height);
}

void                Widget::onClick(CLICK c)
{
  if (_ptrClick)
    _ptrClick(this, c);
}

void                Widget::onFocus()
{
  if (_ptrFocus)
    _ptrFocus(this);
}

void                Widget::onHover()
{
  if (_ptrHover)
    _ptrHover(this);
}

void                Widget::setOnClick(ptrClick ptrFct)
{
  _ptrClick = ptrFct;
}

void                Widget::setOnFocus(ptrFocus ptrFct)
{
  _ptrFocus = ptrFct;
}

void                Widget::setOnHover(ptrFocus ptrFct)
{
  _ptrHover = ptrFct;
}

void                Widget::setStyle(const Style &s)
{
  _style = s;
}

Style               Widget::getStyle() const
{
  return (_style);
}

