#include "Window.hh"
#include "KeyboardManager.hh"
#include "SoundManager.hh"

#include "GUI.hh"

int main()
{
  Gui::IWindow *w = new Gui::Window();

  while (w->isOpen())
    {
      w->drawAll();
    }
  return (0);
}
