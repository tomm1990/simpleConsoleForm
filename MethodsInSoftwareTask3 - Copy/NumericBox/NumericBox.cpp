#include "NumericBox.h"
#include <sstream>

NumericBox::NumericBox(int width, int min, int max): Panel(6,width){
	this->min = min;
	this->max = max;
	val = new Label(width / 3, static_cast<ostringstream*>(&(ostringstream() << number))->str());
	val->setBorderDrawer(BorderType::Single);
	bUP = new Button(width / 3);
	bUP->setBorderDrawer(BorderType::Single);
	bUP->SetText(" +");
	bDOWN = new Button(width / 3);
	bDOWN->setBorderDrawer(BorderType::Single);
	bDOWN->SetText(" -");
	addControl(*val, getLeft(), getTop());
	addControl(*bUP, getLeft()+val->getWidth(), getTop());
	//addControl(*bDOWN, getLeft() + val->getWidth()+1, getTop()+bUP->getHeight()+1);
	
	//valueListener = new ValueListener(*val);
	//bUP->addListener(*valueListener);
	//bDOWN->addListener(*valueListener);
}

NumericBox::~NumericBox()
{
	if (val) delete val;
	if (bUP) delete bUP;
	if (bDOWN) delete bDOWN;
	//if (valueListener) delete valueListener;
}
string NumericBox::getValue() const {
	return to_string(number);
}

void NumericBox::setValue(const string& value){
	auto val = stoi(value);
	if (val >= min && val <= max) {
		number = val;
	}
}

bool NumericBox::canGetFocus(){
	return true;
}