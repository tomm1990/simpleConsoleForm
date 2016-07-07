#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
public:
	Label(int width , string value);
	Label(int width);
	void SetText(string);
	virtual void draw(Graphics& graphics, int left, int top, size_t p) override;
	bool canGetFocus() override { return false; }
	virtual void keyDown(WORD code, CHAR chr) override{};
	virtual void mousePressed(int x, int y, bool isLeft) override{};

	virtual void set_cursor(const Graphics& graphics, int left, int top) override;
};
