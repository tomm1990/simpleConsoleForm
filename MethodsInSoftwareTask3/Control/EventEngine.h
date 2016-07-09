#pragma once
#include "Control.h"
#include "Graphics.h"

// main engine
// implemented with Singleton design pattern
class EventEngine{
public:
	void run(Control& c);
	void stop();
	static void moveFocusForword(Control& main, Control* focused);
	static void moveFocusBackword(Control& main, Control* focused);
	static EventEngine& getEngine();
private:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	static EventEngine* engine;
	bool isRun;
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};