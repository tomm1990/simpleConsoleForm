#include "Control.h"


// ReSharper disable once CppMemberFunctionMayBeStatic
void Control::getCursorXY(SHORT& x, SHORT& y) const
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;
	}
}

void Control::setConsole_CursorPos_TextAttr(const HANDLE handle, const COORD coord, const int color)
{
	SetConsoleCursorPosition(handle, { coord.X, coord.Y });
	SetConsoleTextAttribute(handle, color);

}
/*
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
*/
SHORT Control::getLeft()
{
	return position.X;
}

SHORT Control::getTop()
{
	return position.Y;
}

void Control::setFocus(const Control& it)
{
}

Control* Control::getFocus()
{
	return nullptr;
}

Control::~Control()
{
}

Control::Control(int width) : hOut(GetStdHandle(STD_OUTPUT_HANDLE)), hIn(GetStdHandle(STD_INPUT_HANDLE)), width(width), position({0,0}) , graphics()
{

}

void Control::Show()
{
	isVisibile = true;
}

void Control::Hide()
{
	isVisibile = false;
}
