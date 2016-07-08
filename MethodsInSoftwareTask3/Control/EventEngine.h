#pragma once
#include "Control.h"
#include "Graphics.h"

class EventEngine{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control& c);
	virtual ~EventEngine();
	static void moveFocusForword(Control& main, Control* focused);
	static void moveFocusBackword(Control& main, Control* focused);
private:
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};