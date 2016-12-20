#include "GUI.hh"

using namespace Gui;

void	TextColorFocus(IWidget *w)
{
  Style	s1 = w->getStyle();
  s1.textColor.blue += 100;
  s1.textColor.green += 100;
  w->setStyle(s1);
}

void	TextColorNoFocus(IWidget *w)
{
  Style	s1 = w->getStyle();
  s1.textColor.blue -= 100;
  s1.textColor.green -= 100;
  w->setStyle(s1);
}

void	textEntered(IWidget *w, const std::string &c)
{
  if (c[0] == 127 || c[0] == 8)
    {
      std::string tmp = w->getText();
      if (tmp.length() > 0)
	tmp.pop_back();
      w->setText(tmp);
    }
  else if (isprint(c[0]) && w->getText().size() < 25)
    w->setText(w->getText() + c);
}
