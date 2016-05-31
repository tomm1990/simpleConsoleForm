#include "Control.h"


// ReSharper disable once CppMemberFunctionMayBeStatic
void Control::getCursorXY(int& x, int& y) const
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;
	}
}

void Control::listen()
{
	DWORD cNumRead, fdwMode, i;
	DWORD fdwSaveOldMode;
	INPUT_RECORD irInBuf[128];

	// Get the standard input handle. 
	if (hIn == INVALID_HANDLE_VALUE)
		cout << "error";

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hIn, &fdwSaveOldMode))
		cout << "error";

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hIn, fdwMode))
		cout << "error";

	for (;;)
	{
		// Wait for the events. 
		if (!ReadConsoleInput(hIn, irInBuf, 128, &cNumRead))
			cout << "error";
		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;
			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;
			}
		}
	}
}

SHORT Control::getLeft()
{
	return 1;
}

SHORT Control::getTop()
{
	return 1;
}

Control::~Control()
{
}

Control::Control(int width) : hOut(GetStdHandle(STD_OUTPUT_HANDLE)), hIn(GetStdHandle(STD_INPUT_HANDLE)), width(width), position({0,0})
{
}
