#include "Label.h"

Label::Label(const int width ,const string value): TextBox(width) { SetText(value); }

Label::Label(const int width): TextBox(width) { }

void Label::SetText(const string value) { TextBox::setValue(value); }

void Label::draw(Graphics& graphics, const int left, const int top, const size_t p){
	TextBox::draw(graphics, left, top, p);
	graphics.setCursorVisibility(false);
}

void Label::set_cursor( Graphics& graphics, const int left, const int top) { graphics.setCursorVisibility(false); }