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
	Label::draw(graphics, left, top, 0);
	graphics.write(left + width - 2, top ,"+");
	graphics.write(left + width - 2, top + 2 , "-");
	graphics.write(left + 1, top + 1,static_cast<ostringstream*>(&(ostringstream() << number))->str());
	graphics.setBackground();
	graphics.setForeground();
}

void NumericBox::keyDown(WORD code, CHAR chr)
{
	switch (code)
	{
	case VK_UP:
	{
		setValue(getValue() + 1);
		break;
	}
	case VK_DOWN:
	{
		setValue(getValue() - 1);
		break;
	}
	default:
		break;
	}
}

void NumericBox::mousePressed(int x, int y, bool isLeft){
	if (isLeft){
		if(x>=getWidth()-2 && x<+getWidth()){
			if( y >= 0 && y < 1) setValue(getValue()+1);
			else if(y >  1 && y<=  getHeight()-1) setValue(getValue() - 1);	
		}
	}
}

int NumericBox::getValue() const {
	return number;
}

void NumericBox::setValue(const int value){
	if (value >= min && value <= 120) {
		number = value;
	}
}

bool NumericBox::canGetFocus(){
	return true;
}