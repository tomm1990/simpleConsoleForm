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
	
	valueListener = new ValueListener(*val);
	bUP->addListener(*valueListener);
	//bDOWN->addListener(*valueListener);
}

NumericBox::~NumericBox()
{
	if (val) delete val;
	if (bUP) delete bUP;
	if (bDOWN) delete bDOWN;
	if (valueListener) delete valueListener;
}

void NumericBox::draw(Graphics& graphics, int left, int top, size_t p){
	Control::draw(graphics, left, top, 0);
	val->draw(graphics, left+1, top+3, p);
	bUP->draw(graphics, left+3 + val->getWidth(), top+1, p);
	bDOWN->draw(graphics, left+3 + val->getWidth(), top+3+bUP->getHeight(), p);
	//graphics.write(left + width - 2, top ,"+");
	//graphics.write(left + width - 2, top + 2 , "-");
	//graphics.write(left + 1, top + 1,static_cast<ostringstream*>(&(ostringstream() << number))->str());
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

//void NumericBox::mousePressed(int x, int y, bool isLeft){
//	//Panel::mousePressed( x , y , isLeft );
//	//if (isLeft)
//	//{
//	//	for (auto it = children.begin(); it != children.end(); ++it)
//	//	{
//	//		int X = x - (*it)->getLeft();
//	//		int Y = y - (*it)->getTop();
//	//		if ( X>=(*it)->getLeft()-1 &&  X<= (*it)->getLeft() - 1 + (*it)->getWidth())
//	//		{
//	//			if ( (Y >= (*it)->getTop()) && (Y <= (*it)->getTop() +  (*it)->getHeight() + 1)) {
//	//				//(*it)->mousePressed(X, Y, isLeft);
//	//				break;
//	//			}
//	//			//else {
//	//			//	(*it)->mousePressed(X, Y, isLeft);
//	//			//}
//	//		}
//	//	}
//
//	//}
//
//	//if (isLeft){
//	//	if(x >= getWidth()-2 && x<+getWidth()){
//	//		if (y >= 0 && y < 1)
//	//		{
//	//			if(number>min && number<max) ++number;
//	//		}
//	//		else
//	//		{
//	//			if (y > 1 && y <= getHeight() - 1)
//	//			{
//	//				if (number > min && number < max) --number;
//	//			}
//	//		}
//	//		setValue(getValue());
//	//	}
//	//}
//}

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