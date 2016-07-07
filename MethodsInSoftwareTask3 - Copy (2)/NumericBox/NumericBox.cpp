#include "NumericBox.h"
#include <sstream>

int checkWidth(int width){
	return width < 11 ?  11 :  width;
}

NumericBox::NumericBox(int width, int min, int max) : Panel(6,checkWidth(width)) {
	width = checkWidth(width);
	this->min = min;
	this->max = max;
	val = new Label(width / 3, static_cast<ostringstream*>(&(ostringstream() << number))->str());
	val->setBorder(BorderType::Single);
	bUP = new Button(width / 3);
	bUP->setBorder(BorderType::Single);
	bUP->SetText(" +");
	bDOWN = new Button(width / 3);
	bDOWN->setBorder(BorderType::Single);
	bDOWN->SetText(" -");
	addControl(*val, 1+getLeft(), getTop()+getHeight()/3);
	addControl(*bUP, getLeft()+val->getWidth()+4, getTop()+1);
	addControl(*bDOWN, getLeft() + val->getWidth()+4, getTop()+getHeight()-2);
	
	auto upEvenet = [&](Control *c){
	if(number < this->max)
		{
			++number;
			setValue((number));
		}
	};
	bUP->addListener(upEvenet, bUP);

	auto downEvent = [&](Control *c)
	{
		if (number > this->min) {
			--number;
			setValue((number));
		}
	};
	bDOWN->addListener(downEvent, bDOWN);
}

NumericBox::~NumericBox(){
	if (val) delete val;
	if (bUP) delete bUP;
	if (bDOWN) delete bDOWN;
}

string NumericBox::getValue() const {
	return to_string(number);
}

void NumericBox::setValue(int val){
	if (val >= min && val <= max) {
		number = val;
		this->val->SetText(to_string(number));
	}
}



