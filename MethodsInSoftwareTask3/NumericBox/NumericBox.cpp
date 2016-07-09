#include "NumericBox.h"
#include <sstream>

int checkWidth(const int width) { return width < 11 ?  11 :  width; }

NumericBox::NumericBox(int width, const int min, const int max) : Panel( 3 , checkWidth(width) ) {
	width = checkWidth(width);
	this->min = min;
	this->max = max;
	val = new Label(std::to_string(max).size(), to_string(number));
	val->setBorder(BorderType::Single);
	bUP = new Button(1);
	bUP->setBorder(BorderType::Single);
	bUP->SetText("+");
	bDOWN = new Button(1);
	bDOWN->setBorder(BorderType::Single);
	bDOWN->SetText("-");
	addControl(*val, getLeft()+1, getTop()+1);
	addControl(*bUP, width-(bDOWN->getWidth()+bUP->getWidth()+3), getTop()+1);
	addControl(*bDOWN, width-2, getTop()+1);
	// event listener to plus button
	auto upEvenet = [&](Control *c)	{
		if (number < this->max) {
			++number;
			setValue(number);
		}
	};
	bUP->addListener(upEvenet, bUP);
	// event listener to minus button
	auto downEvent = [&](Control *c){
		if (number > this->min) {
			--number;
			setValue(number);
		}
	};
	bDOWN->addListener(downEvent, bDOWN);
}

NumericBox::~NumericBox(){
	for (int i = 0; i < getChildrens().size(); i++)
		if (getChildrens()[i]) delete getChildrens()[i];
}

void NumericBox::setValue(const int val){
	if (val >= min && val <= max) {
		number = val;
		this->val->SetText(to_string(number));
	}
}