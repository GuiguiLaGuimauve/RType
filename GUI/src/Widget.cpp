#include "Widget.hh"

using namespace Gui;

Widget::Widget(sf::RenderWindow *w, int x, int y, int width, int height, const std::string &text):
  _win(w), _x(x), _y(y), _width(width), _height(height), _text(text),
  _ptrClick(NULL), _ptrFocus(NULL), _ptrHover(NULL), _eventQueue(NULL)
{
  setStyle(_style);
  move(_x, _y);
  resize(_width, _height);
}

Widget::~Widget()
{
}

void                Widget::draw()
{
  // à remplir en fonction du style
  if (_style.form == CIRCLE)
    _win->draw(_circle);
  else if (_style.form == RECTANGLE)
    _win->draw(_rectangle);
  if (_style.image != "")
    _win->draw(_background);
  if (_text != "")
    _win->draw(_sfmlText);
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
  _rectangle.setSize(sf::Vector2f(_width, _height));
  // plus tard il y aura un truc pour redimensionner l'image
  // solution => http://fr.sfml-dev.org/forums/index.php?topic=10739.0
  if (_width != 0)
    _circle.setRadius(_width / 2);
  else
    _circle.setRadius(0);
}

void                Widget::move(int x, int y)
{
  _x = x;
  _y = y;
  _rectangle.move(_x, _y);
  _circle.move(_x, _y);
  _background.move(_x, _y);
}

void                Widget::setText(const std::string &s)
{
  _text = s ;
  _sfmlText.setString(_text);
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
  // set la font du text
  _sfmlText.setColor(sf::Color(s.textColor.red,
			     s.textColor.green,
			     s.textColor.blue));
  // load l'image si != ""
  _circle.setFillColor(sf::Color(s.backgroundColor.red,
				 s.backgroundColor.green,
				 s.backgroundColor.blue));
  _rectangle.setFillColor(sf::Color(s.backgroundColor.red,
				 s.backgroundColor.green,
				 s.backgroundColor.blue));
  // gérer l'opacité
}

Style               Widget::getStyle() const
{
  return (_style);
}

