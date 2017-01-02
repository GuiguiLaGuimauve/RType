#ifndef CHAT_HH
#define CHAT_HH

#include <vector>
#include <string>

#include "IWindow.hh"
#include "IWidget.hh"
#include "IEventQueue.hh"

#define CHAT_WIDTH 400
#define CHAT_NB_LINES 3

#define CHAT_TEXT_COLOR 255,215, 0

void	TextColorFocus(Gui::IWidget *w);
void	TextColorNoFocus(Gui::IWidget *w);
void	TextColorHover(Gui::IWidget *w);
void	TextColorNoHover(Gui::IWidget *w);
void	textEntered(Gui::IWidget *w, const std::string &c);

namespace Gui
{
	class Chat
	{
	public:
		Chat(IWindow *, EventPart::IEventQueue *, int, int);
		virtual ~Chat();

		void		post(const std::string &);

		void		clearAll();
		void		clearLines();
		void		clearInput();
		std::string	getInputText() const;
		std::string getAndClearInput();

		void		move(int, int);
	protected:
		IWindow					*_win;
		EventPart::IEventQueue	*_eventQueue;
		int						_x;
		int						_y;
		std::vector<IWidget *>	_lines;
		IWidget					*_input;
	};
};
#endif