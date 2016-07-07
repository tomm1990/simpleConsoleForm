#pragma once
#include "../Label/Label.h"
#include <functional>

class Button:
	public Label
{
private:
	std::function<void(Control*)> action;
	Control* c;
public:
	Button(int width);
	bool canGetFocus() override { return true; }

	void keyDown(WORD code, CHAR chr) override;;

	void addListener(std::function<void(Control*)> listener, Control* c) { action = listener; this->c = c; };
	void mousePressed(int x, int y, bool isLeft) override { action(c); };
};

