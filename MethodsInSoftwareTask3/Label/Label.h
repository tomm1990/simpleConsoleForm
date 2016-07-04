#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
public:
	Label(int width , string value);
	void SetText(string);
	bool canGetFocus() override { return false; }
	virtual void draw(Graphics& graphics, int left, int top, size_t p) override;
	virtual void keyDown(WORD code, CHAR chr) override{};
	virtual void mousePressed(int x, int y, bool isLeft) override{};
};
