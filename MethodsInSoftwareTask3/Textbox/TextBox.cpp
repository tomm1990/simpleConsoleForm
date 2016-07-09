#include "TextBox.h"

TextBox::TextBox(const int width) : Control(width), cursor(0) { }

void TextBox::keyDown(const WORD code, const CHAR chr) {
	if (cursor >= 0 && cursor <= getWidth()) {
		if (chr >= VK_SPACE && chr <= '~' && value.size() < getWidth() - 1) {
			string str = string(1, chr);
			if (getWidth() - value.size() != 0 && cursor >= value.size()) value.replace(cursor++, 1, str);
			else if (getWidth() - value.size() != 0 && cursor < value.size()) value.insert(cursor++, str);
		}
		else {
			switch (code) {
			case VK_BACK:
			{
				if (cursor <= value.size() && cursor != 0) {
					value.erase(cursor - 1, 1);
					if (cursor > 0) --cursor;
				}
				break;
			}
			case VK_RIGHT: { if (cursor < value.size())	cursor++; break; }
			case VK_LEFT: { if (cursor > 0) cursor--; break; }
			case VK_HOME: { cursor = 0; break; }
			case VK_END: { cursor = value.size(); break; }
			case VK_DELETE: { if (cursor <= value.size()) { value.erase(cursor, 1); break; } } }
		}
	}
}

void TextBox::mousePressed(const int x, const int y, const bool isLeft){
	if (x <= value.size()) cursor = x;
	else cursor = value.size();
}

void TextBox::draw(Graphics& graphics, const int left, const int top, const size_t p){
	Control::draw(graphics, left, top , p);
	graphics.write(left+this->getLeft(), top+this->getTop(),value);
	for(auto i = getWidth() -value.size() ; i > 0 ; --i )	graphics.write(" ");
	graphics.setBackground();
	graphics.setForeground();	
}

string TextBox::getValue() const { return value; }

void TextBox::setValue(const string& value){
	if (value.size() <= getWidth()) this->value = value;
	else this->value.insert(0, value, 0 , getWidth() -1);
}

void TextBox::set_cursor(Graphics& graphics, const int left, const int top){
	graphics.moveTo( left + this->getLeft() + cursor, top + this->getTop() );
	graphics.setCursorVisibility(true);
}