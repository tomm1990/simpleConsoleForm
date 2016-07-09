#include "EventEngine.h"

// Singleton event engine object
EventEngine* EventEngine::engine;

EventEngine::EventEngine(DWORD input, DWORD output):_graphics(output),_console(GetStdHandle(input)){
	isRun = true;
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run( Control & c )
{
	for (bool redraw = true; isRun;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);	
			for (size_t p = 0; p < 3; ++p) 
			{
				if(c.isVisible())
				{
					c.draw(_graphics, 0, 0, p); 
				}
			}
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
				if (f != nullptr && record.Event.KeyEvent.bKeyDown) 
				{
					auto code = record.Event.KeyEvent.wVirtualKeyCode;
					auto chr = record.Event.KeyEvent.uChar.AsciiChar;
					if (code == VK_TAB)
						moveFocusForword(c, f);
					else
						c.keyDown(code, chr);
					redraw = true; 
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
					if (isInside(x, y, c.getLeft(), c.getTop(), c.getWidth(), c.getHeight())) 
					{
						c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
						redraw = true; 
					}
				}
				break;
			}
		default:
			break;
		}
	}
}

void EventEngine::stop()
{
	isRun = false;
}

void EventEngine::moveFocusForword(Control& main, Control* focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
		{
			it = controls.begin();
		}
	while (!(*it)->canGetFocus() || !(*it)->isVisible() 
		|| (*it)->get_layer()!=focused->get_layer());
	Control::setFocus(**it);
}

void EventEngine::moveFocusBackword(Control& main, Control* focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls);
	auto it = find(controls.rbegin(), controls.rend(), focused);
	do
		if (++it == controls.rend())
		{
			it = controls.rbegin();
		}
	while (!(*it)->canGetFocus() || !(*it)->isVisible()
		|| (*it)->get_layer() != focused->get_layer());
	Control::setFocus(**it);
}

EventEngine& EventEngine::getEngine(){
	if (!engine) engine = new EventEngine;
	return *engine;
}