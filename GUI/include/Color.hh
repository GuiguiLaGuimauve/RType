#ifndef COLOR_HH
#define COLOR_HH

namespace Gui
{
  struct Color
  {
    Color(int r = 0, int g = 0, int b = 0):
      red(r), green(g), blue(b) {};
    int red;
    int green;
    int blue;
  };
}

#endif
