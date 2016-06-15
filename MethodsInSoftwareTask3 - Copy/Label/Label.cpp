#include "Label.h"

Label::Label(int width , string value): TextBox(width)
{
	SetText(value);
}




void Label::draw(Graphics& graphics, int left, int top, size_t p){
	TextBox::draw(graphics, left, top, p);

}


void Label::SetText(string value) {
	TextBox::setValue(value);
}