#include "TextBox.h"

TextBox::TextBox(int width): Control(width),cursor(0)
{
	height = 1;
}

void TextBox::keyDown(WORD code, CHAR chr)
{

	if (cursor >= 0 && cursor <= width)
	{
	if (chr >= VK_SPACE && chr<='~' && value.size()<width-1)
	{
		string str = string(1,chr);
		if(width-value.size()!=0)
		{
			value.replace(cursor++, 1, str);
		}

	}
	else
	{
		switch (code)
		{
		case VK_BACK:
		{
			if(cursor<=value.size())
			{
				value.erase(cursor, 1);
			if (cursor > 0)
				--cursor;
			}
			break;
		}
		case VK_RIGHT:
		{
			if(cursor<value.size())
				cursor++;
			break;
		}
		case VK_LEFT:
		{
			if(cursor>0)
			cursor--;
			break;
		}
		
		
		}

	}
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	if (x <= value.size())
	{
		cursor = x;
	}
	else
		cursor = value.size();
}

void TextBox::SetBorder(BorderType border)
{
}

void TextBox::getAllControls(vector<Control*>* vector)
{
}

bool TextBox::canGetFocus()
{
	return true;
}

void TextBox::draw(Graphics& graphics, int left, int top, size_t p)
{
	Control::draw(graphics, left, top,0);
	graphics.write(left, top, value);
	for(auto i=width-value.size();i>0;--i)
	{
		graphics.write(" ");
	}
	graphics.moveTo(left+cursor, top);
	graphics.setBackground();
	graphics.setForeground();
}

string TextBox::get_value() const
{
	return value;
}

void TextBox::set_value(const string& value)
{
	if (value.size() < width)
	{
		this->value = value;
		return;
	}
	throw exception("overflow");
}



