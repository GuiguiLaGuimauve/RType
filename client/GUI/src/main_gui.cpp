#include "GUI.hh"

int main()
{
  EventPart::EventQueue eq;
  Gui::GUI		gui;
  gui.setEventQueue(&eq);
  while (1)
    {
      gui.callback();
      while (!eq.empty())
	{
	  auto e = eq.pop();
	  if (e.type == EventPart::Event::QUIT)
	    return (1);
	}
    }
  return (0);
}
