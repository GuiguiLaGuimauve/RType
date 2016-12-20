#ifndef STYLE_HH
#define STYLE_HH

#include <string>
#include <map>
#include <vector>

#include "Color.hh"
#include "Police.hh"
#include "Form.hh"

namespace Gui
{
  struct Style
  {
    POLICE	policeType = CALIBRI;
    int		policeSize = 12;
    Color	textColor;
    bool	boldText = false;
    bool	italicText = false;
    bool	underlineText = false;
    std::string	image = "";
    FORM	form = NO_FORM;
    Color	backgroundColor;
    int		opacity = 100;
	bool	password = false;
	// animations
	int		frequency = -1;
	bool	move_animation = false;
	std::map<std::string, std::vector<std::string> > anims; // string == NORMAL || RIGHT || LEFT || TOP || BOTTOM
  };
}

#endif
