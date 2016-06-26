#pragma once
#include "../Label/Label.h"
#include <functional>

class Button:
	public Label
{
private:
	std::function<void()> action;
public:
	Button(int width);
	void addListener(std::function<void()> listener) { action = listener; };
	void mousePressed(int x, int y, bool isLeft) override { action(); };
};

