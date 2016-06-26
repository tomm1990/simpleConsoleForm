#include "TextBox.h"

TextBox::TextBox(int width) : Control(width),cursor(0){
	height = 1;
}

void TextBox::keyDown(WORD code, CHAR chr) {
	if (cursor >= 0 && cursor <= width){
		if (chr >= VK_SPACE && chr<='~' && value.size()<width-1){
			string str = string(1,chr);
			if( width-value.size()!=0 && cursor>=value.size()){
				value.replace(cursor++, 1, str);
			}
			else if (width - value.size() != 0 && cursor < value.size()) {
				value.insert(cursor++, str);
			}
	} else {
		switch (code){
			case VK_BACK:
			{
				if( cursor <= value.size() && cursor  != 0 ) {
					value.erase( cursor - 1 , 1 );
					if (cursor > 0) --cursor;
				}
				break;
			}
			case VK_RIGHT:
			{
				if( cursor < value.size() )
					cursor++;
				break;
			}
			case VK_LEFT:
			{
				if(cursor > 0)
				cursor--;
				break;
			}	
		}
	}
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft){
	if (x <= value.size()) cursor = x;
	else cursor = value.size();
}

void TextBox::getAllControls(vector<Control*>* vector)
{
}

bool TextBox::canGetFocus(){
	return true;
}

void TextBox::draw(Graphics& graphics, int left, int top, size_t p){
	Control::draw(graphics, left, top,0);
	graphics.write(left, top,value);
	for(auto i=width-value.size();i>0;--i)	graphics.write(" ");
	graphics.moveTo(left+cursor, top);
	graphics.setBackground();
	graphics.setForeground();
}

string TextBox::getValue() const{
	return value;
}

void TextBox::setValue(const string& value){
	if (value.size() <= width){
		this->value = value;
	} else {
		this->value.insert(0, value, 0 , width-1);
	}
}