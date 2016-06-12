#include "Label.h"

Label::Label(int width , string value): TextBox(width)
{
	SetText(value);
}

void Label::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void Label::KeyEventProc(KEY_EVENT_RECORD)
{
}


void Label::setForeground(Color color)
{
	forColor = color;
}

void Label::setBackground(Color color)
{
	backcolor = color;
}

void Label::SetBorder(BorderType border)
{
	TextBox::SetBorder(border);
}

void Label::draw(Graphics& graphics, int i, int i1, size_t size_t){
	//SetConsoleCursorPosition(hOut, position);
	TextBox::draw(graphics, i, i1, size_t);
	if (i < 0 || i1 < 0) return;
	//SetSavedColors( GetConsoleTextAttribute(hOut));
	position.X = i;
	position.Y = i1;
	graphics.setForeground(forColor);
	graphics.setBackground(backcolor);
	graphics.write(i+1, i1+1,_value);
	//cout << _value << endl;
	//setConsole_CursorPos_TextAttr(hOut, { (SHORT)position.X, (SHORT)(position.Y + width) }, getSavedColors());
}

Label::~Label()
{
}


void Label::SetText(string value) {
	_value = value;
}