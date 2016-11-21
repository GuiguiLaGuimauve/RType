#ifndef STYLE_HH
#define STYLE_HH

#include <string>

#include "Color.hh"
#include "Police.hh"
#include "Form.hh"

namespace Gui
{
  struct Style
  {
    POLICE	policeType;
    int		policeSize;
    Color	textColor;
    bool	boldText;
    bool	italicText;
    bool	underlineText;
    std::string	image;
    FORM	form;
    Color	backgroundColor;
    int		opacity;
  };
}

#endif
