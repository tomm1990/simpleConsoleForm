#pragma once
#include "../Label/Label.h"

class Button:
	public Label
{
public:
	Button(int width, string val);

	void setBorderDrawer(const BorderDrawer & borderDrawer) override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
	void mousePressed(int x, int y, bool isLeft) override;
};

