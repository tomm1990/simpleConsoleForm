#include "EventEngine.h"

EventEngine::EventEngine(DWORD input, DWORD output)
	: _graphics(output), _console(GetStdHandle(input))
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run( Control& c )
{
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t p = 0; p < 5; ++p)
				c.draw( _graphics, (int)c.getLeft() , (int)c.getLeft(), p); // changed to control left-top corner
			redraw = false;
		}

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
			{
				auto f = Control::getFocus();
				if (f == nullptr && record.Event.KeyEvent.bKeyDown) // changed from (f!=nullptr ...)
				{
					auto code = record.Event.KeyEvent.wVirtualKeyCode;
					auto chr = record.Event.KeyEvent.uChar.AsciiChar;
					if (code == VK_TAB)
						moveFocus(c, f);
					else
						c.keyDown(code, chr);
					redraw = false; // changed to false
				}
				break;
			}
		case MOUSE_EVENT:
			{
				auto button = record.Event.MouseEvent.dwButtonState;
				auto coord = record.Event.MouseEvent.dwMousePosition;
				auto x = coord.X - c.getLeft();
				auto y = coord.Y - c.getTop();
				if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
				{
					c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
					redraw = false; // changed to false
				}
				break;
			}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control& main, Control* focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->canGetFocus());
	Control::setFocus(**it);
}
