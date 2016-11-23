#include "Window.hh"
#include "SoundManager.hh"

#include "GUI.hh"

int main()
{
  Gui::IWindow *w = new Gui::Window();

  while (w->isOpen())
    {
      w->drawAll();
      static_cast<Gui::Window *> (w)->getSfmlWinPtr();
    }
  return (0);
}
