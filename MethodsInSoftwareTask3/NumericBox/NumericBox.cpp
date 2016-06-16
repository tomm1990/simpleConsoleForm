#include "NumericBox.h"
#include <sstream>

NumericBox::NumericBox(int width, int min, int max): Label(width , "") {
	this->min = min;
	this->max = max;
	this->height = 3;
}

NumericBox::~NumericBox()
{
}

void NumericBox::draw(Graphics& graphics, int left, int top, size_t p){
	Control::draw(graphics, left, top, 0);
	graphics.write(left + width - 2, top ,"+");
	graphics.write(left + width - 2, top + 2 , "-");
	graphics.write(left + 1, top + 1,static_cast<ostringstream*>(&(ostringstream() << number))->str());
	graphics.setBackground();
	graphics.setForeground();
	graphics.moveTo(left+1, top+1);

}

void NumericBox::keyDown(WORD code, CHAR chr)
{
	switch (code)
	{
	case VK_UP:
	{
		++number;
		break;
	}
	case VK_DOWN:
	{
		--number;
		break;
	}
	default:
		break;
	}
}

void NumericBox::mousePressed(int x, int y, bool isLeft){
	if (isLeft){
		if(x>=getWidth()-2 && x<+getWidth()){
			if (y >= 0 && y < 1)
			{
				++number;
			}
			else
			{
				if (y > 1 && y <= getHeight() - 1)
				{
					--number;
				}
			}
			setValue(getValue());
		}
	}
}

string NumericBox::getValue() const {
	return to_string(number);
}

void NumericBox::setValue(const string& value){
	auto val = stoi(value);
	if (val >= min && val <= 120) {
		number = val;
	}
}

bool NumericBox::canGetFocus(){
	return true;
}