#pragma once
#include "../Label/Label.h"

class Button;

class MouseListener
{
private:
	Control* root;
public:
	MouseListener(Control& panel) :root(&panel) {};
	virtual void mousePressed(Button &b, int x, int y, bool isLeft) = 0;

	Control* get_root() const;
	void set_root(Control* root);
};

class Button:
	public Label
{
private:
		MouseListener* action;
public:
	Button(int width);
	void addListener(MouseListener& listener) { action = &listener; };
	void mousePressed(int x, int y, bool isLeft) override { action->mousePressed(*this, x, y, isLeft); };
};

