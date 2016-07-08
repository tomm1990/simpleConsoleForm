#pragma once
#include "../Label/Label.h"
#include "../Control/EventEngine.h"
#include <functional>

class Button : public Label{
public:
	Button(const int width) : Label(width, "[X]") { }
	virtual ~Button(){ }
	bool canGetFocus() override { return true; }
	void keyDown(const WORD code, const CHAR) override { if (code == VK_SPACE || code == VK_RETURN) action(c); }
	void addListener(const std::function<void(Control*)> listener, Control* c)  { action = listener; this->c = c; }
	void mousePressed(const int, const int, const bool) override { action(c); }
private:
	std::function<void(Control*)> action;
	Control* c;
};