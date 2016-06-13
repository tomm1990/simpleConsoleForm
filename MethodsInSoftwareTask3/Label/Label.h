#pragma once
#include "../Textbox/TextBox.h"

class Label : public TextBox
{
public:
	Label(int width , string value);
	void SetText(string);
	void SetBorder(BorderType border) override;
	void draw(Graphics& graphics, int left, int top, size_t p) override;
};
