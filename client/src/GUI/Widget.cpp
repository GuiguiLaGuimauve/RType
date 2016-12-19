#include "Widget.hh"
#include "SpriteMap.hpp"

using namespace Gui;

Widget::Widget(sf::RenderWindow *w, int x, int y, int width, int height, const std::string &text):
  _win(w), _x(x), _y(y), _width(width), _height(height), _text(text),
  _ptrClick(NULL), _ptrFocus(NULL), _ptrLeaveFocus(NULL),
  _ptrHover(NULL), _ptrLeaveHover(NULL), _ptrText(NULL), _eventQueue(NULL)
{
  _font.loadFromFile("../client/font/PrStart.ttf");
  setStyle(_style);
  move(_x, _y);
  resize(_width, _height);
}

Widget::~Widget()
{
}

void                Widget::draw()
{
  if (timeLimit != -1 && clock.getTimeMilli() > timeLimit)
    return ;
  // à remplir en fonction du style
  if (_style.form == CIRCLE)
    _win->draw(_circle);
  else if (_style.form == RECTANGLE)
    _win->draw(_rectangle);
  if (_style.image != "")
    {
      _win->draw(_background);
    }
  if (_text != "")
    _win->draw(_sfmlText);
}

void                Widget::setEventQueue(EventPart::IEventQueue *eq)
{
  _eventQueue = eq;
}

EventPart::IEventQueue	*Widget::getEventQueue() const
{
  return (_eventQueue);
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
  _sfmlText.setPosition(_x, _y);
  _background.move(_x, _y);
}

void                Widget::setText(const std::string &s)
{
  _text = s;
  if (!_style.password)
	_sfmlText.setString(_text);
  else
    {
      std::string temp;
      for (unsigned int i = 0; i < _text.size(); i++)
	temp += "*";
      _sfmlText.setString(temp);
    }
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

void                Widget::onLeaveFocus()
{
  if (_ptrLeaveFocus)
    _ptrLeaveFocus(this);
}

void                Widget::onHover()
{
  if (_ptrHover)
    _ptrHover(this);
}

void                Widget::onLeaveHover()
{
  if (_ptrLeaveHover)
    _ptrLeaveHover(this);
}

void		    Widget::onTextEntered(const std::string &c)
{
  if (_ptrText)
    _ptrText(this, c);
}

void                Widget::setOnClick(ptrClick ptrFct)
{
  _ptrClick = ptrFct;
}

void                Widget::setOnFocus(ptrFocus ptrFct)
{
  _ptrFocus = ptrFct;
}

void                Widget::setOnLeaveFocus(ptrFocus ptrFct)
{
  _ptrLeaveFocus = ptrFct;
}

void                Widget::setOnHover(ptrFocus ptrFct)
{
  _ptrHover = ptrFct;
}

void                Widget::setOnLeaveHover(ptrFocus ptrFct)
{
  _ptrLeaveHover = ptrFct;
}

void		    Widget::setOnTextEntered(ptrText ptr)
{
  _ptrText = ptr;
}

void                Widget::setStyle(const Style &s)
{
  _style = s;
  _sfmlText.setFont(_font);
  setText(_text);
  _sfmlText.setColor(sf::Color(_style.textColor.red,
			       _style.textColor.green,
			       _style.textColor.blue));
  _sfmlText.setCharacterSize(_style.policeSize);
  _circle.setFillColor(sf::Color(_style.backgroundColor.red,
				 _style.backgroundColor.green,
				 _style.backgroundColor.blue));
  _rectangle.setFillColor(sf::Color(_style.backgroundColor.red,
				 _style.backgroundColor.green,
				 _style.backgroundColor.blue));
  // gérer l'opacité
  // load l'image si != ""
  if (_style.image != "")
    {
      _background = SpriteMap::getSprite(_style.image);
      _background.setPosition(this->getX(), this->getY());
    }
	setText(getText());
}

Style               Widget::getStyle() const
{
  return (_style);
}

void	Widget::showPopup(const std::string &s, int tMilli)
{
  setText(s);
  timeLimit = tMilli;
  clock.reset();
}
