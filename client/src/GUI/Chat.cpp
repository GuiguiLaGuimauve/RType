#include "Chat.hh"

using namespace Gui;

Chat::Chat(IWindow *w, EventPart::IEventQueue *eq, int x, int y) :
	_win(w), _eventQueue(eq)
{
	// création des lignes
	Style	s;
	s.form = NO_FORM;
	s.textColor = Color(CHAT_TEXT_COLOR);
	s.policeSize = 35;
	for (int i = 0; i < CHAT_NB_LINES; i++)
	{
		auto tmpWidget = _win->addWidget(0, 0, 60, 400);
		tmpWidget->setStyle(s);
		_lines.push_back(tmpWidget);
	}
	// création de l'innput
	Style	inputStyle;
	inputStyle.form = NO_FORM;
	inputStyle.textColor = Color(CHAT_TEXT_COLOR);
	inputStyle.policeSize = 35;
	inputStyle.inputMode = true;
	_input = _win->addWidget(0, 0, 100, 1000);
	_input->setStyle(inputStyle);
	_input->setOnFocus(TextColorFocus);
	_input->setOnLeaveFocus(TextColorNoFocus);
	_input->setOnTextEntered([](IWidget *wd, const std::string &c)
	{
		if (c[0] == '\n' || c[0] == '\r')
			wd->getEventQueue()->push(EventPart::Event(EventPart::Event::CHAT_SEND_MESSAGE));
		else if (wd->getText().length() > 15)
		{
			// do nothing
		}
		else if (c[0] == 127 || c[0] == 8)
		{
			std::string tmp = wd->getText();
			if (tmp.length() > 0)
				tmp.pop_back();
			wd->setText(tmp);
		}
		else if (isprint(c[0]) && wd->getText().size() < 25)
			wd->setText(wd->getText() + c);
	});
	move(x, y);
}

Chat::~Chat()
{

}

void		Chat::post(const std::string &s)
{
	for (unsigned int i = 1; i < _lines.size(); i++)
		_lines[i]->setText(_lines[i - 1]->getText());
	_lines[0]->setText(s);
}

void		Chat::clearAll()
{
	clearInput();
	clearLines();
}

void		Chat::clearLines()
{
	for (auto i : _lines)
		i->setText("");
}

void		Chat::clearInput()
{
	_input->setText("");
}

std::string	Chat::getInputText() const
{
	return (_input->getText());
}

std::string	Chat::getAndClearInput()
{
	std::string tmp = getInputText();
	clearInput();
	return (tmp);
}

void		Chat::move(int x, int y)
{
	for (unsigned int i = 0; i < _lines.size(); i++)
	{
		_lines[i]->move(x, y + i * 70);
	}
	_input->move(x, y + 70 * CHAT_NB_LINES);
}
