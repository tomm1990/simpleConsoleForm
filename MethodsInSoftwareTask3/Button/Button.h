#pragma once
#include "../Label/Label.h"
#include <functional>

class Button : public Label{
public:
	Button(const int);
	bool canGetFocus() override { return true; }
	void keyDown(const WORD, const CHAR) override;
	void addListener(const std::function<void(Control*)> listener, Control* c)  { action = listener; this->c = c; }
	void mousePressed(const int, const int, const bool) override { action(c); }
private:
	std::function<void(Control*)> action;
	Control* c;
};