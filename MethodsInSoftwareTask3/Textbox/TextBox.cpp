#include "TextBox.h"

TextBox::TextBox(int width): Control(width)
{
	_widthTextBox = width;

}

TextBox::~TextBox()
{
}

void TextBox::MouseEventProc(MOUSE_EVENT_RECORD)
{
}

void TextBox::KeyEventProc(KEY_EVENT_RECORD)
{
}

void TextBox::Show()
{
}

void TextBox::Hide()
{
}

void TextBox::SetForeground(ForegroundColor color)
{
}

void TextBox::SetBackground(BackgroundColor color)
{
}

void TextBox::SetBorder(BorderType border)
{

}

void TextBox::SetText(string value)
{
	cout << "Left is : " << getLeft();
	cout << "Top is : " << getTop();
	SetConsoleCursorPosition(hOut, { getLeft() , getTop() });
	_value = value;
	cout << value;
}

string TextBox::getValuse()
{
	return "";
}

void TextBox::draw(const Graphics& graphics, int i, int i1, size_t size_t)
{
}

void TextBox::keyDown(WORD code, CHAR chr)
{
}

void TextBox::mousePressed(int i, int y, bool b)
{
}

void TextBox::getAllControls(vector<Control*>* vector)
{
}

bool TextBox::canGetFocus()
{
	return true;
}
