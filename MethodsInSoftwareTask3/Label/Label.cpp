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
}

void Label::draw(Graphics& graphics, int i, int i1, size_t size_t){
	SetConsoleCursorPosition(hOut, position);
	if (position.X < 0 || position.Y < 0) return;
	SetSavedColors( GetConsoleTextAttribute(hOut));
	graphics.setForeground(forColor);
	graphics.setBackground(backcolor);
	cout << _value << endl;
	setConsole_CursorPos_TextAttr(hOut, { (SHORT)position.X, (SHORT)(position.Y + width) }, getSavedColors());
}

Label::~Label()
{
}


void Label::SetText(string value) {
	_value = value;
}