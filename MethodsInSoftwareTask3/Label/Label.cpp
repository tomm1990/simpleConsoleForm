#include "Label.h"

Label::Label(int width , string value): TextBox(width)
{
	SetText(value);
}


void Label::SetBorder(BorderType border)
{
	TextBox::SetBorder(border);
}

void Label::draw(Graphics& graphics, int left, int top, size_t p){
	//SetConsoleCursorPosition(hOut, position);
	TextBox::draw(graphics, left, top, p);
}


void Label::SetText(string value) {
	TextBox::set_value(value);
}