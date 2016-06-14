#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
public:
	Label(int width , string value);
	void SetText(string);
	virtual void SetBorder(BorderType border) override;
	virtual void draw(Graphics& graphics, int left, int top, size_t p) override;
	virtual void keyDown(WORD code, CHAR chr) override{};
	virtual void mousePressed(int x, int y, bool isLeft) override{};
};
