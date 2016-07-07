#include "NumericBox.h"
#include <sstream>

int checkWidth(int width){
	return width < 11 ?  11 :  width;
}

NumericBox::NumericBox(int width, int min, int max) : Panel(3,checkWidth(width)) {
	width = checkWidth(width);
	this->min = min;
	this->max = max;
	val = new Label(std::to_string(max).size(), static_cast<ostringstream*>(&(ostringstream() << number))->str());
	val->setBorder(BorderType::Single);
	bUP = new Button(1);
	bUP->setBorder(BorderType::Single);
	bUP->SetText("+");
	bDOWN = new Button(1);
	bDOWN->setBorder(BorderType::Single);
	bDOWN->SetText("-");
	addControl(*val, left+1, top+1);
	addControl(*bUP, width-5, top+1);
	addControl(*bDOWN, width-2, top+1);
	
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



