#include "GUI.hh"
#include "Assets.hh"

using namespace Gui;

void	TextColorFocus(IWidget *w)
{
	Style	s = w->getStyle();
	s.textColor = Color(TEXT_HOVER_COLOR_R, TEXT_HOVER_COLOR_G, TEXT_HOVER_COLOR_B);
	w->setStyle(s);
}

void	TextColorNoFocus(IWidget *w)
{
	Style	s = w->getStyle();
	s.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
	w->setStyle(s);
}

void	TextColorHover(IWidget *w)
{
	Style	s = w->getStyle();
	s.textColor = Color(TEXT_HOVER_COLOR_R, TEXT_HOVER_COLOR_G, TEXT_HOVER_COLOR_B);
	w->setStyle(s);
}

void	TextColorNoHover(IWidget *w)
{
	Style	s = w->getStyle();
	s.textColor = Color(TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
	w->setStyle(s);
}

void	textEntered(IWidget *w, const std::string &c)
{
  if (c[0] == '|')
    return;
  if (c[0] == 127 || c[0] == 8)
    {
      std::string tmp = w->getText();
      if (tmp.length() > 0)
	tmp.pop_back();
      w->setText(tmp);
    }
  else if (isprint(c[0]) && w->getText().size() < 22)
    w->setText(w->getText() + c);
}
